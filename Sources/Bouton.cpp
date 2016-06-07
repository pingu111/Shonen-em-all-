#include <Bouton.h>

Bouton::Bouton()
{
	defaultText();
}

Bouton::Bouton(sf::Sprite spriteToSet)
{
	setSprite(spriteToSet);
	defaultText();
}

void Bouton::setSprite(sf::Sprite spriteToSet)
{
	sprite = spriteToSet;
}

void Bouton::setText(std::string message)
{
	text.setString(message);

	while (text.getLocalBounds().width > sprite.getTextureRect().width
		&& text.getLocalBounds().height > sprite.getTextureRect().height)
	{
		text.setCharacterSize(text.getCharacterSize() - 1);
	}
}

void Bouton::setFont(sf::Font font)
{
	text.setFont(font);
}

sf::Sprite Bouton::getSprite()
{
	return sprite;
}

std::pair<sf::Sprite, sf::Text> Bouton::getSpriteAndMessage()
{
	return std::pair<sf::Sprite, sf::Text>(sprite, text);
}

void Bouton::setPosition(int posX, int posY)
{
	sprite.setPosition((float)posX, (float)posY);
	text.setPosition((float)posX, (float)posY);
}

void Bouton::setOnClick(void(*function)())
{
	// Mouais, à voir
}

bool Bouton::isClicked(sf::Vector2i mousePosition)
{
	//std::cout << "Sprite : " <<sprite.getPosition().x << " / " << sprite.getPosition().y << "\n";
	//std::cout << "Mouse : " << mousePosition.x << " / " << mousePosition.x << "\n";

	if ((int) sprite.getPosition().x < mousePosition.x &&
		(int) (sprite.getPosition().x + sprite.getTextureRect().width) > mousePosition.x &&
		(int) sprite.getPosition().y < mousePosition.y &&
		(int) (sprite.getPosition().y + sprite.getTextureRect().height) > mousePosition.y)
		return true;
	else
		return false;
}


void Bouton::defaultText()
{
	assert(comicFont.loadFromFile("Ressources\\ComicSansMS.ttf") == true);
	text.setFont(comicFont);
	text.setString("");
	text.setCharacterSize(1);
	text.setColor(sf::Color::Red);
	text.setStyle(sf::Text::Bold);
}