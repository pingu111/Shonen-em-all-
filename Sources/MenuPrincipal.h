#pragma once

#include <SFML/Graphics.hpp>
#include <vector>
#include "WindowManager.h"
#include "VirtualScene.h"

/* L'enum des diffreentes choix que le joueur pourra faire dans cette scene */
enum EnumChoicesUser { QUIT, RYTHM, OPTIONS };

class MenuPrincipal : VirtualScene
{

private:
	std::vector<sf::Sprite>  listSpritesMenu;

public:
	/* Constructeur sans arguments */
	MenuPrincipal();

	/* Constructeur  
	* param : WindowManager windowArg la fenetre d'affichage */
	MenuPrincipal(WindowManager& windowArg);

	/* Fonction qui affiche et dessine le fond et les boutons du menu principal */
	void printBackgroundAndButtons();

	/* Fonction bloquante qui attend un choix du l'utilisateur
		return : le choix de l'utilisateur	*/
	EnumChoicesUser waitForUser();

	/* Destructeur*/
	~MenuPrincipal();
};



