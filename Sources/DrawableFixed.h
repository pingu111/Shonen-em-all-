#pragma once

#include "DrawableVirtual.h"

//unused
class DrawableFixed : DrawableVirtual
{
public:
	DrawableFixed();
	~DrawableFixed();

protected:
	sf::RectangleShape shape;

};

