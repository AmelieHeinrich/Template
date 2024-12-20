// Collider.hpp

#pragma once

#include <SFML/Graphics.hpp>
#include <functional>

struct BoxColliderComponent
{
    sf::RectangleShape Shape;
    sf::Vector2f Size;

    std::function<bool(const BoxColliderComponent& other)> OnCollide;
};
