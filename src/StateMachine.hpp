// StateMachine.hpp

#pragma once

#include <SFML/Graphics.hpp>
#include <memory>
#include <stack>

/// @todo(ame): add scene class taken in update and render

class StateMachine;

class State
{
public:
    State() = default;
    ~State() = default;

    virtual void Init(StateMachine* machine) = 0;
    virtual void Update(float dt) = 0;
    virtual void Render(sf::RenderTarget& target) = 0;
    virtual void Input(sf::Event event) = 0;

protected:
    StateMachine* mMachine;
};

class StateMachine
{
public:
    StateMachine(sf::RenderTarget& window);
    ~StateMachine();

    void Update();
    void Render();
    void Input(sf::Event event);

    template<typename T, typename... Args>
    void SetStartupState(Args&&... args)
    {
        mCurrentState = std::make_shared<T>(std::forward<Args>(args)...);
        mCurrentState->Init(this);
    }

    template<typename T, typename... Args>
    void SetState(Args&&... args)
    {
        mCurrentState.reset();
        mCurrentState = std::make_shared<T>(std::forward<Args>(args)...);
        mCurrentState->Init(this);
    }
private:
    std::shared_ptr<State> mCurrentState;
    sf::RenderTarget& mWindow;
    sf::Clock mDTClock;
    sf::Time mLast;
};
