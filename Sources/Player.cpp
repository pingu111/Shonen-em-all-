#include "Player.h"


Player::Player()
{
	lifePoint = startingLifePoints;
}

void Player::takeHit(int strenght)
{
	lifePoint -= strenght - armor;
}

void Player::hit(bool isHitLeft)
{
	assert(cooldownTime <= 0);
	//TODO changer le sprite (gauche/droite)
	cooldownTime = cooldown;
}
