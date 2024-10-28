// Entity.hpp

#pragma once

#include <cstdint>

#include "Registry.hpp"

class Entity
{
public:
    Entity() = default;
    ~Entity() = default;

    void SetParentRegistry(Registry *reg) { mRegistry = reg; }

    Transform2D& GetTransform();

    CircleComponent& AddCircleComponent();
    CircleComponent& GetCircleComponent();
private:
    friend class Scene;
    friend class Registry;

    Registry* mRegistry;
    std::uint64_t mID;
};