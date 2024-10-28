// GameState.hpp

#include "StateMachine.hpp"
#include "Scene.hpp"

class GameState : public State
{
public:
    GameState() = default;
    ~GameState() = default;

    void Init(StateMachine* machine) override;
    void Update(float dt) override;
    void Render(sf::RenderTarget& target) override;
    void Input(sf::Event event) override;

private:
    Scene mScene;
    Entity mBall;
};
