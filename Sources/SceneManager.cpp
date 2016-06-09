#include <SceneManager.h>

void SceneManager::moveToScene(SceneNames name, WindowManager* window)
{
	//TODO a faire avant de quitter une scene
	

	switch (name)
	{
	case MENU:
	{
		MenuPrincipal scene(window, MENU);
		break;
	}
	case RNB1:
	{
		RythmNBlood scene(window , 2 , 0.1f , 0.5f, RNB1);
		break;
	}
	case RNB2:
	{
		RythmNBlood scene(window, 20 , 0.2f , 0.3f, RNB2);
		break;
	}
	case VILAIN1:
	{
		SceneBoss scene(window, 2 , VILAIN1);
		break;
	}
	case VILAIN2:
	{
		SceneBoss scene(window, 2, VILAIN2);
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

SceneNames SceneManager::fromScene(SceneNames name)
{
	switch (name)
	{
		case MENU:
		{
			return SceneNames::RNB1;
		}
		case RNB1:
		{
			return SceneNames::VILAIN1;
		}
		case RNB2:
		{
			return SceneNames::VILAIN2;
		}
		case VILAIN1:
		{
			return SceneNames::RNB2;
		}
		case VILAIN2:
		{
			return SceneNames::WIN;
		}
	
		default:
			return  SceneNames::MENU;
	}
}
