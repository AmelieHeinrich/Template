// GameState.cpp

#include "GameState.hpp"

#include <iostream>

void GameState::Init(StateMachine* machine)
{
    mMachine = machine;
}

void GameState::Update(float dt)
{
    std::cout << dt << std::endl;
}

void GameState::Render(sf::RenderTarget& target)
{
    target.clear(sf::Color::White);
}

void GameState::Input(sf::Event event)
{

}