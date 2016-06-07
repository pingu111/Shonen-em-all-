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

void WindowManager::add(std::unique_ptr<sf::Text> form)
{
	listText.push_back(move(form));
}

void WindowManager::addWithPeremption(std::unique_ptr<sf::Text> form , int peremptionTime)
{
	listTextWithPeremption.push_back(std::pair<std::unique_ptr<sf::Text>, int>(move(form), peremptionTime));
}

void WindowManager::clearText()
{
	listText.clear();
}



void WindowManager::draw()
{
	window.clear(sf::Color::White);

	for (auto &form : listSprites)
	{
		window.draw(*form);
	}
	for (auto &form : listText)
	{
		window.draw(*form);
	}
	for (auto &form : listTextWithPeremption)
	{
		if(std::time(nullptr) <= form.second + lifeTimeText)
			window.draw(*form.first);
	}
	window.display();
	listSprites.clear();
}

