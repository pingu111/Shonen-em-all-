#include <Ennemi.h>

Ennemi::Ennemi(bool isSpawLeft , int idEnnemi)
{
	id = idEnnemi;
	lifePoint = 1;
	isHittable = false;
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

bool Ennemi::isDead()
{
	return lifePoint <= 0;
}

float Ennemi::takeHit(float strenght)
{
	return 0;
}

void Ennemi::destroy()
{
	isHittable = false;
	//TODO annimation de mort + clean
}

void Ennemi::update()
{
	assert(!isDead());
	//deplacement de l'ennemi
	if (isLeft)
	{
		position += speed;
		isHittable = position >= playerPosition - playerHitDistance;
		if (position >= playerPosition - hitDistance)
		{
			position = playerPosition - hitDistance;
		}

	}
	else
	{
		position -= speed;
		isHittable = position <= playerPosition + playerHitDistance;
		if (position <= playerPosition + hitDistance)
		{
			position = playerPosition + hitDistance;
		}
	}
}

float Ennemi::getXPosition()
{
	return position;
}

bool Ennemi::getIsLeft()
{
	return isLeft;
}

bool operator< (const  Ennemi a, const Ennemi b)
{
	return (a.id < b.id);
}


