#pragma once

#include <SFML\Graphics.hpp>

class Bouton
{

private:
	sf::Sprite sprite;
	sf::Vector2i position;
public:
	Bouton();

	void setSprite(sf::Sprite spriteToSet);
	void setPosition(int posX, int posY);
	sf::Vector2i getPosition();

	void setOnClick(void(*function)());
	sf::Sprite getSprite();

	bool isClicked(sf::Vector2i mousePosition);

};