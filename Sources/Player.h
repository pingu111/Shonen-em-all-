#pragma once

//les includes servent quand on se sert de fonctions ou bien permettent de creer des membres de la classe
#include <assert.h>
#include <Replique.h>
#include <Global.h>
#include <Ennemi.h>
#include <Random.h>
#include <Replique.h>
#include <string>

class Player
{
private:
	Replique repWaiting;
	bool hasSomethingToSay;
	int lifePoint;
	float strenght;
	void destroy();
	bool isSpriteLeft;
	float cooldownTime;
	float damageMult;
	int scoreMult;
	int score;
	float maxHit;
	/* augment la force du hero apres sa rencontre avec le grand mechant */
	void increaseStrenght();
	Player();
	static Player m_instance;

public :
	static Player& Instance();


	/*frappe un ennemi hitable et ajuste le score*/
	void hit(bool isHitLeft, Ennemi &enn);
	/* apres une replique, le hero garde sa super replique en memoire */
	void update(Replique rep);
	/* une fois la scene de combat chargee, stocke les nouvelles capacités de hero. Et augmente sa force */
	std::string sayReplique();
};