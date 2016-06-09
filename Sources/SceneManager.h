#pragma once

#include <MenuPrincipal.h>
#include <RythmNBlood.h>
#include <WindowManager.h>
#include <SceneBoss.h>

enum SceneNames
{
	MENU,
	RNB1,
	RNB2,
	VILAIN,
	WIN,
	DEFEAT,
	EXIT
};


class SceneManager
{
public:
	static void moveToScene(SceneNames name, WindowManager* window);

};
