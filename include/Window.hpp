// window.hpp

#pragma once

#include <SFML/Graphics.hpp>
#include <string>

class Window
{
public:
    Window(int width, int height, const std::string& title);
    ~Window();

    bool IsOpen();
    bool PollEvent(sf::Event& e);
    void Close();
    void Present();

    sf::RenderWindow& GetTarget() { return static_cast<sf::RenderWindow&>(mWindow); }
private:
    sf::RenderWindow mWindow;
};
