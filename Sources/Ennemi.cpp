#include <Ennemi.h>

Ennemi::Ennemi(bool isSpawLeft , int idEnnemi)
{
	id = idEnnemi;
	lifePoint = 1;
	isHittable = false;
	speed = 0;
	isSuper = false;
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
	lifePoint = 2;
	isSuper = true;
	//TODO definir un super ennemi
}

bool Ennemi::isHitable()
{
	if (isDead())
		return false;
	if (isLeft)
		return position >= playerPosition - playerHitDistance;
	return position <= playerPosition + playerHitDistance;
}

bool Ennemi::isDead()
{
	return lifePoint <= 0;
}

void Ennemi::takeHit()
{
	std::cout << "ennemi take hit " << isSuper << "\n";
	lifePoint -= 1;
}

void Ennemi::suicide()
{
	lifePoint = 0;
}

void Ennemi::destroy()
{
	isHittable = false;
	//TODO annimation de mort + clean
}

bool Ennemi::update()
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
			return true;
		}

	}
	else
	{
		position -= speed;
		isHittable = position <= playerPosition + playerHitDistance;
		if (position <= playerPosition + hitDistance)
		{
			position = playerPosition + hitDistance;
			return true;
		}
	}
	return false;
}

float Ennemi::getXPosition()
{
	return position;
}

bool Ennemi::getIsLeft()
{
	return isLeft;
}

bool Ennemi::getIsSuper()
{
	return isSuper;
}

bool operator< (const  Ennemi a, const Ennemi b)
{
	return (a.id < b.id);
}


