#include <YouDied.h>

/* Le constructeur de la scene */
YouDied::YouDied()
{
	initSprite();
	initFonts();
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
	WindowManager::Instance().add(std::make_unique<sf::Text>(textFont.first));

	WindowManager::Instance().draw();
}


void YouDied::initSprite()
{
	assert(fond.loadFromFile("Ressources\\YouDied.jpg") == true);
	fondSprite.setTexture(fond);

	textFont.second = comicFont;
	textFont.first.setFont(textFont.second);
	textFont.first.setCharacterSize(100);

	std::string message;
	int score = Player::Instance().getScore();
	message += "Score : ";
	message += score;
	message += "\nBravo !";
	std::cout << message << "\n";

	textFont.first.setString(message);
}

void YouDied::waitForUser()
{
	printBackground();
	nbSix = 0;
	while (WindowManager::Instance().getWindow()->isOpen())
	{
		sf::Event event;
		int damages = 0;
		while (WindowManager::Instance().getWindow()->pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
			{
				return;
			}
			else if (event.type == sf::Event::KeyPressed)
			{
				if (event.key.code == sf::Keyboard::Escape)
				{
					// On quitte
					return;
				}
				if (event.key.code == sf::Keyboard::Num6)
				{
					// Easter egg ici
					nbSix++;
					if (nbSix == 3)
					{
						SceneManager::moveToScene(SceneNames::RNB);
					}
				}
			};
		}
	}
}
