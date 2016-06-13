#pragma once
#include <VirtualScene.h>
#include <WindowManager.h>

class YouDied : VirtualScene
{
private:
	YouDied();
	static YouDied m_instance;
	YouDied(const YouDied& yd);

public :
	static YouDied& Instance();
	void reload() override;
};