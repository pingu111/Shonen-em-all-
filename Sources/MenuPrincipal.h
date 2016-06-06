#pragma once

#include <SceneManager.h>
#include <vector>
#include <iostream>
#include <assert.h>
#include <VirtualScene.h>
#include <Bouton.h>

/* L'enum des diffreentes choix que le joueur pourra faire dans cette scene */
enum EnumChoicesUser { QUIT, RYTHM, OPTIONS };

class MenuPrincipal : VirtualScene
{

private:
	sf::Texture fond;
	sf::Texture boutonGoToRNB;

	sf::Sprite fondSprite;
	sf::Sprite boutonGoToRNBSprite;

	std::unique_ptr<Bouton> boutonRNB;

	void initTextures();

public:
	/* Constructeur sans arguments */
	MenuPrincipal();

	/* Constructeur  
	* param : WindowManager windowArg la fenetre d'affichage */
	MenuPrincipal(WindowManager* windowArg);

	/* Fonction qui affiche et dessine le fond et les boutons du menu principal */
	void printBackgroundAndButtons();

	/* Fonction bloquante qui attend un choix du l'utilisateur
		return : le choix de l'utilisateur	*/
	EnumChoicesUser waitForUser();

	

	/* Destructeur*/
	~MenuPrincipal();
};



