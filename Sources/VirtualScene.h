#pragma once

#include <SFML/Graphics.hpp>
#include <memory>
#include "WindowManager.h"

/* L'enum des diffreentes choix que le joueur pourra faire */
enum EnumChoicesUser { QUIT, RYTHM, OPTIONS };

class VirtualScene
{

protected:
	/* La fenetre d'affichage */
	WindowManager* window;

	/* Les sprites et textures pour le background */
	sf::Sprite fondSprite;
	sf::Texture fond;

public:
	VirtualScene();
	~VirtualScene();
};

