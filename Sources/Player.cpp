#include <Player.h>


Player::Player()
{
	lifePoint = startingLifePoints;
	position = playerPosition;
	score = 0;
	isSpriteLeft = true;
	cooldownTime = 0;
	damageMult = 1;
	scoreMult = 1;
	score = 0;
	strenght = 1;
	maxHit = 0;
}

void Player::destroy()
{
	//TODO fonction
}

void Player::hit(bool isHitLeft, Ennemi &enn)
{
	assert(cooldownTime <= 0);
	//TODO changer le sprite (gauche/droite)
	cooldownTime = cooldown;
	//TODO afficher le score sur l'ecran
	int hitValue = enn.takeHit(strenght*damageMult);
	if (enn.isDead())
		score += scoreForKill*scoreMult;
}
