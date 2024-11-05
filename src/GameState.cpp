// GameState.cpp

#include "GameState.hpp"

#include <iostream>

void GameState::Init(StateMachine* machine)
{
    mMachine = machine;

    // Setup paddle
    {
        mPaddle = mScene.CreateEntity();

        RectangleComponent& box = mPaddle.AddRectangleComponent();
        box.FillColor = sf::Color::White;
        box.Size = sf::Vector2f(100.0f, 10.0f);

        Transform2D& transform = mPaddle.GetTransform();
        transform.Position = sf::Vector2f(350.0f, 550.0f);
        transform.Scale = sf::Vector2f(1.0f, 1.0f);
   
        BoxColliderComponent& collider = mPaddle.GetBoxColliderComponent();
        collider.Size = box.Size;
        collider.OnCollide = [](const BoxColliderComponent& other) {};
    }

    // Setup ball
    {
        mBall = mScene.CreateEntity();

        CircleComponent& circle = mBall.AddCircleComponent();
        circle.FillColor = sf::Color::Green;
        circle.Radius = 10.0f;

        Transform2D& transform = mBall.GetTransform();
        transform.Position = sf::Vector2f(390.0f, 290.0f);
        transform.Scale = sf::Vector2f(1.0f, 1.0f);
        transform.Velocity = sf::Vector2f(100.0f, 100.0f);

        BoxColliderComponent& collider = mBall.GetBoxColliderComponent();
        collider.Size = sf::Vector2f(20.0f, 20.0f);
        collider.OnCollide = [this](const BoxColliderComponent& other) {
            Transform2D& transform = mBall.GetTransform();
            transform.Velocity.y = -transform.Velocity.y;
            transform.Position += transform.Velocity.y < 0 ? sf::Vector2f(-1.0f, -1.0f) : sf::Vector2f(1.0f, 1.0f);
        };
    }
}

void GameState::Update(float dt)
{
    mScene.Update(dt);

    // paddle update
    {
        Transform2D& transform = mPaddle.GetTransform();
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
            transform.Position.x -= 1000.0 * dt;
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
            transform.Position.x += 1000.0 * dt;
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up))
            transform.Position.y -= 1000.0 * dt;
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down))
            transform.Position.y += 1000.0 * dt;
    }

    // ball update
    {
        Transform2D& transform = mBall.GetTransform();
        CircleComponent& circle = mBall.GetCircleComponent();

        if (transform.Position.x >= mBounds.x - circle.Radius) transform.Velocity.x = -transform.Velocity.x;
        if (transform.Position.x <= circle.Radius) transform.Velocity.x = -transform.Velocity.x;
        if (transform.Position.y >= mBounds.y - circle.Radius) transform.Velocity.y = -transform.Velocity.y;
        if (transform.Position.y <= circle.Radius) transform.Velocity.y = -transform.Velocity.y;
    }
}

void GameState::Render(sf::RenderWindow& target)
{
    mBounds = sf::Vector2u(target.getSize());

    target.clear();
    mScene.Render(target);
}

void GameState::Input(sf::Event event)
{
    
}
