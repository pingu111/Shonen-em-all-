#pragma once

#include <Global.h>
#include <memory>
#include <vector>
#include <map>

#include <VirtualScene.h>
#include <Player.h>
#include <Bouton.h>
#include <SceneManager.h>
#include <Level.h>

class RythmNBlood : VirtualScene
{

private:

	/************ Variables ************/


	/* Booleen explicitant si le joueur est en cours d'animation de frappe*/
	bool isPlayerInHitAnimation;

	/* Booleen : true si la derniere frappe est à gauche false si à droite */
	bool isLastHitLeft;

	/* Le nombre d'ennemis morts */
	int nbEnnemiDead;

	/* Le nombre d'ennemis spwané*/
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

	/* La meilleure police possible */
	sf::Font comicFont;

	/* Le texte des degats faits par le joueur */
	sf::Text textDamages;


	/************ Fonctions ************/

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
	void printBackground();

	/* Ajoute des ennemis 
	   Retourne le nouveau timer */
	std::time_t addEnnemies(std::time_t timeLastCall);

	/* Retourne un sprite, comme un miroir */
	sf::Sprite flipSprite(sf::Sprite spriteToFlip);

	/* Gere les animations et renvoie la liste des ennemis touchables */
	std::vector<std::shared_ptr<Ennemi>> animationsEnnemies();

	/* Gere la liste des ennemis morts et vivants, et la met à jour */
	void listDeadAlive();

	/* Gere les animations du joueur */
	void animationPlayer();

	/* Charge les .tff */
	void initFonts();

	/* Affiche un texte lorsque le joueur tape */
	void printText(int hitValue);

	/* Le nombre d'ennemis dans cette scene */
	int nbEnnemiesMax;

	/* La vitesse des ennemis */
	float ennemiSpeed;

	/* Le temps entre 2 ennemis  */
	float durationBetweenEnnemies;

	/* Constructeur
	* param : WindowManager windowArg la fenetre d'affichage */
	RythmNBlood();
	RythmNBlood(const RythmNBlood& rnb);

	static RythmNBlood m_instance;

	/* probabilité que l'ennemi ait plus de points de vie */
	float probaSuperEnnemi;

public:
	static RythmNBlood& Instance();

	void reload() override;

	/* Destructeur */
	~RythmNBlood();
};

