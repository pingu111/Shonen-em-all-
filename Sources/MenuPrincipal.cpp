#include "MenuPrincipal.h"

MenuPrincipal::MenuPrincipal()
{
	initTextures();
}

MenuPrincipal::MenuPrincipal(WindowManager& windowArg)
{
	initTextures();
	window = windowArg.clone();
}

void MenuPrincipal::printBackgroundAndButtons()
{

	// On ajoute tous les sprites qu'on veut afficher 
	window->add(std::make_unique<sf::Sprite>(fondSprite));

	// On les affiche
	window->draw();
}

EnumChoicesUser MenuPrincipal::waitForUser()
{
	// Boucle verifiant les evenements
	while (true)
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

void MenuPrincipal::initTextures()
{
	fond.loadFromFile("Ressources\\Menuprincipal\\FondMenuPrincipal.jpg");
	fondSprite.setTexture(fond);

}


MenuPrincipal::~MenuPrincipal()
{
	;
}

