#pragma once

#include <MenuPrincipal.h>
#include <RythmNBlood.h>
#include <WindowManager.h>
#include <SceneBoss.h>

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
