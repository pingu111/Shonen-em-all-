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
	virtual void reload() = 0;
	virtual void launchScene() = 0;
	virtual void printBackground() = 0;
	virtual void waitForUser() = 0;


	VirtualScene();
	~VirtualScene();


};

