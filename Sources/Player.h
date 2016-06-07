#pragma once

//les includes servent quand on se sert de fonctions ou bien permettent de creer des membres de la classe
#include <assert.h>
#include <Replique.h>
#include <Global.h>
#include <Ennemi.h>

class Player
{
private:
	int lifePoint;
	int strenght;
	void destroy();
	bool isSpriteLeft;
	float cooldownTime;
	int damageMult;
	int scoreMult;
	int score;
	int maxHit;


public :
	Player();

	/*frappe un ennemi hitable et ajuste le score*/
	void hit(bool isHitLeft, Ennemi &enn);
	void update(Replique rep);
};