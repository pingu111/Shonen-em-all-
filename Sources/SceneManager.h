#pragma once
#include <SceneBoss.h>
#include <MenuPrincipal.h>
#include <RythmNBlood.h>
#include <YouDied.h>
#include <WindowManager.h>
#include <Global.h>

class SceneManager
{
public :
	static void moveToScene(SceneNames name, WindowManager* window);
};
