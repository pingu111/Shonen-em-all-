#include "MenuPrincipal.h"

MenuPrincipal::MenuPrincipal()
{
	initTextures();
}

MenuPrincipal::MenuPrincipal(WindowManager* windowArg)
{
	window = windowArg;
	initTextures();
}

void MenuPrincipal::printBackgroundAndButtons()
{

	// On ajoute tous les sprites qu'on veut afficher 
	window->add(std::make_unique<sf::Sprite>(fondSprite));
	window->add(std::make_unique<sf::Sprite>(boutonGoToRNBSprite));

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

	boutonGoToRNB.loadFromFile("Ressources\\Menuprincipal\\TextBox.gif");
	boutonGoToRNBSprite.setTexture(boutonGoToRNB);

	boutonGoToRNBSprite.setPosition(window->getWindow()->getSize().x / 2	 - boutonGoToRNBSprite.getTextureRect().width / 2,
									window->getWindow()->getSize().y * 5 / 6 - boutonGoToRNBSprite.getTextureRect().height / 2);
}


MenuPrincipal::~MenuPrincipal()
{
	;
}

