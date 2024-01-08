#include "IComponentArray.h"
#include <array>
#include <unordered_map>
#include <cassert>

template<typename ComponentType>
class ComponentArray : public IComponentArray {

    public:

        void insertData(Entity, ComponentType);
        void removeData(Entity);
        ComponentType& getData(Entity);
        void entityDestroyed(Entity) override;

    private:

        std::array<ComponentType, MAX_ENTITIES> m_componentArray;
        std::unordered_map<Entity, size_t> m_entityToIndexMap;
        std::unordered_map<size_t, Entity> m_indexToEntityMap;

        size_t m_size;
};

#include "ComponentArray.tpp"