// Registry.hpp

#pragma once

#include <unordered_map>

#include "Components/Transform.hpp"
#include "Components/Circle.hpp"

using EntityID = std::uint64_t;

struct Registry
{
    std::unordered_map<EntityID, Transform2D> Transforms = {};
    std::unordered_map<EntityID, CircleComponent> Circles = {};
};
