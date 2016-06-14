#include <Player.h>

Player Player::m_instance = Player();

Player::Player()
{
	hasSomethingToSay = false;
	lifePoint = startingLifePoints;
	score = 0;
	isSpriteLeft = true;
	damageMult = 1;
	scoreMult = 1;
	score = 0;
	strenght = 10;
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
	strenght *= 2;
}

int Player::getScore()
{
	return score;
}

int Player::hit(Ennemi &enn)
{
	float bonus = Random::randFloat(1, 2);
	enn.takeHit();
	int hitValue = (int)(bonus * strenght * damageMult);
	if (hitValue > maxHit)
		maxHit = hitValue;
	if (enn.isDead())
		score += scoreForKill*scoreMult;
	return hitValue;
}

void Player::update(Replique replique)
{
	assert(!hasSomethingToSay);
	repWaiting = replique;
	hasSomethingToSay = true;
}

std::string Player::sayReplique()
{
	assert(hasSomethingToSay);
	damageMult = repWaiting.damageMult;
	scoreMult = repWaiting.scoreMult;
	lifePoint = startingLifePoints;
	increaseStrenght();
	hasSomethingToSay = false;
	return repWaiting.text;
}

bool Player::getHasSomethingToSay()
{
	return hasSomethingToSay;
}

void Player::takeHit()
{
	lifePoint -= 1;
}

bool Player::isDead()
{
	return lifePoint < 0;
}