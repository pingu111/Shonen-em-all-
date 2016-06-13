#include "VirtualScene.h"



VirtualScene::VirtualScene()
{
}


VirtualScene::~VirtualScene()
{
}


void VirtualScene::initFonts()
{
	assert(comicFont.loadFromFile("Ressources\\ComicSansMS.ttf") == true);
}