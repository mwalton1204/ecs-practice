#ifndef COMPONENT_MANAGER_H
#define COMPONENT_MANAGER_H

#include "ECSConstants.h"
#include "ComponentArray.h"
#include <memory>
#include <unordered_map>

class ComponentManager {
    public:

        ComponentManager(){}
        ~ComponentManager(){}

        template<typename ComponentType>
        void registerComponent(){
            const char* typeName = typeid(ComponentType).name();

		    assert(m_componentTypes.find(typeName) == m_componentTypes.end() && "Registering component type more than once.");

            // Add this component type to the component type map
		    m_componentTypes.insert({typeName, m_nextComponentType});

            // Create a ComponentArray pointer and add it to the component arrays map
		    m_componentArrays.insert({typeName, std::make_shared<ComponentArray<T>>()});

            m_nextComponentType++;
        }

        template<typename ComponentType>
        Component getComponentType() {
            const char* typeName = typeid(ComponentType).name();

		    assert(m_componentTypes.find(typeName) != m_componentTypes.end() && "Component not registered before use.");

		    return m_componentTypes[typeName];
        }

        template<typename ComponentType>
        void addComponent(Entity entity, ComponentType component) {
            // Add a component to the array for an entity
		    getComponentArray<ComponentType>()->insertData(entity, component);
        }

        template<typename ComponentType>
        void removeComponent(Entity entity) {
            // Remove a component from the array for an entity
		    getComponentArray<ComponentType>()->removeData(entity);
        }

        template<typename ComponentType>
        Component& getComponent(Entity entity) {
            // Get a reference to a component from the array for an entity
		    return getComponentArray<ComponentType>()->getData(entity);
        }

        void entityDestroyed(Entity entity) {
            // Notify each component array that an entity has been destroyed
            // If it has a component for that entity, it will remove it
            for (auto const& pair : m_componentArrays)
            {
                auto const& component = pair.second;

                component->entityDestroyed(entity);
            }
        }

    private:

    std::unordered_map<const char*, Component> m_componentTypes{};
    std::unordered_map<const char*, std::shared_ptr<IComponentArray>> m_componentArrays{};
    Component m_nextComponentType{};

    template<typename ComponentType>
    std::shared_ptr<ComponentArray<ComponentType>> getComponentArray() {
        const char* typeName = typeid(ComponentType).name();

        assert(m_componentTypes.find(typeName) != m_componentTypes.end() && "Component not registered before use.");

		return std::static_pointer_cast<ComponentArray<T>>(mComponentArrays[typeName]);
    }


};

#endif //COMPONENT_MANAGER_H