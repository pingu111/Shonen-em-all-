#pragma once

#include <MenuPrincipal.h>
#include <RythmNBlood.h>
#include <WindowManager.h>
#include <SFML/Graphics.hpp>

enum SceneNames
{
	MENU,
	RNB,
	VILAIN,
	WIN,
	DEFEAT
};


class SceneManager
{
public:
	static void moveToScene(SceneNames name, WindowManager* window);

};
