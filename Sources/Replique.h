#pragma once
#include <string>
#include <vector>

struct Replique
{
	std::string text;
	int scoreMult;
	float damageMult;
};

class ListReplique
{
public :
	const static std::vector<Replique> repliques;
};