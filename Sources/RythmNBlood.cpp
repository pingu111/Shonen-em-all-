#include <RythmNBlood.h>


RythmNBlood::RythmNBlood() : player(Player::Instance(), 0)
{
	initSprite();
	initFonts();
}

//RythmNBlood RythmNBlood::m_instance = RythmNBlood();


RythmNBlood& RythmNBlood::Instance()
{
	static RythmNBlood m_instance;
	return m_instance;
}

RythmNBlood::~RythmNBlood()
{

}

void RythmNBlood::launchScene()
{
	//on recupere les infos du level en cours (nombre d'ennemis, points de vie, armure ...)
	//TODO
	printBackground();

	idEnnemi = 0;
	isPlayerInHitAnimation = false;
	isLastHitLeft = false;
	nbEnnemiDead = 0;

	waitForUser();
}

void RythmNBlood::printBackground()
{
	// On ajoute tous les sprites qu'on veut afficher 
	WindowManager::Instance().add(std::make_unique<sf::Sprite>(fondSprite));
}

void RythmNBlood::waitForUser()
{
	std::time_t timeLastAdd = std::time(nullptr);
	std::time_t timeLastTouched = std::time(nullptr);

	while (WindowManager::Instance().getWindow()->isOpen() )
	{
		if (player.first.isDead())
		{
			WindowManager::Instance().clearText();
			WindowManager::Instance().draw();
			SceneManager::moveToScene(SceneNames::DEFEAT);
			return;
		}
		printBackground();

		animationPlayer();

		timeLastAdd = addEnnemies(timeLastAdd);
		std::cout << "nb morts : " << nbEnnemiDead << " / "<< nbEnnemiesMax <<"\n";

		if (nbEnnemiDead < nbEnnemiesMax)
		{
			// Parcours des listes d'ennemis en vie ou morts
			listDeadAlive();

			std::vector<std::shared_ptr<Ennemi>> ennemiesHittables = animationsEnnemies();

			// On gere les evenements et leurs consequences
			ennemiesHittables = eventManager(ennemiesHittables);

			WindowManager::Instance().draw();
		}
		else
		{
			// Alors, fin de la scene
			WindowManager::Instance().clearText();
			WindowManager::Instance().draw();

			SceneManager::moveToScene(SceneNames::VILAIN);
			return;
		}
	}
}

void RythmNBlood::initSprite()
{

	assert(fond.loadFromFile("Ressources\\RNB\\Fond.png") == true);
	fondSprite.setTexture(fond);

	for (int i = 0; i < 18; i++)
	{
		// On charge les images du joueur qui tape 
		sf::Image image;
		sf::Texture texture;
		sf::Sprite sprite;

		std::string placeFile = "Ressources\\RNB\\PlayerTape\\frame_";
		placeFile += std::to_string(i);
		placeFile += "_delay-0.03s.gif";

		assert(image.loadFromFile(placeFile) == true);
		//image.createMaskFromColor(sf::Color(0,255,0));
		
		texture.loadFromImage(image);
		sprite.setTexture(texture);

		sprite.setPosition((float)WindowManager::Instance().getWindow()->getSize().x * playerPosition / 100
							- (float)sprite.getTextureRect().width / 2,
							(float)WindowManager::Instance().getWindow()->getSize().y *0.715f
							- (float)sprite.getTextureRect().height / 2);

		// On les stocke
		for (int i = 0; i < 2; i++)
		{
			listSpritePlayerHitting.push_back(std::pair<sf::Sprite, std::unique_ptr<sf::Texture>>(sprite, std::make_unique<sf::Texture>(texture)));
			listSpritePlayerHitting.back().first.setTexture(*listSpritePlayerHitting.back().second);
		}
		

		if (i == 1)
		{
			// On stocke l'image du joueur qui attend
			playerWaitingSprite = (std::pair<sf::Sprite, std::unique_ptr<sf::Texture>>(sprite, std::make_unique<sf::Texture>(texture)));
			playerWaitingSprite.first.setTexture(*playerWaitingSprite.second);
		}
	}

	for (int i = 0; i < 13; i++)
	{
		// On charge les images des ennemis qui courent
		sf::Image image;
		sf::Texture texture;
		sf::Sprite sprite;

		std::string placeFile = "Ressources\\RNB\\EnnemiCours\\frame_";
		placeFile += std::to_string(i);
		placeFile += "_delay-0.03s.gif";

		assert(image.loadFromFile(placeFile) == true);
		//image.createMaskFromColor(sf::Color::Green);
		texture.loadFromImage(image);
		
		// On les stocke
		for (int i = 0; i < 5; i++)
		{
			listSpriteEnnemyMoving.push_back(std::pair<sf::Sprite, std::unique_ptr<sf::Texture>>(sprite, std::make_unique<sf::Texture>(texture)));
			listSpriteEnnemyMoving.back().first.setTexture(*listSpriteEnnemyMoving.back().second);
		}
	}

	for (int i = 0; i < 13; i++)
	{
		// On charge les images des super ennemis qui courent
		sf::Image image;
		sf::Texture texture;
		sf::Sprite sprite;

		std::string placeFile = "Ressources\\RNB\\SuperEnnemiCours\\frame_";
		placeFile += std::to_string(i);
		placeFile += "_delay-0.03s.gif";

		assert(image.loadFromFile(placeFile) == true);
		//image.createMaskFromColor(sf::Color::Green);
		texture.loadFromImage(image);

		// On les stocke
		for (int i = 0; i < 5; i++)
		{
			listSpriteSuperMoving.push_back(std::pair<sf::Sprite, std::unique_ptr<sf::Texture>>(sprite, std::make_unique<sf::Texture>(texture)));
			listSpriteSuperMoving.back().first.setTexture(*listSpriteSuperMoving.back().second);
		}
	}


}

void RythmNBlood::initFonts()
{
	assert(comicFont.loadFromFile("Ressources\\ComicSansMS.ttf") == true);

	textDamages.setFont(comicFont);
	textDamages.setString("");
	textDamages.setCharacterSize(24);
	textDamages.setColor(sf::Color::Red);
	textDamages.setStyle(sf::Text::Bold);
	textDamages.setPosition(
		(float)WindowManager::Instance().getWindow()->getSize().x/2
		- textDamages.getLocalBounds().width / 2,
		(float)WindowManager::Instance().getWindow()->getSize().y/4
		- textDamages.getLocalBounds().height / 2);

	textReplique.setFont(comicFont);
	textReplique.setString("");
	textReplique.setCharacterSize(24);
	textReplique.setColor(sf::Color::White);
	textReplique.setStyle(sf::Text::Bold);
	textReplique.setPosition(
		(float)WindowManager::Instance().getWindow()->getSize().x / 2
		- textDamages.getLocalBounds().width / 2,
		(float)WindowManager::Instance().getWindow()->getSize().y / 4
		- textDamages.getLocalBounds().height / 2);
}

std::time_t RythmNBlood::addEnnemies(std::time_t timeLastAdd)
{
	if (idEnnemi <= nbEnnemiesMax)
	{
		//std::cout << "add ennemi " << nbEnnemiesMax <<  "/" << idEnnemi << "\n";

		//std::cout << " addEnnemies "<< timeLastAdd << " vs "<< std::time(nullptr) << "\n";
		if (std::time(nullptr) - timeLastAdd > durationBetweenEnnemies)
		{
			timeLastAdd = std::time(nullptr);

			// Cree un ennemi
			Ennemi newEnnemi(Random::randInt(0, 1) == 1, ++idEnnemi);
			newEnnemi.initSpeed((float)ennemiSpeed);

			if (Random::randFloat(0, 1) <= probaSuperEnnemi)
			{
				std::cout << "SUPER \n";
				newEnnemi.makeSuper();
			}

			std::shared_ptr<Ennemi> newEnn = std::make_shared<Ennemi>(newEnnemi);

			// Cree son sprite
			int nbSprite = Random::randInt(0, 10);
			sf::Sprite spriteNewEnnemi;
			
			if (!newEnn->getIsSuper())
			{
				spriteNewEnnemi = listSpriteEnnemyMoving[nbSprite].first;
			}
			else
			{
				spriteNewEnnemi = listSpriteSuperMoving[nbSprite].first;
			}


			if (!newEnnemi.getIsLeft())
			{
				spriteNewEnnemi = flipSprite(spriteNewEnnemi);
			}
			std::pair<int, sf::Sprite> pair(nbSprite, spriteNewEnnemi);

			mapSpriteEnnemi.insert(std::pair<std::shared_ptr<Ennemi>, std::pair<int, sf::Sprite>>
				(newEnn, pair));

			ennemisAlive.push_back(newEnn);
		}
	}
	return timeLastAdd;
}

sf::Sprite RythmNBlood::flipSprite(sf::Sprite spriteToFlip)
{
	spriteToFlip.setOrigin({ spriteToFlip.getLocalBounds().width, 0 });
	spriteToFlip.scale(-1.f, 1.f);
	return spriteToFlip;
}

std::vector<std::shared_ptr<Ennemi>> RythmNBlood::animationsEnnemies()
{

	std::vector<std::shared_ptr<Ennemi>> ennemiesHittables;
	for (auto &enn : ennemisAlive)
	{
		if (enn->update())
		{
			enn->suicide();
			nbEnnemiDead++;

			ennemisDead.push_back(enn);
			player.first.takeHit();
		}
		else
		{
			if (enn->isHitable())
				ennemiesHittables.push_back(enn);

			// On change le sprite de l'ennemi 
			if (!enn->getIsSuper())
			{
				if (mapSpriteEnnemi.at(enn).first + 1 < (int)listSpriteEnnemyMoving.size())
					mapSpriteEnnemi.at(enn).first++;
				else
					mapSpriteEnnemi.at(enn).first = 0;

				mapSpriteEnnemi.at(enn).second = listSpriteEnnemyMoving[mapSpriteEnnemi.at(enn).first].first;
			}
			else
			{
				if (mapSpriteEnnemi.at(enn).first + 1 < (int)listSpriteSuperMoving.size())
					mapSpriteEnnemi.at(enn).first++;
				else
					mapSpriteEnnemi.at(enn).first = 0;

				mapSpriteEnnemi.at(enn).second = listSpriteSuperMoving[mapSpriteEnnemi.at(enn).first].first;
			}


			// On retourne les sprites si necessaire
			if (!enn->getIsLeft())
			{
				mapSpriteEnnemi.at(enn).second = flipSprite(mapSpriteEnnemi.at(enn).second);
			}

			// On le deplace
			mapSpriteEnnemi.at(enn).second.setPosition(
				(float)WindowManager::Instance().getWindow()->getSize().x * enn->getXPosition() / 100
				- mapSpriteEnnemi.at(enn).second.getTextureRect().width / 2,
				(float)WindowManager::Instance().getWindow()->getSize().y * 3 / 4
				- mapSpriteEnnemi.at(enn).second.getTextureRect().height / 2);

			WindowManager::Instance().add(std::make_unique<sf::Sprite>(mapSpriteEnnemi.at(enn).second));
		}

	}
	return ennemiesHittables;
}

void RythmNBlood::listDeadAlive()
{
	std::vector<int> listEnnemiesDeadPosition;
	for (int i = 0; i < (int)ennemisAlive.size(); i++)
	{
		if (ennemisAlive[i]->isDead())
		{
			ennemisDead.push_back(ennemisAlive[i]);
			listEnnemiesDeadPosition.push_back(i);
		}
	}
	for (int i = listEnnemiesDeadPosition.size() - 1; i >= 0; i--)
	{
		ennemisAlive.erase(ennemisAlive.begin() + listEnnemiesDeadPosition[i]);
	}

}

std::vector<std::shared_ptr<Ennemi>> RythmNBlood::eventManager(std::vector<std::shared_ptr<Ennemi>> ennemiesHittables)
{
	sf::Event event;
	int damages = 0;
	while (WindowManager::Instance().getWindow()->pollEvent(event))
	{
		if (event.type == sf::Event::Closed)
		{
			//TODO QUITTER PROPREMENT 
		}
		else if (event.type == sf::Event::KeyPressed)
		{
			if (event.key.code == sf::Keyboard::Escape)
			{
				std::cout << " sf::Keyboard::Escape\n";
			}
		}
		else if (event.key.code == sf::Keyboard::Left && !isPlayerInHitAnimation)
		{
			// taper !
			isPlayerInHitAnimation = true;
			isLastHitLeft = true;
			for (auto &enn : ennemiesHittables)
			{
				if (enn->getIsLeft())
				{
					damages = player.first.hit(*enn);
					printText(damages);
					if(enn->isDead())
						nbEnnemiDead++;

				}
			}
		}
		else if (event.key.code == sf::Keyboard::Right && !isPlayerInHitAnimation)
		{
			// taper !
			isPlayerInHitAnimation = true;
			isLastHitLeft = false;
			for (auto &enn : ennemiesHittables)
			{
				if (!enn->getIsLeft())
				{
					damages = player.first.hit(*enn);
					printText(damages);
					if (enn->isDead())
						nbEnnemiDead++;
				}
			}
		}
		else if (sf::Mouse::isButtonPressed(sf::Mouse::Left) && !isPlayerInHitAnimation)
		{
			//playerHittingAnimation = true;

			//On parcours les boutons et on verifie s'ils sont cliqués
		}
	}

	return ennemiesHittables;
}

void RythmNBlood::animationPlayer()
{
	// On gere l'animation du joueur
	if (isPlayerInHitAnimation)
	{
		if (player.second + 1 < (int)listSpritePlayerHitting.size())
		{
			player.second++;
		}
		else
		{
			player.second = 0;
			isPlayerInHitAnimation = false;
		}
		if (!isLastHitLeft)
			WindowManager::Instance().add(std::make_unique<sf::Sprite>(flipSprite(listSpritePlayerHitting[player.second].first)));
		else
			WindowManager::Instance().add(std::make_unique<sf::Sprite>(listSpritePlayerHitting[player.second].first));
	}
	else
	{
		if (!isLastHitLeft)
		{
			WindowManager::Instance().add(std::make_unique<sf::Sprite>(flipSprite(playerWaitingSprite.first)));
		}
		else
		{
			WindowManager::Instance().add(std::make_unique<sf::Sprite>(playerWaitingSprite.first));
		}
	}
}

void RythmNBlood::printText(int hitValue)
{
	if (hitValue >= 0)
	{
		textDamages.setPosition(
			(float)WindowManager::Instance().getWindow()->getSize().x * Random::randInt(3,7)/10
			- textDamages.getLocalBounds().height / 2,
			(float)WindowManager::Instance().getWindow()->getSize().y * Random::randInt(3, 7)/10
			- textDamages.getLocalBounds().height / 2);

		char stringDamage[250];
		sprintf_s(stringDamage, "%d", hitValue);
		strcat_s(stringDamage, " dommages !");
		textDamages.setString(stringDamage);
		WindowManager::Instance().addWithPeremption(std::make_unique<sf::Text>(textDamages), (int)std::time(nullptr));
	}
	else
	{
		if (textDamages.getString() != "")
		{
			textDamages.setString("");
			WindowManager::Instance().addWithPeremption(std::make_unique<sf::Text>(textDamages), (int)std::time(nullptr));
		}
	}
}

void RythmNBlood::printReplique(std::string repliqueText)
{
	textReplique.setPosition(
		(float)WindowManager::Instance().getWindow()->getSize().x / 2
		- textDamages.getLocalBounds().width / 2,
		(float)WindowManager::Instance().getWindow()->getSize().y / 3
		- textDamages.getLocalBounds().height / 2);

	textDamages.setString(repliqueText);
	WindowManager::Instance().addWithPeremption(std::make_unique<sf::Text>(textDamages), (int)std::time(nullptr));
}


void RythmNBlood::reload()
{
	if (player.first.getHasSomethingToSay())
	{
		std::string repliqueText = player.first.sayReplique();
		printReplique(repliqueText);
	}
	Level lv = LevelManager::nextLevel();

	durationBetweenEnnemies = lv.cooldown;
	nbEnnemiesMax = lv.ennemiNumber;
	ennemiSpeed = lv.ennemiSpeed;
	probaSuperEnnemi = lv.probaSuper;

	std::cout << "nb : " << nbEnnemiesMax << "\n";
	launchScene();
}

