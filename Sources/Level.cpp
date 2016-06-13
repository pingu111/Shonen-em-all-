#include <Level.h>


/*
float ennemiSpeed;
float cooldown;
int ennemiNumber;
float probaSuper;
*/

bool isFirstLevel = true;

Level LevelManager::currentLevel = { 1, 1, 5, 0 };

Level LevelManager::nextLevel()
{
	if (!isFirstLevel)
	{
		Level nextLevel = { currentLevel.ennemiSpeed * 1.1 , currentLevel.cooldown * 0.95, currentLevel.ennemiNumber * 2, min(currentLevel.probaSuper + 0.1 , 1.0) };
		currentLevel = nextLevel;
	}
	else
		isFirstLevel = false;
	return currentLevel;
}

float min(float a, float b)
{
	if (b > a)
		return a;
	return b;
}

