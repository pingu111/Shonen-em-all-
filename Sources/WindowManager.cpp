#include "WindowManager.h"

WindowManager::WindowManager()
{
	window.create(sf::VideoMode(1200, 900), "Shonen'em all");
}

sf::RenderWindow* WindowManager::getWindow()
{
	return &window;
}

WindowManager::~WindowManager()
{

}

std::unique_ptr<WindowManager> WindowManager::clone()
{
	// On ferme la window avant de la passer 
	window.close();

	auto uniPtr = std::make_unique<WindowManager>();
	return move(uniPtr);
}