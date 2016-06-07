#pragma once
#include <vector>
#include <memory>
#include <Replique.h>
#include <VirtualScene.h>
#include <Bouton.h>
#include <Random.h>
#include <assert.h>
#include <Player.h>

class SceneBoss : VirtualScene
{
private:
	/* la liste de toutes les repliqes possibles */
	std::vector<std::unique_ptr<Replique>> repliques;
	/* la liste des 4 repliqes courantes et leur bouton */
	std::vector<std::pair<Replique&,std::unique_ptr<Bouton>>> SeletedRepliques;
	/* selectionne aleatoirement 4 repliqes parmis toutes celles connues. Il doit y en avoirp plus de 4 */
	std::vector<Replique> randReplique();
	/* attend l'appuie sur un bouton */
	void waitForUser();
	Player& player;
public :
	/* Le constructeur de la scene */
	SceneBoss(WindowManager *windowArg);
};
