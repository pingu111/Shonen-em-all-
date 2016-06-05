#pragma once

#include <Bonhomme.h>
#include <assert.h>
#include <Global.h>

class Player : public Bonhomme
{
private:
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
	void hit(bool isHitLeft, Bonhomme &enn);
};