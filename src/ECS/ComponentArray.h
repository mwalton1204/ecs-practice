#include "IComponentArray.h"
#include <array>
#include <unordered_map>
#include <cassert>

template<typename ComponentType>
class ComponentArray : public IComponentArray {

    public:

        void InsertData(Entity, ComponentType);
        void RemoveData(Entity);
        ComponentType& GetData(Entity);
        void EntityDestroyed(Entity) override;

    private:

        std::array<ComponentType, MAX_ENTITIES> m_componentArray;
        std::unordered_map<Entity, size_t> m_EntityToIndexMap;
        std::unordered_map<size_t, Entity> m_indexToEntityMap;

        size_t m_size;
};

#include "ComponentArray.tpp"