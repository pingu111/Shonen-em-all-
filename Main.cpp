#include <memory>
#include <iostream>
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

static void moveToScene(SceneNames name , WindowManager* window)
{
	//TODO a faire avant de quitter une scene
	switch (name)
	{
	case MENU:
	{
		MenuPrincipal scene(window);
		break;
	}
	case RNB:
	{
		RythmNBlood scene(window);
		break;
	}
	case VILAIN:
		break;
	case WIN:
		break;
	case DEFEAT:
		break;
	default:
		break;
	}
	//TODO a faire au debut de toutes les scenes
}

int main()
{
	WindowManager windowManager;
	moveToScene(SceneNames::MENU , &windowManager);
	return 0;
}
