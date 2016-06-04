#include <Bonhomme.h>

Bonhomme::Bonhomme()
{
	lifePoint = 0;
}

int Bonhomme::getLifePoint()
{
	return lifePoint;
}

bool Bonhomme::isDead()
{
	return lifePoint <= 0;
}

