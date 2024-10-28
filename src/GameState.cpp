// GameState.cpp

#include "GameState.hpp"

#include <iostream>

void GameState::Init(StateMachine* machine)
{
    mMachine = machine;

    mBall = mScene.CreateEntity();

    Transform2D& transform = mBall.GetTransform();
    transform.Position = sf::Vector2f(0, 0);
    transform.Scale = sf::Vector2f(1.0f, 1.0f);

    CircleComponent& circle = mBall.AddCircleComponent();
    circle.FillColor = sf::Color::White;
    circle.Radius = 10.0f;
}

void GameState::Update(float dt)
{
    Transform2D& transform = mBall.GetTransform();
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
        transform.Velocity.x -= 1000.0 * dt;
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
        transform.Velocity.x += 1000.0 * dt;

    mScene.Update(dt);

    transform.Velocity = sf::Vector2f(0.0f, 0.0f);
}

void GameState::Render(sf::RenderTarget& target)
{
    target.clear();
    mScene.Render(target);
}

void GameState::Input(sf::Event event)
{
    
}
