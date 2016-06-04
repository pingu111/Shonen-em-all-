#pragma once

#include <Bonhomme.h>

class Player : public Bonhomme
{
public :
	void takeHit(float strenght) override;

};