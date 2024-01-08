#include "ComponentArray.h"

template<typename ComponentType>
void ComponentArray::InsertData(Entity entity, ComponentType component) {
    assert(mEntityToIndexMap.find(entity) == mEntityToIndexMap.end() && "Component added to same entity more than once.");

    // Put new entry at end and update the maps
    size_t newIndex = mSize;
    mEntityToIndexMap[entity] = newIndex;
    mIndexToEntityMap[newIndex] = entity;
    mComponentArray[newIndex] = component;
    mSize++;
}

void ComponentArray::RemoveData(Entity entity) {
    assert(m_EntityToIndexMap.find(entity) != m_EntityToIndexMap.end() && "Removing non-existent component.");

    // Copy element at end into deleted element's place to maintain density
    size_t indexOfRemovedEntity = m_EntityToIndexMap[entity];
    size_t indexOfLastElement = mSize - 1;
    m_ComponentArray[indexOfRemovedEntity] = m_ComponentArray[indexOfLastElement];

    // Update map to point to moved spot
    Entity entityOfLastElement = m_IndexToEntityMap[indexOfLastElement];
    m_EntityToIndexMap[entityOfLastElement] = indexOfRemovedEntity;
    m_IndexToEntityMap[indexOfRemovedEntity] = entityOfLastElement;

    m_EntityToIndexMap.erase(entity);
    m_IndexToEntityMap.erase(indexOfLastElement);

    m_Size--;
}

template<typename ComponentType>
ComponentType& ComponentArray::GetData(Entity entity){
    assert(m_EntityToIndexMap.find(entity) != m_EntityToIndexMap.end() && "Retrieving non-existent component.");

    // Return a reference to the entity's component
    return m_ComponentArray[m_EntityToIndexMap[entity]];
}

void ComponentArray::EntityDestroyed(Entity entity) override {
    if (m_EntityToIndexMap.find(entity) != m_EntityToIndexMap.end()) {
        RemoveData(entity);
    }
}