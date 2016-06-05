#pragma once

class Bonhomme
{

protected :
	float position;
	/*le nombre de points de vie*/
	int lifePoint;
	/*les degats infliges a caque coups*/
	int strenght;
	/*une valeur qui reduit les degats reçus*/
	int armor;
private:
	virtual void destroy() = 0;
public :
	/* Constructeur 
	* Param : lpArg, le nombre de points de vie de ce bonhomme */
	Bonhomme();

	/* Renvoie le nombre de point de vie de ce personnage */
	int getLifePoint();

	bool isDead();

	int takeHit(int strenght);


};

