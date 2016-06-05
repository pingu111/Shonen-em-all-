#pragma once

#include <Bonhomme.h>
#include <assert.h>

static float playerHitDistance = 20;
static float playerPosition = 50;
static float cooldown = 10;
static int startingLifePoints = 5;

class Player : public Bonhomme
{
	bool isSpriteLeft;
	float cooldownTime;
	float damageMult;
	float scoreMult;
	float score;
public :
	Player();
	void takeHit(int strenght) override;
	void hit(bool isHitLeft);
};