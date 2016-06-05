#include "RythmNBlood.h"

RythmNBlood::RythmNBlood(WindowManager* windowArg)
{
	window = windowArg;
	launchScene();
}

RythmNBlood::~RythmNBlood()
{
}

void RythmNBlood::launchScene()
{
	initTextures();
	updateScene();
}

void RythmNBlood::updateScene()
{
	for (Ennemi enn : ennemis)
		enn.update();
}
