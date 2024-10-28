// Scene.hpp

#pragma once

#include <vector>

#include "Entity.hpp"
#include "Registry.hpp"
#include "Systems.hpp"

class Scene
{
public:
    Scene() = default;
    ~Scene();

    Entity& CreateEntity();

    void Update(float dt);
    void Render(sf::RenderTarget& target);
private:
    std::vector<Entity> mEntities;

    Registry mRegistry;
    TransformSystem mTransformSystem;
    CircleSystem mCircleSystem;
    RectangleSystem mRectangleSystem;
    BoxColliderSystem mColliderSystem;
};
