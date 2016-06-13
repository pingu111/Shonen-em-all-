#pragma once
#include <vector>
#include <memory>
#include <Replique.h>
#include <VirtualScene.h>
#include <Bouton.h>
#include <Random.h>
#include <assert.h>
#include <Player.h>
#include <SceneManager.h>

class SceneBoss : VirtualScene
{
private:

	/* Le nombre de repliques echangées avant de changer de scene */
	int nbRepliquesMax;

	/* la liste de toutes les repliqes possibles */
	std::vector<std::unique_ptr<Replique>> repliquesUPtr;

	/* la liste des 4 repliqes courantes et leur bouton */
	std::vector<std::pair<Replique*,Bouton>> seletedRepliques;

	/* selectionne aleatoirement 4 repliqes parmis toutes celles connues. Il doit y en avoir plus de 4 */
	std::vector<Replique*> randReplique();

	/* attend l'appuie sur un bouton */
	void waitForUser();

	Player& player;

	/* La liste des boutons */
	std::vector<Bouton> listButtonsChoices;
	std::vector<std::pair<std::unique_ptr<sf::Sprite>, std::unique_ptr<sf::Texture>>> listSpritesButtonChoice;

	/* Affiche le fond */
	void printBackground();

	/* Lance la scene */
	void launchScene();

	void initRepliques();

	/* Ouvre les .ttf */
	void initFonts();

	/* Ouvre les sprites */
	void initSprite();

	/* La meilleure police au monde */
	sf::Font comicFont;

	void chargeButtons(std::vector<Replique*> repliquesChosen);

	/* Le constructeur de la scene */
	SceneBoss();

	SceneBoss(const SceneBoss& sceneCopy) = delete;
	void operator=(const SceneBoss& wm) = delete;

	static SceneBoss m_instance;

public :
	static SceneBoss& Instance();
	void reload() override;
};
