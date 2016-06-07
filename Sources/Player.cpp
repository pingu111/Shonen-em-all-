#include <Player.h>

Player Player::m_instance = Player();

Player::Player()
{
	lifePoint = startingLifePoints;
	score = 0;
	isSpriteLeft = true;
	cooldownTime = 0;
	damageMult = 1;
	scoreMult = 1;
	score = 0;
	strenght = 1;
	maxHit = 0;
}

Player& Player::Instance()
{
	return m_instance;
}

void Player::destroy()
{
	//TODO fonction
}

void Player::increaseStrenght()
{
	strenght += 1;
}



void Player::hit(bool isHitLeft, Ennemi &enn)
{
	assert(cooldownTime <= 0);
	cooldownTime = cooldown;

	float bonus = Random::randFloat(0, 2);
	float hitValue = enn.takeHit(bonus*strenght*damageMult);

	if (hitValue > maxHit)
		maxHit = hitValue;
	if (enn.isDead())
		score += std::round(scoreForKill*scoreMult);
}

void Player::update(Replique replique)
{
	damageMult = replique.damageMult;
	scoreMult = replique.scoreMult;
	increaseStrenght();
}