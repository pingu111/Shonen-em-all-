#include <EnnemiRandom.h>


bool EnnemiRandom::update()
{
	std::cout << "Loul\n";

	assert(!isDead());
	//deplacement de l'ennemi
	if (isLeft)
	{
		if (Random::randInt(0, 100) > percentageBack)
		{
			position += speed;
		}
		else
		{
			position -= speed;
		}

		isHittable = position >= playerPosition - playerHitDistance;
		if (position >= playerPosition - hitDistance)
		{
			position = playerPosition - hitDistance;
			return true;
		}
	}
	else
	{
		if (Random::randInt(0, 100) > percentageBack)
		{
			position += speed;
		}
		else
		{
			position -= speed;
		}

		isHittable = position <= playerPosition + playerHitDistance;
		if (position <= playerPosition + hitDistance)
		{
			position = playerPosition + hitDistance;
			return true;
		}
	}
	return false;
}

void EnnemiRandom::setPercentageBack(int arg)
{
	// On ne peut pas se permettre un ennemi qui recule trop 
	if (arg > 40)
		arg = 40;
	percentageBack = arg;
}
