#pragma once

#include <assert.h>
#include <SFML\Graphics.hpp>
#include <Global.h>
#include <vector>
#include <iostream>
#include <string>


static float hitDistance = 5;

class Ennemi
{
private :
	float position;
	int lifePoint;
	bool isHittable;
	float speed;
	bool isSuper;
	bool isLeft;
	void destroy();


	
public :
	Ennemi(bool isSpawnLeft , int idEnnemi);

	/* transforme un ennemi en super ennemi */
	void makeSuper();

	/* initialise la vitesse de l'ennemi (en fonction du temps passe dans le jeu)
	 */
	void initSpeed(float speed);

	/* update la position de l'ennemi, return true si l'ennemi frappe le joueur*/
	bool update();

	/*l'ennemi est-il assez proche pour se prendre un coup*/
	bool isHitable();

	/* est-il mort ? */
	bool isDead();
	/* le sbire se fait frapper */
	void takeHit();

	/* retourne la position en X actuelle du sbire */
	float getXPosition();

	/* le sbire est-il a la gauche de hero ? */
	bool getIsLeft();

	/* l'id du sbire, il n'a rien a dire dessus, et ne bouge pas */
	static int id;

	/* depressif apres avoir reussi sa mission (frapper le hero), le sbire se suiide car il ne sert plus a rien pour le grand mechant (c'est triste :'( ) */
	void suicide();

	/* suis-je un super sbire ? */
	bool getIsSuper();

};

bool  operator< (const  Ennemi a, const Ennemi b);