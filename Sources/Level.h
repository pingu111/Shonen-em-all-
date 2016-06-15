#pragma once
#include <algorithm> 

struct Level
{
	float ennemiSpeed;
	float cooldown;
	int ennemiNumber;
	float probaSuper;
};

class LevelManager
{
private:
	/* le niveau en cours */
	static Level currentLevel;
public :
	/* 
	  calcul les valeurs du nouveau level à partir du precedent
	  retourne les valeurs du nouveau level
	 */
	static Level nextLevel();
};