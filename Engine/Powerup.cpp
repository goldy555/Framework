#include "Powerup.h"





//constructors
powerup::powerup()
{
}

powerup::powerup(int ab, int cd, int ef, int gh) 
{
}
//Custom Hitbox for powerup 
bool powerup::Hitbox(spaceship & boom)
{

	if ((boom.thex() + boom.theheight() >= getcx()) && (boom.they() + boom.thewidth() >= getcy()) && (boom.thex() <= getcx() + getwidth()) && (boom.they() <= getcy() + getheight()))

	{
		
		return iscolliding = true;
	}


	else
	{

		return false;
	}

}



//drawing function

void powerup::rec(Graphics & gfx)
{

	gfx.DrawSprite(getcx(), getcy(), medkit, Colors::White);

}

