#include <Level.h>


/*
float ennemiSpeed;
float cooldown;
int ennemiNumber;
float probaSuper;
*/

bool isFirstLevel = true;

Level LevelManager::currentLevel = { 1, 1, 5, 0 };

static float min(float a, float b)
{
	if (b > a)
		return a;
	return b;
}

Level LevelManager::nextLevel()
{
	if (!isFirstLevel)
	{
		Level nextLevel = { currentLevel.ennemiSpeed * 1.1f , currentLevel.cooldown * 0.95f, currentLevel.ennemiNumber * 2, min(currentLevel.probaSuper + 0.1f , 1.0f) };
		currentLevel = nextLevel;
	}
	else
		isFirstLevel = false;
	return currentLevel;
}

