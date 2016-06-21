#include <EnnemiClassic.h>



bool EnnemiClassic::update()
{
	assert(!isDead());

	//std::cout << "classic position " << position << " speed " << speed <<  "\n";
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
