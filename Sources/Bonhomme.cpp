#include "Bonhomme.h"

Bonhomme::Bonhomme() 
{
	lifePoint = 0;
}

Bonhomme::Bonhomme(int lpArg)
{
	lifePoint = lpArg;
}

int Bonhomme::getLifePoint()
{
	return lifePoint;
}

void Bonhomme::setLifePoint(int newLp)
{
	lifePoint = newLp;
}

