#pragma once

#include <SFML/Graphics.hpp>
#include "WindowManager.h"

class MenuPrincipal
{

private:
	sf::RenderWindow window;

public:
	MenuPrincipal();
	MenuPrincipal(WindowManager& windowArg);

	~MenuPrincipal();
};

