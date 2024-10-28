// Entity.cpp

#include "Entity.hpp"

Transform2D& Entity::GetTransform()
{
    return mRegistry->Transforms[mID];
}

CircleComponent& Entity::AddCircleComponent()
{
    mRegistry->Circles[mID] = CircleComponent();
    return GetCircleComponent();
}

CircleComponent& Entity::GetCircleComponent()
{
    return mRegistry->Circles[mID];
}
