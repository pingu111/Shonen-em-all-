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

	bool playerHittingAnimation;
	bool isLastHitLeft;

	int idEnnemi;
	/* La liste d'ennemis en vie */
	std::vector<std::shared_ptr<Ennemi>> ennemisAlive;

	/* La liste d'ennemis mourants, en cours d'animation de mort */
	std::vector<std::shared_ptr<Ennemi>> ennemisDead;

	/* La liste des sprites contenant l'ennmi en train de courir */
	std::vector<std::pair<sf::Sprite,std::unique_ptr<sf::Texture>>> listSpriteEnnemyMoving;

	/* La liste des sprites du joueur en train de taper */
	std::vector<std::pair<sf::Sprite, std::unique_ptr<sf::Texture>>> listSpritePlayerHitting;

	/* La map faisant correspondre un ennemi à un sprite */
	std::map<std::shared_ptr<Ennemi>, std::pair<int, sf::Sprite>> mapSpriteEnnemi;

	std::pair<sf::Sprite, std::unique_ptr<sf::Texture>> playerWaitingSprite;

	/* Le joueur et son numero actuel de sprite */
	std::pair<Player&, int> player;

	Bouton buttonQuit;

	/* Initialise les sprites du joueur et des ennemis*/
	void initSprite();

	/* Lance la scene : appelé par le consytructeur */
	void launchScene();

	/* Gere les inputs */
	std::vector<std::shared_ptr<Ennemi>> eventManager(std::vector<std::shared_ptr<Ennemi>> ennemiesHittables);

	/* Met à jour la scene, les ennemis, ... 
		Est bloquant */
	void waitForUser();

	/* Affiche les images de fond et les boutons initiaux de la scene */
	void printBackgroundAndButtons();

	/* Ajoute des ennemis 
	   Retourne le nouveau timer */
	std::time_t addEnnemies(std::time_t timeLastCall);

	/* Retourne un sprite, comme un miroir */
	sf::Sprite flipSprite(sf::Sprite spriteToFlip);

	/* Gere les animations et renvoie la liste des ennemis touchables */
	std::vector<std::shared_ptr<Ennemi>> animations();

	/* Gere la liste des ennemis morts et vivants, et la met à jour */
	void listDeadAlive();

	/* Gere les animations du joueur */
	void animationPlayer();


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

