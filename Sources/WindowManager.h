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

	/* Renvoie un unique pointer */
	std::unique_ptr<WindowManager> clone();

private:
	/* La RenderWindow d'affichage pour tout le programme */
	sf::RenderWindow window;
};

