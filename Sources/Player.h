#pragma once

#include <Bonhomme.h>
#include <assert.h>
#include <Ennemi.h>

static const float playerHitDistance = 20;
static const float playerPosition = 50;
static const float cooldown = 10;
static const int startingLifePoints = 5;
static const int scoreForKill = 1;

class Player : public Bonhomme
{
private:
	void destroy();
	bool isSpriteLeft;
	float cooldownTime;
	float damageMult;
	float scoreMult;
	float score;
	float maxHit;
public :
	Player();

	/*frappe un ennemi hitable et ajuste le score*/
	void hit(bool isHitLeft, Ennemi enn);
};