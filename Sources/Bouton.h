#pragma once

#include <SFML\Graphics.hpp>
#include <iostream>

class Bouton
{

private:
	/* Le sprite du bouton */
	sf::Sprite sprite;

public:

	Bouton();
	/* Constructeur : sette le sprite du bouton */
	Bouton(sf::Sprite spriteToSet);

	/* Change le sprite du bouton */
	void setSprite(sf::Sprite spriteToSet);

	/* Change la position du sprite du bouton */
	void setPosition(int posX, int posY);

	/* Ajoute un fonction qui sera appelée lordqu'on clique sur le bouton */
	void setOnClick(void(*function)());

	/* Renvoie le sprite du bouton */
	sf::Sprite getSprite();

	/* Renvoie true si le bouton est cliqué, false sinon  */
	bool isClicked(sf::Vector2i mousePosition);

};