#include <SceneManager.h>

void SceneManager::moveToScene(SceneNames name, WindowManager* window)
{
	//TODO a faire avant de quitter une scene
	

	switch (name)
	{
	case MENU:
	{
		MenuPrincipal::Instance(window).reload();
		break;
	}
	case RNB:
	{
		RythmNBlood::Instance(window).reload();
		break;
	}
	case VILAIN:
	{
		SceneBoss::Instance(window).reload();
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
