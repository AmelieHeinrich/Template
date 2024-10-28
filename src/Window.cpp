// window.cpp

#include "window.hpp"

Window::Window(int width, int height, const std::string& title)
{
    mWindow.create(sf::VideoMode(width, height), title);
}

Window::~Window()
{
    if (mWindow.isOpen())
        Close();
}

bool Window::IsOpen()
{
    return mWindow.isOpen();
}

bool Window::PollEvent(sf::Event& e)
{
    return mWindow.pollEvent(e);
}

void Window::Close()
{
    mWindow.close();
}

void Window::Present()
{
    mWindow.display();
}
