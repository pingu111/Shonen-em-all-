#include <Random.h>

int Random::randInt(int left, int right)
{
	static std::random_device rd;

	static std::mt19937 e2(rd());

	std::uniform_int_distribution<> dist(left, right);

	return dist(e2);
}

float Random::randFloat(float left, float right)
{
	static std::random_device rd;

	static std::mt19937 e2(rd());

	std::uniform_real_distribution<> dist(left, right);

	return (float)dist(e2);
}