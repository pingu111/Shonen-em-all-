#pragma once

#include <Player.h>
#include <Bonhomme.h>
#include <assert.h>

static float hitDistance = 5;

class Ennemi : public Bonhomme
{
private :
	float speed;
	bool isSuper;
	bool isLeft;
	/*hit the player and commit suicide*/
	void hitPlayer(Player player);
	void destroy();
public :
	Ennemi(bool isSpawnLeft);

	/* transforme un ennemi en super ennemi */
	void makeSuper();

	/* initialise la vitesse de l'ennemi (en fonction du temps passe dans le jeu)
	 */
	void initSpeed(float speed);

	/* update la position de l'ennemi et frappe l'ennemi si necessaire*/
	void update(Player player);

	/*l'ennemi est-il assez proche pour se prendre un coup*/
	bool isHitable();

};