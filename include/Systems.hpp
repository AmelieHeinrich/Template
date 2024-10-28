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

class RectangleSystem
{
public:
    RectangleSystem() = default;
    ~RectangleSystem() = default;

    void Update(Registry& reg, std::uint64_t maxEntity, sf::RenderTarget& target);
};

class BoxColliderSystem
{
public:
    BoxColliderSystem() = default;
    ~BoxColliderSystem() = default;

    void Update(Registry& reg, std::uint64_t maxEntity);
    void Draw(Registry& reg, std::uint64_t maxEntity, sf::RenderTarget& target);
};
