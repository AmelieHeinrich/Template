// Transform.hpp

#pragma once

#include <SFML/Graphics.hpp>

struct Transform2D
{
    sf::Vector2f Position;
    sf::Vector2f Velocity;
    sf::Vector2f Scale;
    float Rotation;
    sf::Transform Transform;
};
