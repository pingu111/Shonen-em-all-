#pragma once
#include <SFML/Graphics.hpp>

class DrawableVirtual
{
public:
	DrawableVirtual();
	~DrawableVirtual();
	virtual void addToDraw(sf::RenderWindow &window) = 0;

};

