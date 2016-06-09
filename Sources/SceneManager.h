#pragma once

#include <MenuPrincipal.h>
#include <RythmNBlood.h>
#include <WindowManager.h>
#include <SceneBoss.h>
#include <Global.h>


class SceneManager
{
public:
	static void moveToScene(SceneNames name, WindowManager* window);
	static SceneNames fromScene(SceneNames name);
};
