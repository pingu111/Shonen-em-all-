#include <EnnemiRandom.h>


bool EnnemiRandom::update()
{
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
			// On fait un bond en arrière
			position -= ( speed * changementSpeed);
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
			position -= speed;
		}
		else
		{
			// On fait un bond en arrière
			position += (speed * changementSpeed);
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
	if (arg > 50/ changementSpeed)
		arg = 50/ changementSpeed;
	percentageBack = arg;
}
