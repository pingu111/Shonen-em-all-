#pragma once

#include <Global.h>
#include <memory>
#include <vector>
#include <map>

#include <VirtualScene.h>
#include <Player.h>
#include <Bouton.h>

class RythmNBlood : VirtualScene
{

private:

	int idEnnemi;
	/* La liste d'ennemis */
	std::vector<std::shared_ptr<Ennemi>> ennemis;

	/* La liste des sprites contenant l'ennmi en train de courir */
	std::vector<std::pair<sf::Sprite,std::unique_ptr<sf::Texture>>> listSpriteEnnemyMoving;

	/* La liste des sprites du joueur en train de taper */
	std::vector<std::pair<sf::Sprite, std::unique_ptr<sf::Texture>>> listSpritePlayerHitting;

	/* La map faisant correspondre un ennemi à un sprite */
	std::map<std::shared_ptr<Ennemi>, std::pair<int, sf::Sprite>> mapSpriteEnnemi;

	std::pair<sf::Sprite, std::unique_ptr<sf::Texture>> playerWaitingSprite;

	Player& player;

	Bouton buttonQuit;

	/* Initialise les sprites du joueur et des ennemis*/
	void initSprite();

	/* Lance la scene : appelé par le consytructeur */
	void launchScene();


	/* Met à jour la scene, les ennemis, ... 
		Est bloquant */
	void waitForUser();

	/* Affiche les images de fond et les boutons initiaux de la scene */
	void printBackgroundAndButtons();

	/* Ajoute des ennemis 
	   Retourne le nouveau timer */
	std::time_t addEnnemies(std::time_t timeLastCall);


	/* Les sprites et textures pour le background */
	sf::Sprite fondSprite;
	sf::Texture fond;

public:
	/* Constructeur
	* param : WindowManager windowArg la fenetre d'affichage */
	RythmNBlood(WindowManager *windowArg);

	/* Destructeur */
	~RythmNBlood();
};

