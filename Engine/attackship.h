#pragma once
#include "Spaceship.h"

#include "Surface.h"


class attackship  {


public:
	//constructors
	attackship();
	attackship(int gx, int gy, int cvelox, int cveloy, const Surface *alien);
	
	 // getters
	 int getcx() const;
	 int getcy() const;
	 int getwidth() const;
	 int getheight() const;
	 int getvelox()const;
	 int getveloy()const;
	 bool neverfalse = false;
	 bool iscolliding = false;
	//functions
	 void velocity();
	 void display();
	 virtual bool Hitbox(spaceship & boom);
	 virtual void rec(Graphics &gfx);
private:
	//variable and surface obj.
	const Surface *alien;
	int cx ;
	int cy ;
	int ali;
	int cwidth =20;
	int cheight =20;
	int velox ;
	int veloy ;
	bool gameover = false;

};