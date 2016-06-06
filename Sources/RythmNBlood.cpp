#include <RythmNBlood.h>


Player RythmNBlood::player;

RythmNBlood::RythmNBlood(WindowManager* windowArg)
{
	//ennemis = std::vector<Ennemi>();
	window = windowArg;
	launchScene();
	player = Player();
	initSprite();
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

void RythmNBlood::initSprite()
{
	for (int i = 1; i < 19; i++)
	{
		sf::Texture texture;
		sf::Sprite sprite;
		std::string placeFile = "Ressources\\RNB\\EnnemiCours\\PlayerTape\\Tape (";
		placeFile += std::to_string(i);
		placeFile += ").png";

		assert(texture.loadFromFile(placeFile) == true);
		sprite.setTexture(texture);

		sprite.setPosition((float)window->getWindow()->getSize().x * player.getXPosition() / 100,
						   (float)window->getWindow()->getSize().y * 3 / 4);

		listSpritePlayerHitting.push_back(sprite);
		if (i == 1)
			playerWaitingSprite = sprite;
	}

	for (int i = 1; i < 14; i++)
	{
		sf::Texture texture;
		sf::Sprite sprite;
		std::string placeFile = "Ressources\\RNB\\EnnemiCours\\EnnemiCours (";
		placeFile += std::to_string(i);
		placeFile += ").png";

		assert(texture.loadFromFile(placeFile) == true);
		sprite.setTexture(texture);
		listSpriteEnnemyMoving.push_back(sprite);
	}

}
