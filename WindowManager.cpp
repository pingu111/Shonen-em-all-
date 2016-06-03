#include "WindowManager.h"

WindowManager::WindowManager()
{
	window.create(sf::VideoMode(1200, 800), "Shonen'em all");
}

sf::RenderWindow* WindowManager::getWindow()
{
	return &window;
}

WindowManager::~WindowManager()
{

}