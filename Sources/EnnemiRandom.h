#pragma once

#include <Random.h>
#include <Ennemi.h>

class EnnemiRandom : public Ennemi
{
public:
	EnnemiRandom(bool isSpawnLeft, int idEnnemi , int percentageBack) : Ennemi( isSpawnLeft, idEnnemi)
	{
		setPercentageBack(percentageBack);
	}

	/* Met  à jour la position de l'ennemi */
	bool update() override;

	/* Sette la probabilité qu'a l'ennemi de reculer*/
	void setPercentageBack(int arg);

private : 
	/* La probabilité qu'a l'ennemi de reculer */
	int percentageBack;
};