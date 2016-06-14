#include <YouDied.h>

/* Le constructeur de la scene */
YouDied::YouDied()
{
	initFonts();
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
	WindowManager::Instance().add(std::make_unique<sf::Text>(textFont.first));

	WindowManager::Instance().draw();
}


void YouDied::initSprite()
{
	assert(fond.loadFromFile("Ressources\\YouDied.jpg") == true);
	fondSprite.setTexture(fond);

	textFont.second = comicFont;
	textFont.first.setFont(textFont.second);
	textFont.first.setCharacterSize(80);

	std::string message;
	int score = Player::Instance().getScore();
	message += "Score : ";
	message += std::to_string(score);
	std::cout << message << "\n";

	textFont.first.setString(message);
	textFont.first.setPosition
	(
		fondSprite.getTextureRect().width / 2 - textFont.first.getGlobalBounds().width / 2,
		fondSprite.getTextureRect().height * 5/6 - textFont.first.getGlobalBounds().height / 2
	);
}

void YouDied::waitForUser()
{
	printBackground();
	std::string input;

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
			else if (event.type == sf::Event::TextEntered)
			{
				if (event.text.unicode < 128)
				{
					input += static_cast<char>(event.text.unicode);

					if (input.find("666") != std::string::npos)
						SceneManager::moveToScene(SceneNames::RNB);
					if (input.find("trump") != std::string::npos)
						SceneManager::moveToScene(SceneNames::RNB);
					if (input.find("lol") != std::string::npos)
						SceneManager::moveToScene(SceneNames::DEFEAT);
					if (input.find("reset") != std::string::npos)
						SceneManager::moveToScene(SceneNames::MENU);
				}
			}
			if (event.type == sf::Event::KeyPressed)
			{
				if (event.key.code == sf::Keyboard::Escape)
				{
					// On quitte
					return;
				}
			}
		}
	}
}
