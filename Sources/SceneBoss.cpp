#include <SceneBoss.h>

/* Le constructeur de la scene */
SceneBoss::SceneBoss(WindowManager *windowArg) : player(Player::Instance())
{
	window = windowArg;
	launchScene();
}

void SceneBoss::launchScene()
{
	initRepliques();
	initFonts();
	initSprite();
	initFonts();
	chargeButtons(randReplique());

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

	for (auto &button : listButtonsChoices)
	{
		std::cout << "Hop \n";
		window->add(std::make_unique<Bouton>(button));
	}
	window->draw();
}

void SceneBoss::initRepliques()
{
	for (Replique rep : ListReplique::repliques)
	{
		repliques.push_back(std::make_unique<Replique>(rep));
		std::cout << rep.text << " n° " << repliques.size() << std::endl;
	}
	/*for (int i = 0; i < 10; i++)
	{
		Replique rep;
		std::string message = "Ceci est un\ntest, ?!\nnumero ";
		message += std::to_string(i);

		rep.text = message;
		rep.damageMult = 1;
		rep.scoreMult = 2;

		repliques.push_back(std::make_unique<Replique>(rep));
	}*/
}

void SceneBoss::initSprite()
{
	assert(fond.loadFromFile("Ressources\\Boss\\FondNuit.jpg") == true);
	fondSprite.setTexture(fond);
	window->add(std::make_unique<sf::Sprite>(fondSprite));

	// On créé les boutons
	for (int i = 0; i < 4; i++)
	{
		sf::Texture boutonTextTmp;
		Bouton boutonTmp;
		sf::Sprite boutonSpriteTmp;

		assert(boutonTextTmp.loadFromFile("Ressources\\Boss\\TextBoxBlank.gif") == true);

		std::unique_ptr<sf::Texture> ptrTexture = std::make_unique<sf::Texture>(boutonTextTmp);
		boutonSpriteTmp.setTexture(*ptrTexture);

		float sizeBetweenButtonsX = ((float)window->getWindow()->getSize().x -
									(float)(2 * boutonSpriteTmp.getTextureRect().width)) / 3;

		switch (i)
		{
			// Placement des 4 boutons de choix 
			case 0:
				boutonSpriteTmp.setPosition(
					sizeBetweenButtonsX,
					(float)window->getWindow()->getSize().y - 2.1f * boutonSpriteTmp.getTextureRect().height);
				break;
			case 1:
				boutonSpriteTmp.setPosition(
					(float)window->getWindow()->getSize().x - sizeBetweenButtonsX - boutonSpriteTmp.getTextureRect().width,
					(float)window->getWindow()->getSize().y - 2.1f * boutonSpriteTmp.getTextureRect().height);
				break;
			case 2:
				boutonSpriteTmp.setPosition(
					sizeBetweenButtonsX,
					(float)window->getWindow()->getSize().y - 1.05f * boutonSpriteTmp.getTextureRect().height);
				break;
			case 3:
				boutonSpriteTmp.setPosition(
					(float)window->getWindow()->getSize().x - sizeBetweenButtonsX - boutonSpriteTmp.getTextureRect().width,
					(float)window->getWindow()->getSize().y - 1.05f * boutonSpriteTmp.getTextureRect().height);
				break;
		}

		listSpritesButtonChoice.push_back(std::pair<std::unique_ptr<sf::Sprite>, std::unique_ptr<sf::Texture>>(std::make_unique<sf::Sprite>(boutonSpriteTmp), std::make_unique<sf::Texture>(boutonTextTmp)));
		listSpritesButtonChoice.back().first->setTexture(*listSpritesButtonChoice.back().second);


		//std::cout << listSpritesButtonChoice[i].first.getPosition().x << "/" << listSpritesButtonChoice[i].first.getPosition().y << "\n";

		boutonTmp.setSprite(boutonSpriteTmp , move(ptrTexture));
		boutonTmp.setText("TEST" , comicFont);

		listButtonsChoices.push_back(boutonTmp);
	}
}

void SceneBoss::chargeButtons(std::vector<Replique*> repliquesChosen)
{
	// On créé les boutons
	for (int i = 0; i < 4; i++)
	{
		//std::cout << listSpritesButtonChoice[i].first.getPosition().x << "/" << listSpritesButtonChoice[i].first.getPosition().y << "\n";
		std::cout << "Copie ";
		assert(comicFont.loadFromFile("Ressources\\ComicSansMS.ttf") == true);
		listButtonsChoices[i].setText(repliquesChosen[i]->text, comicFont);
	}
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
			SceneManager::moveToScene(SceneNames::EXIT,window);
			return;
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
			for (Bouton &button : listButtonsChoices)
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
std::vector<Replique*> SceneBoss::randReplique()
{
	int rand1, rand2, rand3, rand4;
	assert(repliques.size() >= 4);

	//ici on suppose qu'on beaucoup de repliques donc la probabilite de tomber sur une deja choisie est faible.
	//on aurai aussi pu creer un liste de uint et la melanger. Ensuite prendre les 4 premiers elements de la liste (qui correspondront aux indices des repliques choisies)
	rand1 = Random::randInt(0, repliques.size()-1);
	do 
	{
		rand2 = Random::randInt(0, repliques.size()-1);
	} while (rand2 == rand1);

	do 
	{
		rand3 = Random::randInt(0, repliques.size()-1);
	} while (rand3 == rand1 || rand3 == rand2);

	do 
	{
		rand4 = Random::randInt(0, repliques.size()-1);
	} while (rand4 == rand1 || rand4 == rand2 || rand4 == rand3);

	std::vector<Replique*> vec(4);
	vec = { repliques[rand1].get(),repliques[rand2].get(),repliques[rand3].get(),repliques[rand4].get() };
	return vec;
}