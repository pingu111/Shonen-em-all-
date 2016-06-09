#pragma once

#include <SFML\Graphics.hpp>
#include <iostream>
#include <assert.h>
#include <memory>


class Bouton
{

private:
	/* Le sprite du bouton */
	std::pair<sf::Sprite, std::unique_ptr<sf::Texture>> spriteTexture;

	/* Le texte du bouton ,s'il yen a un */
	std::pair<sf::Text, sf::Font> textFont;


	sf::Font font;

	/* La police par defaut */
	sf::Font comicFont;

public:

	Bouton();
	/* Constructeur : sette le sprite du bouton */
	Bouton(sf::Sprite spriteToSet, std::unique_ptr<sf::Texture> textureToSet);

	/* Constructeur de copie */
	Bouton(const Bouton &buttonCopy);


	/* Change le sprite du bouton */
	void setSprite(sf::Sprite spriteToSet, std::unique_ptr<sf::Texture> textureToSet);

	/* Change la position du sprite du bouton */
	void setPosition(int posX, int posY);

	void setText(std::string message, sf::Font font);

	void setFont(sf::Font font);

	void defaultText();

	void setText(std::string message, sf::Font font, int sizeCharac);


	/* Ajoute un fonction qui sera appelée lordqu'on clique sur le bouton */
	void setOnClick(void(*function)());

	/* Renvoie le sprite du bouton */
	sf::Sprite getSprite();

	/* Renvoie true si le bouton est cliqué, false sinon  */
	bool isClicked(sf::Vector2i mousePosition);

	/* Renvoie le sprite et le message */
	std::pair< std::unique_ptr<sf::Sprite>, std::unique_ptr<sf::Text>> getSpriteAndMessage();
};