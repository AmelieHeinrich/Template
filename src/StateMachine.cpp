// StateMachine.cpp

#include "StateMachine.hpp"

StateMachine::StateMachine(sf::RenderWindow& window)
    : mWindow(window)
{
}

StateMachine::~StateMachine()
{
    mCurrentState.reset();
}

void StateMachine::Update()
{
    sf::Time time = mDTClock.getElapsedTime();
    sf::Time dt = time - mLast;
    mLast = time;

    mCurrentState->Update(dt.asSeconds());
}

void StateMachine::Render()
{
    mCurrentState->Render(mWindow);
}

void StateMachine::Input(sf::Event event)
{
    mCurrentState->Input(event);
}
