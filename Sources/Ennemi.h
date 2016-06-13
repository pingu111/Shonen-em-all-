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

	bool isDead();
	void takeHit();

	float getXPosition();

	bool getIsLeft();

	int id;

	void suicide();
};

bool  operator< (const  Ennemi a, const Ennemi b);