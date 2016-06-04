#pragma once

class Bonhomme
{

protected :
	/*le nombre de points de vie*/
	int lifePoint;
	/*les degats infliges a caque coups*/
	float strenght;
	/*une valuer qui divise les degats reçus*/
	float armor;

public:
	/* Constructeur 
	* Param : lpArg, le nombre de points de vie de ce bonhomme */
	Bonhomme();

	/* Renvoie le nombre de point de vie de ce personnage */
	int getLifePoint();

	bool isDead();

	void virtual takeHit(float strenght) = 0;
};

