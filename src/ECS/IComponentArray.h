#include "ECSConstants.h"

class IComponentArray
{
    public:
        virtual ~IComponentArray() = default;
        virtual void EntityDestroyed(Entity entity) = 0;
};