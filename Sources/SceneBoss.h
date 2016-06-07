#pragma once
#include <vector>
#include <memory>
#include <Replique.h>
#include <VirtualScene.h>

class SceneBoss : VirtualScene
{
private:
	/* la liste de toutes les repliqes possibles */
	std::vector<std::unique_ptr<Replique>> repliques;
	/* la liste des 4 repliqes courantes */
	std::vector<Replique> SeletedRepliques;
	/* selectionne aleatoirement 4 repliqes parmis toutes celles connues */
	std::vector<Replique> randReplique();
	/* attend l'appuie sur un bouton */
	void waitForUser();
public :
	/* Le constructeur de la scene */
	SceneBoss(WindowManager *windowArg);
};
