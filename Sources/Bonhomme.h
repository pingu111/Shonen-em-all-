#pragma once

class Bonhomme
{

private:
	int lifePoint;

public:
	/* Constructeur sans arguments */
	Bonhomme();

	/* Constructeur 
	* Param : lpArg, le nombre de points de vie de ce bonhomme */
	Bonhomme(int lpArg);

	/* Renvoie le nombre de point de vie de ce personnage */
	virtual int getLifePoint();

	/* Sette le nombre de points de vie de ce bonhomme */
	virtual void setLifePoint(int newLp);

};

