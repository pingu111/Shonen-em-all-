#pragma once

#include <SFML/Graphics.hpp>
#include <memory>
#include "WindowManager.h"
#include "VirtualScene.h"


class RythmNBlood : VirtualScene
{

public:
	/* Constructeur */
	RythmNBlood();

	/* Constructeur
	* param : WindowManager windowArg la fenetre d'affichage */
	RythmNBlood(WindowManager& windowArg);

	/* Destructeur */
	~RythmNBlood();
};

