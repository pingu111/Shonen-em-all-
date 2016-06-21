#pragma once

//les includes servent quand on se sert de fonctions ou bien permettent de creer des membres de la classe
#include <assert.h>
#include <Replique.h>
#include <Global.h>

#include <EnnemiRandom.h>
#include <EnnemiClassic.h>

#include <Random.h>
#include <Replique.h>
#include <string>

class Player
{
private:
	Replique repWaiting;
	/* le joueur a t il quelque chose a dire apres sa rencontre avec le grand mechant ? */
	bool hasSomethingToSay;
	int lifePoint;
	float strenght;
	bool isSpriteLeft;
	float damageMult;
	int scoreMult;
	int score;
	int maxHit;
	/* augment la force du hero apres sa rencontre avec le grand mechant */
	void increaseStrenght();
	Player();
	static Player m_instance;

public :
	static Player& Instance();

	/* has the payer something to say */
	bool getHasSomethingToSay();
	/*frappe un ennemi hitable et ajuste le score*/
	int hit(Ennemi &enn);
	/* apres une rencontre avec le grand mechant, le hero garde sa super replique en memoire (sauf si elle est suffisament nulle pour qu'il perde)*/
	void update(Replique rep);
	/* une fois la scene de combat chargee le hero clame sa replique (valeur de retour), stocke les nouvelles capacites de hero. Et augmente sa force */
	std::string sayReplique();

	/* le hero se fait frapper et perd un point de vie */
	void takeHit();

	/* renvoie le melleur coup du joueur */
	int getMaxHit();

	/* suis-je mort ? */
	bool isDead();

	/* Renvoie le score du joueur */
	int getScore();
};