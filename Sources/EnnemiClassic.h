#pragma once
#include <Ennemi.h>

class EnnemiClassic : public Ennemi
{
public:
	EnnemiClassic(bool isSpawnLeft, int idEnnemi) : Ennemi(isSpawnLeft, idEnnemi) {}

	/* Met  � jour la position de l'ennemi */
	bool update() override;

};