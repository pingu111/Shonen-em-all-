#include <memory>
#include "MenuPrincipal.h"
#include "RythmNBlood.h"
#include "WindowManager.h"
#include <SFML/Graphics.hpp>


int main()
{
	WindowManager windowManager;

	MenuPrincipal menuScene(windowManager);
	menuScene.printBackgroundAndButtons();

	EnumChoicesUser choice = menuScene.waitForUser();
	switch (choice)
	{
		case QUIT:
		{
			// TODO Tout detruire ici
			break;
		}
		case RYTHM:
		{
			// TODO partir sur la scene RNB
			RythmNBlood rnbScene(windowManager);
			break;
		}
		default :
		{
			break;
		}
	}

	return 0;
}