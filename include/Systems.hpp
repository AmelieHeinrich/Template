// Systems.hpp

#pragma once

#include "Registry.hpp"

class TransformSystem
{
public:
    TransformSystem() = default;
    ~TransformSystem() = default;

    void Update(Registry& reg, float dt, std::uint64_t maxEntity);
};

class CircleSystem
{
public:
    CircleSystem() = default;
    ~CircleSystem() = default;

    void Update(Registry& reg, std::uint64_t maxEntity, sf::RenderTarget& target);
};
