#pragma once

#include <SFML\Graphics.hpp>
#include <iostream>
#include <assert.h>


class Bouton
{

private:
	/* Le sprite du bouton */
	sf::Sprite sprite;

	/* Le texte du bouton ,s'il yen a un */
	sf::Text text;

	sf::Font font;

	/* La police par defaut */
	sf::Font comicFont;

public:

	Bouton();
	/* Constructeur : sette le sprite du bouton */
	Bouton(sf::Sprite spriteToSet);

	/* Change le sprite du bouton */
	void setSprite(sf::Sprite spriteToSet);

	/* Change la position du sprite du bouton */
	void setPosition(int posX, int posY);

	void setText(std::string message);

	void setFont(sf::Font font);

	void defaultText();


	/* Ajoute un fonction qui sera appelée lordqu'on clique sur le bouton */
	void setOnClick(void(*function)());

	/* Renvoie le sprite du bouton */
	sf::Sprite getSprite();

	/* Renvoie true si le bouton est cliqué, false sinon  */
	bool isClicked(sf::Vector2i mousePosition);

	/* Renvoie le sprite et le message */
	std::pair<sf::Sprite, sf::Text> getSpriteAndMessage();


};