#pragma once

#include <SFML/Graphics.hpp>
#include <memory>
#include <WindowManager.h>
#include <Global.h>

/* L'enum des diffreentes choix que le joueur pourra faire */
enum EnumChoicesUser { QUIT, RYTHM, OPTIONS };

class VirtualScene
{

protected:

	/* Les sprites et textures pour le background */
	sf::Sprite fondSprite;
	sf::Texture fond;

	SceneNames nameActualScene;


	/* La meilleure police au monde */
	sf::Font comicFont;

	void initFonts();


public:
	/* lance a chaque debut de scene. Permet de mettre de place les constantes et de reinitialiser la scene */
	virtual void reload() = 0;
	/* lance la scene, initialise les textures et lance la boucle d'evenements */
	virtual void launchScene() = 0;
	/* affiche l'image de fond */
	virtual void printBackground() = 0;
	/* boucle d'evenements */
	virtual void waitForUser() = 0;


	VirtualScene();
	~VirtualScene();


};

