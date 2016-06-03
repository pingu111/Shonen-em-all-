#pragma once

#include <SFML/Graphics.hpp>
#include <memory>
#include "WindowManager.h"

class VirtualScene
{

protected:
	/* La fenetre d'affichage */
	std::unique_ptr<WindowManager> window;

public:
	VirtualScene();
	~VirtualScene();
};

