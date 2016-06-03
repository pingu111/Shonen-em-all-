#include "MenuPrincipal.h"

MenuPrincipal::MenuPrincipal()
{
	;
}

MenuPrincipal::MenuPrincipal(WindowManager& windowArg)
{
	window = windowArg.clone();
}

void MenuPrincipal::printBackgroundAndButtons()
{
	window->getWindow()->clear();

	sf::RectangleShape background(sf::Vector2f(	(float)window->getWindow()->getSize().x, 
												(float)window->getWindow()->getSize().y));

	background.setFillColor(sf::Color::Black);
	window->getWindow()->draw(background);
	window->getWindow()->display();
}

EnumChoicesUser MenuPrincipal::waitForUser()
{
	// Boucle verifiant les evenements
	while (window->getWindow()->isOpen())
	{
		sf::Event event;

		while (window->getWindow()->pollEvent(event))
		{
			if (event.type == sf::Event::Closed ||
				event.key.code == sf::Keyboard::Escape)
				return QUIT;
		}		
		//if(bouton a été cliqué)
		// return RYTHM;
	}
	return QUIT;
}


MenuPrincipal::~MenuPrincipal()
{
	;
}
