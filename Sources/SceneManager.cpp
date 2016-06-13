#include <SceneManager.h>

void SceneManager::moveToScene(SceneNames name)
{
	//TODO a faire avant de quitter une scene
	

	switch (name)
	{
	case MENU:
	{
		MenuPrincipal::Instance().reload();
		return;
	}
	case RNB:
	{
		RythmNBlood::Instance().reload();
		return;
	}
	case VILAIN:
	{
		SceneBoss::Instance().reload();
		return;
	}
	case WIN:
	{
		return;
	}
	case DEFEAT:
	{
		YouDied::Instance().reload();
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
