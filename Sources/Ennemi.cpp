#include <Ennemi.h>

Ennemi::Ennemi(bool isSpawLeft)
{
	lifePoint = 1;
	speed = 0;
	isSuper = false;
	strenght = 1;
	armor = 1;
	isLeft = isSpawLeft;
	if (isSpawLeft)
		position = 0;
	else
		position = 100;
}

void Ennemi::initSpeed(float speed_)
{
	assert(speed == 0);
	speed = speed_;
}

void Ennemi::makeSuper()
{
	assert(isSuper == false);
	//TODO definir un super ennemi
}

bool Ennemi::isHitable()
{
	if (isLeft)
		return position >= playerPosition - playerHitDistance;
	return position <= playerPosition + playerHitDistance;
}

void Ennemi::hitPlayer(Player player)
{
	player.takeHit(strenght);
	takeHit(armor+lifePoint);
}

void Ennemi::destroy()
{
	//TODO annimation de mort + clean
}

void Ennemi::update(Player player)
{
	//deplacement de l'ennemi
	if (isLeft)
	{
		position += speed;
		if (position >= playerPosition - hitDistance)
		{
			position = playerPosition - hitDistance;
			hitPlayer(player);
		}

	}
	else
	{
		position -= speed;
		if (position <= playerPosition + hitDistance)
		{
			position = playerPosition + hitDistance;
			hitPlayer(player);
		}
	}
}