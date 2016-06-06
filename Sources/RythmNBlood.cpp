#include <RythmNBlood.h>


Player RythmNBlood::player;

RythmNBlood::RythmNBlood(WindowManager* windowArg)
{
	//ennemis = std::vector<Ennemi>();
	idEnnemi = 0;
	window = windowArg;

	launchScene();
}

RythmNBlood::~RythmNBlood()
{
}

void RythmNBlood::launchScene()
{
	initSprite();
	waitForUser();
}


void RythmNBlood::printBackgroundAndButtons()
{
	// On ajoute tous les sprites qu'on veut afficher 
	window->add(std::make_unique<sf::Sprite>(fondSprite));
}

void RythmNBlood::waitForUser()
{
	std::time_t timeLastAdd = std::time(nullptr);

	while (window->getWindow()->isOpen())
	{
		printBackgroundAndButtons();
		window->add(std::make_unique<sf::Sprite>(playerWaitingSprite.first));
		timeLastAdd = addEnnemies(timeLastAdd);

		std::vector<std::shared_ptr<Ennemi>> ennemiesHittables;
		for (auto &enn : ennemis)
		{
			enn->update();
			if (enn->isHitable())
				ennemiesHittables.push_back(enn);
			if (!enn->isDead())
			{
				mapSpriteEnnemi.at(enn).setPosition(
					 (float)window->getWindow()->getSize().x * enn->getXPosition() / 100 
					- mapSpriteEnnemi.at(enn).getTextureRect().width / 2,
					+ (float)window->getWindow()->getSize().y * 3 / 4 
					- mapSpriteEnnemi.at(enn).getTextureRect().height / 2);
				window->add(std::make_unique<sf::Sprite>(mapSpriteEnnemi.at(enn)));
			}
		}

		sf::Event event;
		while (window->getWindow()->pollEvent(event))
		{
			if (event.type == sf::Event::Closed )
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
			else if (event.key.code == sf::Keyboard::Left)
			{
				for (auto &enn : ennemiesHittables)
				{
					player.hit(true, *enn);
				}
			}
			else if (event.key.code == sf::Keyboard::Right)
			{
				for (auto &enn : ennemiesHittables)
				{
					player.hit(false, *enn);
				}
			}
			else if (sf::Mouse::isButtonPressed(sf::Mouse::Left))
			{
				//On parcours les boutons et on verifie s'ils sont cliqués
			}
		}
		window->draw();

	}
}

void RythmNBlood::initSprite()
{

	assert(fond.loadFromFile("Ressources\\RNB\\Fond.png") == true);
	fondSprite.setTexture(fond);

	for (int i = 0; i < 18; i++)
	{
		sf::Image image;
		sf::Texture texture;
		sf::Sprite sprite;

		std::string placeFile = "Ressources\\RNB\\PlayerTape\\frame_";
		placeFile += std::to_string(i);
		placeFile += "_delay-0.03s.gif";

		assert(image.loadFromFile(placeFile) == true);
		image.createMaskFromColor(sf::Color(0,255,0));
		
		texture.loadFromImage(image);
		sprite.setTexture(texture);

		sprite.setPosition( (float)window->getWindow()->getSize().x * playerPosition / 100 - sprite.getTextureRect().width / 2,
										+ (float)window->getWindow()->getSize().y * 3 / 4 - sprite.getTextureRect().height / 2);

		
		listSpritePlayerHitting.push_back(std::pair<sf::Sprite, std::unique_ptr<sf::Texture>>(sprite, std::make_unique<sf::Texture>(texture)));
		listSpritePlayerHitting.back().first.setTexture(*listSpritePlayerHitting.back().second);
		
		if (i == 1)
		{
			playerWaitingSprite = (std::pair<sf::Sprite, std::unique_ptr<sf::Texture>>(sprite, std::make_unique<sf::Texture>(texture)));
			playerWaitingSprite.first.setTexture(*playerWaitingSprite.second);
		}
	}

	for (int i = 0; i < 13; i++)
	{
		sf::Image image;
		sf::Texture texture;
		sf::Sprite sprite;

		std::string placeFile = "Ressources\\RNB\\EnnemiCours\\frame_";
		placeFile += std::to_string(i);
		placeFile += "_delay-0.03s.gif";

		assert(image.loadFromFile(placeFile) == true);
		image.createMaskFromColor(sf::Color::Green);
		texture.loadFromImage(image);

		listSpriteEnnemyMoving.push_back(std::pair<sf::Sprite, std::unique_ptr<sf::Texture>>(sprite, std::make_unique<sf::Texture>(texture)));
		listSpriteEnnemyMoving.back().first.setTexture(*listSpriteEnnemyMoving.back().second);
	}

}

std::time_t RythmNBlood::addEnnemies(std::time_t timeLastAdd)
{
	//std::cout << " addEnnemies "<< timeLastAdd << " vs "<< std::time(nullptr) << "\n";
	if (std::time(nullptr) - timeLastAdd > 1)
	{
		timeLastAdd = std::time(nullptr);

		Ennemi newEnnemi(timeLastAdd % 2 == 1, ++idEnnemi);
		newEnnemi.initSpeed((float)ennemiSpeed);
		std::shared_ptr<Ennemi> newEnn = std::make_shared<Ennemi>(newEnnemi);
		
		mapSpriteEnnemi.insert(std::pair<std::shared_ptr<Ennemi>, sf::Sprite>
							(newEnn, listSpriteEnnemyMoving[0].first));
		ennemis.push_back(newEnn);
	}
	return timeLastAdd;
}
