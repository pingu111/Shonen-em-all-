#include <memory>
#include "Sources\MenuPrincipal.h"
#include "Sources\RythmNBlood.h"
#include "Sources\WindowManager.h"
#include <SFML/Graphics.hpp>

enum SceneNames
{
	MENU,
	RNB,
	VILAIN,
	WIN,
	DEFEAT
};

int main()
{
	WindowManager windowManager;
	moveToScene(SceneNames::MENU);
	return 0;
}

static void moveToScene(SceneNames name)
{
	//TODO a faire avant de quitter une scene
	switch (name)
	{
	case MENU:
	{
		MenuPrincipal scene();
		break;
	}
	case RNB:
	{
		RythmNBlood scene();
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