#pragma once
#include <VirtualScene.h>
#include <WindowManager.h>

class YouDied : VirtualScene
{
private:
	YouDied();
	static YouDied m_instance;

	YouDied(const YouDied& yd) = delete;
	void operator=(const YouDied& yd) = delete;

	void launchScene() override;
	void printBackground() override;
	void initSprite();
	void waitForUser() override;

public :
	static YouDied& Instance();
	void reload() override;
};