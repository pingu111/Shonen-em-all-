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

	/* Dessine la liste des sprites de listSprites */
	void draw();

private:
	/* La RenderWindow d'affichage pour tout le programme */
	sf::RenderWindow window;

	/* La liste des sprites qu'on dessinera */
	std::vector<std::unique_ptr<sf::Sprite>> listSprites;
};

