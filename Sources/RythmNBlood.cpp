#include "RythmNBlood.h"

RythmNBlood::RythmNBlood(WindowManager* windowArg)
{
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
	while (true)
	{
		updateScene();

	}
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

void RythmNBlood::updateScene()
{
	for (Ennemi enn : ennemis)
		enn.update();
}
