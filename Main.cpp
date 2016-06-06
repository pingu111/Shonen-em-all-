#include <memory>
#include <iostream>
#include <SceneManager.h>


int main()
{
	WindowManager windowManager;
	SceneManager::moveToScene(SceneNames::MENU , &windowManager);
	return 0;
}
