#include <MenuPrincipal.h>
#include <iostream>

MenuPrincipal::MenuPrincipal()
{
	initTextures();
	printBackgroundAndButtons();
	waitForUser();
}

MenuPrincipal::MenuPrincipal(WindowManager* windowArg)
{
	window = windowArg;
	initTextures();
	printBackgroundAndButtons();
	waitForUser();
}

void MenuPrincipal::printBackgroundAndButtons()
{

	// On ajoute tous les sprites qu'on veut afficher 
	window->add(std::make_unique<sf::Sprite>(fondSprite));
	window->add(std::make_unique<sf::Sprite>(boutonRNB->getSprite()));

	// On les affiche
	window->draw();
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
			if (sf::Mouse::isButtonPressed(sf::Mouse::Left))
			{
				if (boutonRNB->isClicked(sf::Mouse::getPosition(*window->getWindow())))
				{
					std::cout << "Clique !\n";
					Global::moveToScene(SceneNames::RNB, window);
					return RYTHM;
				}
			}
		}		
		//if(bouton a été cliqué)
		// return RYTHM;
	}

	return QUIT;
}

void MenuPrincipal::initTextures()
{
	assert(fond.loadFromFile("Ressources\\Menuprincipal\\FondMenuPrincipal.jpg") == true);
	fondSprite.setTexture(fond);

	assert(boutonGoToRNB.loadFromFile("Ressources\\Menuprincipal\\TextBox.gif") == true);
	boutonGoToRNBSprite.setTexture(boutonGoToRNB);

	boutonGoToRNBSprite.setPosition((float) window->getWindow()->getSize().x / 2	 - boutonGoToRNBSprite.getTextureRect().width / 2,
									(float) window->getWindow()->getSize().y * 5 / 6 - boutonGoToRNBSprite.getTextureRect().height / 2);

	// On créé le bouton qui cible le Hack n slash
	boutonRNB->setSprite(boutonGoToRNBSprite);
}


MenuPrincipal::~MenuPrincipal()
{
	;
}

