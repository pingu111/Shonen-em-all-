#include <memory>
#include <iostream>
#include <SceneManager.h>
#pragma comment(linker, "/SUBSYSTEM:windows /ENTRY:mainCRTStartup")


int main()
{
	SceneManager::moveToScene(SceneNames::MENU);
	return 0;
}
