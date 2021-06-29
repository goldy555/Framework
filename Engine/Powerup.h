#pragma once
#include "Spaceship.h"
#include "attackship.h"

// use of inheritance and polymorphism
class powerup : public attackship {

public:
	powerup();
	powerup(int ab, int cd, int ef, int gh);
	bool Hitbox(spaceship &boom) override;
	void rec(Graphics &gfx)override;
private:
	
	Surface medkit = Surface("Spirtes\\meds.bmp");

};