#pragma once

#include <MenuPrincipal.h>
#include <RythmNBlood.h>
#include <WindowManager.h>
#include <SFML/Graphics.hpp>

enum SceneNames
{
	MENU,
	RNB,
	VILAIN,
	WIN,
	DEFEAT
};

static const float playerHitDistance = 20;
static const float playerPosition = 50;
static const float cooldown = 10;
static const int startingLifePoints = 5;
static const int scoreForKill = 1;

class Global
{
public:
	static void moveToScene(SceneNames name, WindowManager* window);

};
