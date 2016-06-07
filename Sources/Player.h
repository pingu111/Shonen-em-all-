#pragma once

//les includes servent quand on se sert de fonctions ou bien permettent de creer des membres de la classe
#include <assert.h>
#include <Replique.h>
#include <Global.h>
#include <Ennemi.h>
#include <Random.h>

class Player
{
private:
	int lifePoint;
	float strenght;
	void destroy();
	bool isSpriteLeft;
	float cooldownTime;
	float damageMult;
	float scoreMult;
	int score;
	float maxHit;
	/* augment la force du hero apres sa rencontre avec le grand mechant */
	void increaseStrenght();


public :
	Player();

	/*frappe un ennemi hitable et ajuste le score*/
	void hit(bool isHitLeft, Ennemi &enn);
	/* apres une replique, stocke les nouvelles capacités de hero. Et augmente sa force */
	void update(Replique rep);
};