#pragma once
#include <SFML/Graphics.hpp>

class DrawableVirtual
{
public:
	DrawableVirtual();
	~DrawableVirtual();
	/* ajoute l'objet a la liste des objets a afficher */
	virtual void addToDraw(sf::RenderWindow &window) = 0;

};

