#include "attackship.h"
#include "Surface.h"


//constructors
attackship::attackship():alien(nullptr)
{
}


attackship:: attackship(int gx, int gy, int cvelox, int xveloy, const Surface *alien): cx(gx),cy(gy), velox(cvelox), veloy(xveloy),alien(alien)
	
{
	
}
// Velocity Concept : Adding random pixel(in start of game.cpp) to the position of the stone(cx, cy) so it can start moving toward the x or y coordinate.
void attackship::velocity()
{
	cx = cx + velox;
	cy = cy + veloy;
}

void attackship::display()
{
	velocity();
	
	//if the object goes below 0 it'll be pushed back to 0 and since console screen is of 800x600 pixel, i did the same for the other sides, they all will be pushed back inside the console screen
	if (cx < 0)
	{
		cx = 0;
		velox = -velox;//if it hits the 0 of x axis it will be pushed back inside the console screen  and start accelerating toward the opposite direction.
	}
	else if (cx + cwidth >= 800)
	{
		cx = 770;
		velox = -velox;
	}


	if (cy < 0)
	{
		cy = 0;
		veloy = -veloy;// SAME AS ABOVE
	}
	else if (cy +cheight >= 600)
	{
		cy = 570;
		veloy = -veloy;
	}


}




// The colliosion concept: following function compares the size of all the sides of the ship with the enemy ship and if any of the sides enters the region of the other then the colliding condition will get true(i.e they're colliding) 


bool attackship::Hitbox( spaceship & boom)
{
	
		if ((boom.thex() + boom.theheight() >= cx ) && (boom.they() + boom.thewidth() >= cy)&&( boom.thex()<=cx+cwidth)&&(boom.they()<=cy+cheight))// comparing different sides.

		{
			boom.countScore(); //counting the score each time ship collide with enemy
			return iscolliding = true;	
		}
		
		
		else
		{ 

			return  false;
		}
	
}

//getters returns function
int attackship::getcx() const
{
	return cx;
}
int attackship::getcy() const
{
	return cy;
}
int attackship::getwidth() const
{
	return cwidth;
}
int attackship::getheight() const
{
	return cheight;
}
int attackship::getvelox() const
{
	return velox;
}
int attackship::getveloy() const
{
	return veloy;
}

void attackship::rec(Graphics & gfx)
{
	gfx.DrawSprite(cx, cy, *alien, Colors::White);
}