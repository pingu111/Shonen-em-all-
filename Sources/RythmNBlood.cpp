#include <RythmNBlood.h>

RythmNBlood::RythmNBlood(WindowManager* windowArg)
{
	//ennemis = std::vector<Ennemi>();
	window = windowArg;
	launchScene();
}

RythmNBlood::~RythmNBlood()
{
}

void RythmNBlood::launchScene()
{
	initTextures();
	printBackgroundAndButtons();
	waitForUser();
}

void RythmNBlood::initTextures()
{
	assert(fond.loadFromFile("Ressources\\RNB\\Fond.png") == true);
	fondSprite.setTexture(fond);
}

void RythmNBlood::printBackgroundAndButtons()
{
	// On ajoute tous les sprites qu'on veut afficher 
	window->add(std::make_unique<sf::Sprite>(fondSprite));

	// On les affiche
	window->draw();
}

void RythmNBlood::waitForUser()
{
	while (window->getWindow()->isOpen())
	{
		sf::Event event;
		while (window->getWindow()->pollEvent(event))
		{
			for (Ennemi enn : ennemis)
				enn.update();

			if (event.type == sf::Event::Closed ||
				event.key.code == sf::Keyboard::Escape)
				;
			if (event.key.code == sf::Keyboard::Left)
				;
			if (event.key.code == sf::Keyboard::Right)
				;
			if (sf::Mouse::isButtonPressed(sf::Mouse::Left))
			{
				//On parcours les boutons et on verifie s'ils sont cliqués
			}
			
		}
	}
}
