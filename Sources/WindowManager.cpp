#include "WindowManager.h"

WindowManager::WindowManager()
{
	window.create(sf::VideoMode(1200, 900), "Shonen'em all");
	window.setActive(false);
}

sf::RenderWindow* WindowManager::getWindow()
{
	return &window;
}

WindowManager::~WindowManager()
{

}

void WindowManager::add(std::unique_ptr<sf::Sprite> form)
{
	listSprites.push_back(move(form));
}

void WindowManager::draw()
{
	window.clear();

	for (auto &form : listSprites)
	{
		window.draw(*form);
	}
	window.display();
}

