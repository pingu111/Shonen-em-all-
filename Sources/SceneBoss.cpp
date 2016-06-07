#include <SceneBoss.h>


/* selectionne aleatoirement 4 repliqes parmis toutes celles connues */
std::vector<Replique> SceneBoss::randReplique()
{
	int rand1,rand2,rand3,rand4;
	assert(repliques.size() > 4);
	rand1 = Random::randInt(0, repliques.size());
	do {
		rand2 = Random::randInt(0, repliques.size());
	} while (rand2 == rand1);
	do {
		rand3 = Random::randInt(0, repliques.size());
	} while (rand3 == rand1 || rand3 == rand2);
	do {
		rand4 = Random::randInt(0, repliques.size());
	} while (rand4 == rand1 || rand4 == rand2 || rand4 == rand3);

	std::vector<Replique> vec(4);
	vec = { *repliques[rand1],*repliques[rand2],*repliques[rand3],*repliques[rand4] };
	return vec;
}
/* attend l'appuie sur un bouton */
void SceneBoss::waitForUser()
{
	//au clic :

}
/* Le constructeur de la scene */
SceneBoss::SceneBoss(WindowManager *windowArg)
{

}