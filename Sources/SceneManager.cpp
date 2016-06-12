#include <SceneManager.h>

void SceneManager::moveToScene(SceneNames name, WindowManager* window)
{
	//TODO a faire avant de quitter une scene
	

	switch (name)
	{
	case MENU:
	{
		MenuPrincipal::Instance(window).reload();
		return;
	}
	case RNB:
	{
		RythmNBlood::Instance(window).reload();
		return;
	}
	case VILAIN:
	{
		SceneBoss::Instance(window).reload();
		return;
	}
	case WIN:
	{
		return;
	}
	case DEFEAT:
	{
		return;
	}
	case EXIT:
	{
		return;
	}
	default:
		return;
	}
}
