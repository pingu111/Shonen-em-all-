#include "Bouton.h"

Bouton::Bouton()
{

}

void Bouton::setSprite(sf::Sprite spriteToSet)
{
	sprite = spriteToSet;
}

sf::Sprite Bouton::getSprite()
{
	return sprite;
}

void Bouton::setPosition(int posX, int posY)
{
	position.x = posX;
	position.y= posY;
}

void Bouton::setOnClick(void(*function)())
{
	// Mouais, à voir
}

bool Bouton::isClicked(sf::Vector2i mousePosition)
{
	if (position.x < mousePosition.x &&
		position.x + sprite.getTextureRect().width > mousePosition.x &&
		position.y < mousePosition.y &&
		position.y + sprite.getTextureRect().height > mousePosition.y)
		return true;
	else
		return false;
}
