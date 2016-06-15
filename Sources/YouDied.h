#pragma once
#include <VirtualScene.h>
#include <WindowManager.h>
#include <SceneManager.h>

class YouDied : VirtualScene
{
private:
	/* Constructeur */
	YouDied();

	static YouDied m_instance;
	YouDied(const YouDied& yd) = delete;
	void operator=(const YouDied& yd) = delete;

	void launchScene() override;
	void printBackground() override;
	void initSprite();
	void waitForUser() override;

	/* Error 404, int unknown ! */
	int nbSix;

	std::pair<sf::Text, sf::Font> textFont;

public :
	static YouDied& Instance();
	void reload() override;
};