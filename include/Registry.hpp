// Registry.hpp

#pragma once

#include <unordered_map>

#include "Components/Transform.hpp"
#include "Components/Circle.hpp"
#include "Components/Rectangle.hpp"
#include "Components/Collider.hpp"

using EntityID = std::uint64_t;

struct Registry
{
    std::unordered_map<EntityID, Transform2D> Transforms = {};
    std::unordered_map<EntityID, CircleComponent> Circles = {};
    std::unordered_map<EntityID, RectangleComponent> Rectangles = {};
    std::unordered_map<EntityID, BoxColliderComponent> BoxColliders = {};
};
