#pragma once
#include <VirtualScene.h>
#include <WindowManager.h>

class YouDied : VirtualScene
{
private:
	YouDied();
	static YouDied m_instance;
public :
	static YouDied& Instance();
	void reload() override;
};