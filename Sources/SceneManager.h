#pragma once
#include <SceneBoss.h>
#include <MenuPrincipal.h>
#include <RythmNBlood.h>
#include <YouDied.h>
#include <WindowManager.h>
#include <Global.h>

class SceneManager
{
public :
	/* va a la scene choisie, une fois l'appel terminé la scene courante reprendra. */
	static void moveToScene(SceneNames name);
};
