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
		RythmNBlood scene(window , 2 , 0.1f , 0.5f);
		break;
	}
	case RNB2:
	{
		RythmNBlood scene(window, 20 , 0.2f , 0.3f);
		break;
	}
	case VILAIN1:
	{
		SceneBoss scene(window, 2);
		break;
	}
	case VILAIN2:
	{
		SceneBoss scene(window, 2);
		break;
	}
	case WIN:
		break;
	case DEFEAT:
		break;
	case EXIT:
		//TODO close la fenetre
	default:
		break;
	}
	//TODO a faire au debut de toutes les scenes
}
