#pragma once


#include <SFML/Graphics.hpp>
#include <memory>


class WindowManager
{


public:
	/* Constructeur : créé la RenderWindow */
	WindowManager();

	/* Destructeur*/
	~WindowManager();

	/* Retourne la RenderWinow* */
	sf::RenderWindow* getWindow();

	/* Ajoute l'argument dans le vector des sprites qu'on dessinera */
	void add(std::unique_ptr<sf::Sprite> form);

	/* Ajoute l'argument dans le vector des textes qu'on dessinera */
	void add(std::unique_ptr<sf::Text> form);

	/* Dessine la liste des sprites de listSprites 
	 Et vide la liste des sprites à dessiner */
	void draw();

private:
	/* La RenderWindow d'affichage pour tout le programme */
	sf::RenderWindow window;

	/* La liste des sprites qu'on dessinera */
	std::vector<std::unique_ptr<sf::Sprite>> listSprites;

	/* La liste des textes qu'on dessinera */
	std::vector<std::unique_ptr<sf::Text>> listText;
};

