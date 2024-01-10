#ifndef COMPONENT_ARRAY_H
#define COMPONENT_ARRAY_H

#include "IComponentArray.h"
#include <array>
#include <unordered_map>
#include <cassert>

template<typename ComponentType>
class ComponentArray : public IComponentArray {

    public:

        void insertData(Entity entity, ComponentType component) {
            assert(m_entityToIndexMap.find(entity) == m_entityToIndexMap.end() && "Component added to same entity more than once.");

            // Put new entry at end and update the maps
            size_t newIndex = mSize;
            m_entityToIndexMap[entity] = newIndex;
            m_indexToEntityMap[newIndex] = entity;
            m_componentArray[newIndex] = component;
            mSize++;
        }

        void removeData(Entity entity) {
            assert(m_entityToIndexMap.find(entity) != m_entityToIndexMap.end() && "Removing non-existent component.");

            // Copy element at end into deleted element's place to maintain density
            size_t indexOfRemovedEntity = m_entityToIndexMap[entity];
            size_t indexOfLastElement = mSize - 1;
            m_componentArray[indexOfRemovedEntity] = m_componentArray[indexOfLastElement];

            // Update map to point to moved spot
            Entity entityOfLastElement = m_IndexToEntityMap[indexOfLastElement];
            m_entityToIndexMap[entityOfLastElement] = indexOfRemovedEntity;
            m_indexToEntityMap[indexOfRemovedEntity] = entityOfLastElement;

            m_entityToIndexMap.erase(entity);
            m_indexToEntityMap.erase(indexOfLastElement);

            m_Size--;
        }

        ComponentType& getData(Entity entity) {
            assert(m_entityToIndexMap.find(entity) != m_entityToIndexMap.end() && "Retrieving non-existent component.");

            // Return a reference to the entity's component
            return m_componentArray[m_entityToIndexMap[entity]];
        }

        void entityDestroyed(Entity entity) override {
            if (m_entityToIndexMap.find(entity) != m_entityToIndexMap.end()) {
                removeData(entity);
            }
        }

    private:

        std::array<ComponentType, MAX_ENTITIES> m_componentArray;
        std::unordered_map<Entity, size_t> m_entityToIndexMap;
        std::unordered_map<size_t, Entity> m_indexToEntityMap;

        size_t m_size;
};

#endif //COMPONENT_ARRAY_H