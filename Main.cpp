#include <memory>
#include "MenuPrincipal.h"
#include "RythmNBlood.h"
#include "WindowManager.h"
#include <SFML/Graphics.hpp>


int main()
{
	WindowManager windowManager;

	MenuPrincipal menuScene(windowManager);

	return 0;
}