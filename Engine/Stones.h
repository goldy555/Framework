#pragma once
#include "Spaceship.h"
#include "attackship.h"


class stones {

public:
	stones();
	stones(int kx, int ky, int xvel, int yvel, const Surface *asteroid);
	void rec(Graphics &gfx);
	void velocity();
	void  display();
	
	bool Hitbox(spaceship & boom);
	void deac(const spaceship &boom);
	//getters
	int newx() const;
	int newy() const;
	int newwidth() const;
	int newheight() const;
	int newxvelo()const;
	int newyvelo()const;
	bool iscrashing_()const;

private:
	//variables and surface objects
	const Surface *asteroid;
	int lx;
	int ly;
	int lwidth = 20;
	int lheight = 20;
	int xvelo;
	int yvelo;
	bool iscrashing = false;



};