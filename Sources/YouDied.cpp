#include <YouDied.h>

/* Le constructeur de la scene */
YouDied::YouDied()
{
	initSprite();
}

YouDied& YouDied::Instance()
{
	static YouDied m_instance;
	return m_instance;
}

void YouDied::reload()
{
	launchScene();
}

void YouDied::launchScene()
{
	waitForUser();
}

void YouDied::printBackground()
{
	// On ajoute tous les sprites qu'on veut afficher 
	WindowManager::Instance().add(std::make_unique<sf::Sprite>(fondSprite));
	WindowManager::Instance().draw();
}


void YouDied::initSprite()
{
	assert(fond.loadFromFile("Ressources\\YouDied.jpg") == true);
	fondSprite.setTexture(fond);
}

void YouDied::waitForUser()
{
	printBackground();

	while (WindowManager::Instance().getWindow()->isOpen())
	{
		;
	}
}
