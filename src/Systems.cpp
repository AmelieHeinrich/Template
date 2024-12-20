// Systems.cpp

#include "Systems.hpp"

void TransformSystem::Update(Registry& reg, float dt, std::uint64_t maxEntity)
{
    for (int e = 0; e < maxEntity; e++) {
        if (reg.Transforms.count(e) > 0) {
            sf::Transform& trans = reg.Transforms[e].Transform;
            trans.rotate(reg.Transforms[e].Rotation);
            trans.scale(reg.Transforms[e].Scale);

            reg.Transforms[e].Position += reg.Transforms[e].Velocity * dt;
        }
    }
}

void CircleSystem::Update(Registry& reg, std::uint64_t maxEntity, sf::RenderWindow& target)
{
    for (int e = 0; e < maxEntity; e++) {
        if (reg.Circles.count(e) > 0 && reg.Transforms.count(e) > 0) {
            sf::CircleShape& shape = reg.Circles[e].Shape;
            shape.setPosition(reg.Transforms[e].Position);
            shape.setFillColor(reg.Circles[e].FillColor);
            shape.setRadius(reg.Circles[e].Radius);

            target.draw(shape, reg.Transforms[e].Transform);
        }
    }
}

void RectangleSystem::Update(Registry& reg, std::uint64_t maxEntity, sf::RenderWindow& target)
{
    for (int e = 0; e < maxEntity; e++) {
        if (reg.Rectangles.count(e) > 0 && reg.Transforms.count(e) > 0) {
            sf::RectangleShape& shape = reg.Rectangles[e].Shape;
            shape.setPosition(reg.Transforms[e].Position);
            shape.setFillColor(reg.Rectangles[e].FillColor);
            shape.setSize(reg.Rectangles[e].Size);

            target.draw(shape, reg.Transforms[e].Transform);
        }
    }
}

void BoxColliderSystem::Update(Registry& reg, std::uint64_t maxEntity)
{
    // Create a list of entities to destroy after the collision checks
    std::vector<int> entitiesToDestroy;

    for (int ex = 0; ex < maxEntity; ex++) {
        if (reg.BoxColliders.count(ex) > 0 && reg.Transforms.count(ex) > 0) {
            for (int ey = 0; ey < maxEntity; ey++) {
                if (reg.BoxColliders.count(ey) > 0 && reg.Transforms.count(ey) > 0) {
                    if (ex == ey) continue;

                    // Get the shapes for each collider for debugging (optional)
                    sf::RectangleShape& leftShape = reg.BoxColliders[ex].Shape;
                    leftShape.setOutlineColor(sf::Color::Red);
                    leftShape.setOutlineThickness(1.0f);
                    leftShape.setPosition(reg.Transforms[ex].Position);
                    leftShape.setScale(reg.Transforms[ex].Scale);
                    leftShape.setSize(reg.BoxColliders[ex].Size);

                    sf::RectangleShape& rightShape = reg.BoxColliders[ey].Shape;
                    rightShape.setOutlineColor(sf::Color::Red);
                    rightShape.setOutlineThickness(1.0f);
                    rightShape.setPosition(reg.Transforms[ey].Position);
                    rightShape.setScale(reg.Transforms[ey].Scale);
                    rightShape.setSize(reg.BoxColliders[ey].Size);

                    // Check for collision between the two shapes
                    if (leftShape.getGlobalBounds().intersects(rightShape.getGlobalBounds())) {
                        // Perform the collision action for both entities
                        if (reg.BoxColliders[ex].OnCollide(reg.BoxColliders[ey]))
                            entitiesToDestroy.push_back(ex);
                        if (reg.BoxColliders[ey].OnCollide(reg.BoxColliders[ex]))
                            entitiesToDestroy.push_back(ey);
                    }
                }
            }
        }
    }

    // Destroy the entities outside of the loop
    for (int entityId : entitiesToDestroy) {
        if (reg.BoxColliders.count(entityId) > 0) {
            reg.BoxColliders.erase(entityId);  // Remove the collider
        }
        if (reg.Transforms.count(entityId) > 0) {
            reg.Transforms.erase(entityId);  // Remove the transform
        }
        // Optionally, remove other components related to this entity
        // reg.OtherComponents.erase(entityId);
    }
}

void BoxColliderSystem::Draw(Registry& reg, std::uint64_t maxEntity, sf::RenderWindow& target)
{
    for (int e = 0; e < maxEntity; e++) {
        if (reg.BoxColliders.count(e) > 0 && reg.Transforms.count(e) > 0) {
            sf::RectangleShape& leftShape = reg.BoxColliders[e].Shape;
            leftShape.setOutlineColor(sf::Color::Red);
            leftShape.setFillColor(sf::Color::Black);
            leftShape.setOutlineThickness(1.0f);
            leftShape.setPosition(reg.Transforms[e].Position);
            leftShape.setScale(reg.Transforms[e].Scale);
            leftShape.setSize(reg.BoxColliders[e].Size);

            target.draw(reg.BoxColliders[e].Shape);
        }
    }
}
