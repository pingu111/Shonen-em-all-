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
	case RNB1:
	{
		RythmNBlood scene(window , 2 , 1.0f , 0.5f);
		break;
	}
	case RNB2:
	{
		RythmNBlood scene(window, 20 , 1.0f , 0.3f);
		break;
	}
	case VILAIN:
	{
		SceneBoss scene(window);
		break;
	}
	case WIN:
		break;
	case DEFEAT:
		break;
	default:
		break;
	}
	//TODO a faire au debut de toutes les scenes
}
