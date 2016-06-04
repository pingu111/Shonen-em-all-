#pragma once

#include <Bonhomme.h>

float playerPosition = 50;

class Player : public Bonhomme
{
public :
	void takeHit(float strenght) override;
};