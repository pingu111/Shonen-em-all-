#pragma once
#include <Bonhomme.h>
#include <Global.h>
#include <assert.h>
#include <vector>
#include <iostream>
#include <string>


static float hitDistance = 5;

class Ennemi : public Bonhomme
{
private :
	bool isHittable;
	float speed;
	bool isSuper;
	bool isLeft;

	void destroy();

	/* La liste des sprites contenant l'ennmi en train de courir */
	std::vector<sf::Sprite> listSpriteEnnemyMoving;

	void initSprites();
	
public :
	Ennemi(bool isSpawnLeft);

	/* transforme un ennemi en super ennemi */
	void makeSuper();

	/* initialise la vitesse de l'ennemi (en fonction du temps passe dans le jeu)
	 */
	void initSpeed(float speed);

	/* update la position de l'ennemi et frappe l'ennemi si necessaire*/
	void update();

	/*l'ennemi est-il assez proche pour se prendre un coup*/
	bool isHitable();

};