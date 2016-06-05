#pragma once

#include <SFML/Graphics.hpp>
#include <memory>
#include <WindowManager.h>
#include <VirtualScene.h>
#include <Ennemi.h>


class RythmNBlood : VirtualScene
{

private:
	std::vector<Ennemi> ennemis;
	static Player player;
	void launchScene();
	void initTextures();
	void updateScene();

public:
	/* Constructeur
	* param : WindowManager windowArg la fenetre d'affichage */
	RythmNBlood(WindowManager * windowArg);

	/* Destructeur */
	~RythmNBlood();
};

