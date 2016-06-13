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
	static Level currentLevel;
public :
	static Level nextLevel();
};