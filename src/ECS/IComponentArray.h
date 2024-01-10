#ifndef I_COMPONENT_ARRAY_H
#define I_COMPONENT_ARRAY_H

#include "ECSConstants.h"

class IComponentArray
{
    public:
        virtual ~IComponentArray() = default;
        virtual void entityDestroyed(Entity entity) = 0;
};

#endif //I_COMPONENT_ARRAY_H