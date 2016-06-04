#include "Bouton.h"

Bouton::Bouton()
{
	;
}

Bouton::Bouton(sf::Sprite spriteToSet)
{
	sprite = spriteToSet;
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
	sprite.setPosition(posX, posY);
}

void Bouton::setOnClick(void(*function)())
{
	// Mouais, à voir
}

bool Bouton::isClicked(sf::Vector2i mousePosition)
{
	//std::cout << "Sprite : " <<sprite.getPosition().x << " / " << sprite.getPosition().y << "\n";
	//std::cout << "Mouse : " << mousePosition.x << " / " << mousePosition.x << "\n";

	if (sprite.getPosition().x < mousePosition.x &&
		sprite.getPosition().x + sprite.getTextureRect().width > mousePosition.x &&
		sprite.getPosition().y < mousePosition.y &&
		sprite.getPosition().y + sprite.getTextureRect().height > mousePosition.y)
		return true;
	else
		return false;
}
