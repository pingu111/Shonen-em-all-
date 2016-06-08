#include <Bouton.h>

Bouton::Bouton()
{

}

Bouton::Bouton(const Bouton &buttonCopy)
{
	setSprite(buttonCopy.spriteTexture.first, std::make_unique<sf::Texture>(*buttonCopy.spriteTexture.second));
	setText(buttonCopy.textFont.first.getString(), buttonCopy.textFont.second);

}

Bouton::Bouton(sf::Sprite spriteToSet, std::unique_ptr<sf::Texture> textureToSet)
{
	setSprite(spriteToSet , move(textureToSet));
}

void Bouton::setSprite(sf::Sprite spriteToSet , std::unique_ptr<sf::Texture> textureToSet)
{
	spriteTexture.first = spriteToSet;
	spriteTexture.second = move(textureToSet);
	spriteTexture.first.setTexture(*spriteTexture.second);
}

void Bouton::setText(std::string message , sf::Font font)
{
	textFont.second = font;
	textFont.first.setFont(textFont.second);
	textFont.first.setString(message);
	std::cout << "Texte = " << message << "\n";

	// Si on depasse le sprite, on diminue la taille
	while (textFont.first.getLocalBounds().width > spriteTexture.first.getTextureRect().width
		&& textFont.first.getLocalBounds().height >  spriteTexture.first.getTextureRect().height)
	{
		textFont.first.setCharacterSize(textFont.first.getCharacterSize() - 1);
	}
}

void Bouton::setFont(sf::Font font)
{
	textFont.first.setFont(font);
}

sf::Sprite Bouton::getSprite()
{
	return spriteTexture.first;
}

std::pair<std::unique_ptr<sf::Sprite>, std::unique_ptr<sf::Text>> Bouton::getSpriteAndMessage()
{
	return std::pair<std::unique_ptr<sf::Sprite>, std::unique_ptr<sf::Text>>
		(std::make_unique<sf::Sprite>(spriteTexture.first), std::make_unique<sf::Text>(textFont.first));
}

void Bouton::setPosition(int posX, int posY)
{
	spriteTexture.first.setPosition((float)posX, (float)posY);
	textFont.first.setPosition((float)posX, (float)posY);
}

void Bouton::setOnClick(void(*function)())
{
	// Mouais, à voir
}

bool Bouton::isClicked(sf::Vector2i mousePosition)
{
	//std::cout << "Sprite : " <<sprite.getPosition().x << " / " << sprite.getPosition().y << "\n";
	//std::cout << "Mouse : " << mousePosition.x << " / " << mousePosition.x << "\n";

	if ((int)spriteTexture.first.getPosition().x < mousePosition.x &&
		(int) (spriteTexture.first.getPosition().x + spriteTexture.first.getTextureRect().width) > mousePosition.x &&
		(int)spriteTexture.first.getPosition().y < mousePosition.y &&
		(int) (spriteTexture.first.getPosition().y + spriteTexture.first.getTextureRect().height) > mousePosition.y)
		return true;
	else
		return false;
}


void Bouton::defaultText()
{
	assert(comicFont.loadFromFile("Ressources\\ComicSansMS.ttf") == true);
	textFont.second = (comicFont);

	textFont.first.setFont(textFont.second);

	textFont.first.setString("");
	textFont.first.setCharacterSize(5);
	textFont.first.setColor(sf::Color::Red);
	textFont.first.setStyle(sf::Text::Bold);
}