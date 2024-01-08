#include "IComponentArray.h"
#include <array>
#include <unordered_map>

template<typename ComponentType>

class ComponentArray : public IComponentArray {

    public:

        void InsertData(Entity entity, ComponentType component;)
        void RemoveData(Entity entity)
        ComponentType& GetData(Entity entity)
        void EntityDestroyed(Entity entity) override

    private:

        std::array<ComponentType, MAX_ENTITIES> m_componentArray;
        std::unordered_map<Entity, size_t> m_EntityToIndexMap;
        std::unordered_map<size_t, Entity> m_indexToEntityMap;

        size_t m_size;
};