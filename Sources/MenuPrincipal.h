#pragma once

#include <SceneManager.h>
#include <vector>
#include <iostream>
#include <assert.h>
#include <VirtualScene.h>
#include <Bouton.h>



class MenuPrincipal : VirtualScene
{

private:
	sf::Texture boutonGoToRNB;
	sf::Sprite boutonGoToRNBSprite;

	Bouton boutonRNB;

	void initTextures();

	MenuPrincipal();
	static MenuPrincipal m_instance;

public:
	static MenuPrincipal& Instance(WindowManager* windowArg);

	/* Fonction qui affiche et dessine le fond et les boutons du menu principal */
	void printBackgroundAndButtons();

	/* Fonction bloquante qui attend un choix du l'utilisateur
		return : le choix de l'utilisateur	*/
	EnumChoicesUser waitForUser();

	void reload() override;

	

	/* Destructeur*/
	~MenuPrincipal();
};



