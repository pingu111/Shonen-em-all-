#include <SceneBoss.h>

/* Le constructeur de la scene */
SceneBoss::SceneBoss(WindowManager *windowArg) : player(Player::Instance())
{
	window = windowArg;
	launchScene();
}

void SceneBoss::launchScene()
{
	initSprite();
	initFonts();
	// Boucle principale 
	while (window->getWindow()->isOpen())
	{
		printBackground();
		waitForUser();
	}
}

void SceneBoss::printBackground()
{
	// On ajoute tous les sprites qu'on veut afficher 
	window->add(std::make_unique<sf::Sprite>(fondSprite));
}

void SceneBoss::initSprite()
{
	assert(fond.loadFromFile("Ressources\\Boss\\fond.jpg") == true);
	fondSprite.setTexture(fond);
	window->add(std::make_unique<sf::Sprite>(fondSprite));

	// On créé les boutons
	for (int i = 0; i < 4; i++)
	{
		sf::Texture boutonTextTmp;
		Bouton boutonTmp;

		assert(boutonTextTmp.loadFromFile("Ressources\\Boss\\TextBoxBlank.gif") == true);
		sf::Sprite boutonSpriteTmp(boutonTextTmp);

		float sizeBetweenButtonsX = ((float)window->getWindow()->getSize().x -
									(float)(2 * boutonSpriteTmp.getTextureRect().width)) / 3;
		std::cout << sizeBetweenButtonsX << "\n";

		switch (i)
		{
			// Placement des 4 boutons de choix 
			case 0:
			{
				boutonSpriteTmp.setPosition(
					0,
					0);
				break;
			}
			case 1:
			{
				boutonSpriteTmp.setPosition(
					100,
					0);
				break;
			}
			case 2:
			{
				boutonSpriteTmp.setPosition(
					200,
					0);
				break;
			}
			case 3:
			{
				boutonSpriteTmp.setPosition(
					300,
					0);
				break;
			}
		}


		std::cout << boutonSpriteTmp.getPosition().x << "/" << boutonSpriteTmp.getPosition().y << " . "<< i << "\n";


		listSpritesButtonChoice.push_back(std::pair<sf::Sprite, std::unique_ptr<sf::Texture>>(boutonSpriteTmp, std::make_unique<sf::Texture>(boutonTextTmp)));
		listSpritesButtonChoice.back().first.setTexture(*listSpritesButtonChoice.back().second);

		boutonTmp.setSprite(boutonSpriteTmp);
		listButtonsChoices.push_back(boutonTmp);
	}

	for (int i = 0; i < 4; i++)
	{
		std::cout << listSpritesButtonChoice[i].first.getPosition().x << "/" << listSpritesButtonChoice[i].first.getPosition().y << "\n";
		window->add(std::make_unique<sf::Sprite>(listSpritesButtonChoice[i].first));
	}
	window->draw();
	system("pause");
}

void SceneBoss::initFonts()
{
	assert(comicFont.loadFromFile("Ressources\\ComicSansMS.ttf") == true);
}

/* attend l'appui sur un bouton */
void SceneBoss::waitForUser()
{
	sf::Event event;
	while (window->getWindow()->pollEvent(event))
	{
		if (event.type == sf::Event::Closed)
		{
			//TODO QUITTER PROPREMENT CAPSLOCKMAGGLE;
		}
		else if (event.type == sf::Event::KeyPressed)
		{
			if (event.key.code == sf::Keyboard::Escape)
			{
				std::cout << " sf::Keyboard::Escape\n";
				system("pause");
			}
		}
		else if (sf::Mouse::isButtonPressed(sf::Mouse::Left))
		{
			//On parcours les boutons et on verifie s'ils sont cliqués
			for (Bouton button : listButtonsChoices)
			{
				if (button.isClicked(sf::Mouse::getPosition(*window->getWindow())))
				{
					//player.update(/*replique choisie*/*repliques[0]);
				}
			}
		}
	}

}

/* selectionne aleatoirement 4 repliqes parmis toutes celles connues */
std::vector<Replique> SceneBoss::randReplique()
{
	int rand1, rand2, rand3, rand4;
	assert(repliques.size() > 4);
	rand1 = Random::randInt(0, repliques.size());
	do {
		rand2 = Random::randInt(0, repliques.size());
	} while (rand2 == rand1);
	do {
		rand3 = Random::randInt(0, repliques.size());
	} while (rand3 == rand1 || rand3 == rand2);
	do {
		rand4 = Random::randInt(0, repliques.size());
	} while (rand4 == rand1 || rand4 == rand2 || rand4 == rand3);

	std::vector<Replique> vec(4);
	vec = { *repliques[rand1],*repliques[rand2],*repliques[rand3],*repliques[rand4] };
	return vec;
}