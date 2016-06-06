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
	std::vector<Ennemi> ennemis;

	/* La liste des sprites contenant l'ennmi en train de courir */
	std::vector<sf::Sprite> listSpriteEnnemyMoving;

	/* La liste des sprites du joueur en train de taper */
	std::vector<sf::Sprite> listSpritePlayerHitting;

	/* La map faisant correspondre un ennemi � un sprite */
	std::map<Ennemi, sf::Sprite> mapSpriteEnnemi;

	sf::Sprite playerWaitingSprite;

	static Player player;

	Bouton buttonQuit;

	/* Initialise les sprites du joueur et des ennemis*/
	void initSprite();

	/* Lance la scene : appel� par le consytructeur */
	void launchScene();


	/* Met � jour la scene, les ennemis, ... 
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

