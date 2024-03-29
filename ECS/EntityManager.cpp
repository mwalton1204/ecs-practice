#include "EntityManager.h"

EntityManager::EntityManager() {
    for(Entity entity = 0; entity < MAX_ENTITIES; entity++) {
        m_availableEntities.push(entity);
    }
}

EntityManager::~EntityManager() {}

Entity EntityManager::createEntity() {
    assert(m_livingEntities < MAX_ENTITIES && "Too many entities.");

    Entity id = m_availableEntities.front();
    m_availableEntities.pop();
    m_livingEntities++;

    return id;
}

void EntityManager::destroyEntity(Entity entity) {
    assert(entity < MAX_ENTITIES && "Entity out of range.");

    m_signatures[entity].reset();

    m_availableEntities.push(entity);
    m_livingEntities--;
}

void EntityManager::setSignature(Entity entity, Signature signature) {
    assert(entity < MAX_ENTITIES && "Entity out of range.");

    m_signatures[entity] = signature;
}

Signature EntityManager::getSignature(Entity entity) {
    assert(entity < MAX_ENTITIES && "Entity out of range.");

    return m_signatures[entity];
}

