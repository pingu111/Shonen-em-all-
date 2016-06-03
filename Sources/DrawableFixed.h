#pragma once

#include "DrawableVirtual.h"

class DrawableFixed : DrawableVirtual
{
public:
	DrawableFixed();
	~DrawableFixed();

protected:
	sf::RectangleShape shape;

};

