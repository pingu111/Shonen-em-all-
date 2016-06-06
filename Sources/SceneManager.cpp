#include <SceneManager.h>

void SceneManager::moveToScene(SceneNames name, WindowManager* window)
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
