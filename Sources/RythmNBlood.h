#pragma once

#include <Global.h>
#include <memory>
#include <VirtualScene.h>
#include <Player.h>
#include <Ennemi.h>

#include <Bouton.h>



class RythmNBlood : VirtualScene
{

private:
	/* La liste d'ennemis */
	std::vector<Ennemi> ennemis;

	//static Player player;

	std::unique_ptr<Bouton> buttonQuit;

	/* Lance la scene : appelé par le consytructeur */
	void launchScene();

	/* Charge les images */
	void initTextures();

	/* Met à jour la scene, les ennemis, ... 
		Est bloquant */
	void waitForUser();

	/* Affiche les images de fond et les boutons initiaux de la scene */
	void printBackgroundAndButtons();


	/* Les sprites et textures pour le background */
	sf::Sprite fondSprite;
	sf::Texture fond;

public:
	/* Constructeur
	* param : WindowManager windowArg la fenetre d'affichage */
	RythmNBlood(WindowManager * windowArg);

	/* Destructeur */
	~RythmNBlood();
};

