#ifndef ENTITY_MANAGER_H
#define ENTITY_MANAGER_H

#include <queue>
#include <array>
#include "ECSConstants.h"

class EntityManager {
    public:

        EntityManager();
        ~EntityManager();

        Entity createEntity();
        void destroyEntity(Entity entity);
        void setFlags(Entity entity, Signature signature);
        void getFlags(Entity entity);

    private:

    std::queue<Entity> m_availableEntities{};
    std::array<Signature, MAX_ENTITIES> m_signatures{};
    uint32_t m_livingEntities;

};

#endif //ENTITY_MANAGER_H