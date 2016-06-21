#pragma once

#include <Random.h>
#include <Ennemi.h>

class EnnemiRandom : Ennemi
{
public:
	/* Met  � jour la position de l'ennemi */
	bool update() override;

	/* Sette la probabilit� qu'a l'ennemi de reculer*/
	void setPercentageBack(int arg);

private : 
	/* La probabilit� qu'a l'ennemi de reculer */
	int percentageBack;
};