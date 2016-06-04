#pragma once

#include <Player.h>
#include <Bonhomme.h>
#include <assert.h>

float hitDistance = 5;

class Ennemi : public Bonhomme
{
private :
	float position;
	float speed;
	bool isSuper;
	bool isLeft;
public :
	Ennemi(bool isSpawnLeft);

	/* transforme un ennemi en super ennemi */
	void makeSuper();

	/* initialise la vitesse de l'ennemi (en fonction du temps passe dans le jeu)
	 */
	void initSpeed(float speed);

	/* update la position de l'ennemi et tappe le player si suffisament proche */
	void update();

	void takeHit(float strenght) override;

	void hitPlayer(Player player);

};