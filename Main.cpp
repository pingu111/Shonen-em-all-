#include <memory>
#include <iostream>
#include <Global.h>





int main()
{
	WindowManager windowManager;
	Global::moveToScene(SceneNames::MENU , &windowManager);
	return 0;
}
