// Systems.cpp

#include "Systems.hpp"

void TransformSystem::Update(Registry& reg, float dt, std::uint64_t maxEntity)
{
    for (int e = 0; e < maxEntity; e++) {
        if (reg.Transforms.count(e) > 0) {
            sf::Transform& trans = reg.Transforms[e].Transform;
            trans.translate(reg.Transforms[e].Velocity);
            trans.rotate(reg.Transforms[e].Rotation);
            trans.scale(reg.Transforms[e].Scale);
        }
    }
}

void CircleSystem::Update(Registry& reg, std::uint64_t maxEntity, sf::RenderTarget& target)
{
    for (int e = 0; e < maxEntity; e++) {
        if (reg.Circles.count(e) > 0 && reg.Transforms.count(e) > 0) {
            sf::CircleShape shape;
            shape.setFillColor(reg.Circles[e].FillColor);
            shape.setRadius(reg.Circles[e].Radius);

            target.draw(shape, reg.Transforms[e].Transform);
        }
    }
}
