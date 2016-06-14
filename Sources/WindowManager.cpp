#include "WindowManager.h"


WindowManager::WindowManager()
{
	window.create(sf::VideoMode(1200, 900), "Shonen'em all");
	window.setActive(false);
}

//WindowManager WindowManager::m_instance = WindowManager();

WindowManager& WindowManager::Instance()
{
	static WindowManager m_instance;
	return m_instance;
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

void WindowManager::add(std::unique_ptr<Bouton> button)
{
	listButtons.push_back(move(button));
}

void WindowManager::clearText()
{
	listText.clear();
	listTextWithPeremption.clear();
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
	/*	std::string string = form->getString();
		std::cout << " Texte to print = " << string << "\n";
		std::cout << " Font to print = " << form->getFont()->getInfo().family << "\n";
		std::cout << " Size to print = " << form->getCharacterSize() << "\n";
		std::cout << " Pos to print = " << form->getPosition().x << "/"<<form->getPosition().y<<"\n";
		*/
		window.draw(*form);
	}

	for (auto &form : listButtons)
	{
		window.draw(*form->getSpriteAndMessage().first);

		/*std::string string = form->getSpriteAndMessage().second->getString();
		std::cout << " Texte to print = " << string << "\n";
		std::cout << " Font to print = " << form->getSpriteAndMessage().second->getFont()->getInfo().family << "\n";
		std::cout << " Size to print = " << form->getSpriteAndMessage().second->getCharacterSize() << "\n";
		std::cout << " Pos to print = " << form->getSpriteAndMessage().second->getPosition().x << "/"<<form->getSpriteAndMessage().second->getPosition().y<<"\n";
		*/
		window.draw(*form->getSpriteAndMessage().second);
	}

	for (auto &form : listTextWithPeremption)
	{
		if (std::time(nullptr) <= form.second + lifeTimeText)
			window.draw(*form.first);
	}



	window.display();
	listSprites.clear();
	listButtons.clear();

}

