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

int Bonhomme::takeHit(int strenght)
{
	int hitStrenght = strenght - armor;
	lifePoint -= hitStrenght;
	if (isDead())
		destroy();
	return hitStrenght;
}
