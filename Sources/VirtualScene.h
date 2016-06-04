#pragma once

#include <SFML/Graphics.hpp>
#include <memory>
#include "WindowManager.h"

class VirtualScene
{

protected:
	/* La fenetre d'affichage */
	WindowManager* window;

public:
	VirtualScene();
	~VirtualScene();
};

