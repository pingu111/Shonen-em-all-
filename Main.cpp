#include <memory>
#include "Sources\MenuPrincipal.h"
#include "Sources\RythmNBlood.h"
#include "Sources\WindowManager.h"
#include <SFML/Graphics.hpp>


int main()
{
	WindowManager windowManager;

	MenuPrincipal menuScene(&windowManager);
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
			RythmNBlood rnbScene(&windowManager);
			break;
		}
		default :
		{
			break;
		}
	}

	return 0;
}