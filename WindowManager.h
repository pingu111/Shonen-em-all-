#pragma once


#include <SFML/Graphics.hpp>


class WindowManager
{
public:
	/* Constructeur : cr�� la RenderWindow */
	WindowManager();

	/* Destructeur*/
	~WindowManager();

	/* Retourne la RenderWinow* */
	sf::RenderWindow* getWindow();

private:
	/* La RenderWindow d'affichage pour tout le programme */
	sf::RenderWindow window;
};

