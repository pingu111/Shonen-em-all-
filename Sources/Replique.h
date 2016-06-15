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
	/* la liste de toutes les repliques possibles */
	const static std::vector<Replique> repliques;
};