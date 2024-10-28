// main.cpp

#include "Window.hpp"
#include "GameState.hpp"

int main()
{
    Window window(1280, 720, "Template");

    StateMachine machine(window.GetTarget());
    machine.SetStartupState<GameState>();

    while (window.IsOpen()) {
        sf::Event e;
        while (window.PollEvent(e)) {
            if (e.type == sf::Event::Closed)
                window.Close();
            machine.Input(e);
        }
        
        machine.Update();
        machine.Render();
        window.Present();
    }

    return 0;
}