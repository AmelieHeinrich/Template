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

    sf::RenderTarget& GetTarget() { return static_cast<sf::RenderTarget&>(mWindow); }
private:
    sf::RenderWindow mWindow;
};
