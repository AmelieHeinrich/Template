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

RectangleComponent& Entity::AddRectangleComponent()
{
    mRegistry->Rectangles[mID] = RectangleComponent();
    return GetRectangleComponent();
}

RectangleComponent& Entity::GetRectangleComponent()
{
    return mRegistry->Rectangles[mID];
}

BoxColliderComponent& Entity::AddBoxColliderComponent()
{
    mRegistry->BoxColliders[mID] = BoxColliderComponent();
    return GetBoxColliderComponent();
}

BoxColliderComponent& Entity::GetBoxColliderComponent()
{
    return mRegistry->BoxColliders[mID];
}
