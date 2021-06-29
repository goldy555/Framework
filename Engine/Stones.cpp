#include "Stones.h"
//constructors
stones::stones():asteroid(nullptr)
{
}

stones::stones(int kx, int ky, int xvel, int yvel,const Surface *asteroid): lx(kx), ly(ky), xvelo(xvel), yvelo(yvel), asteroid(asteroid)
{
	

}
//drawing the stone spirtes
void stones::rec(Graphics & gfx)
{
	gfx.DrawSprite(lx, ly, *asteroid, Colors::White);
}
///Velocity Concept: Adding random pixel(in start of game.cpp) to the position of the stone(x,y) so it can start moving toward the x or y coordinate.
void stones::velocity()
{
	lx = lx + xvelo;
	ly = ly + yvelo;
}

void stones::display()
{

	velocity();


	if ( lx < 0)
	{
		lx = 0;
		xvelo = -xvelo;//if it hits the 0 of x axis it will deaccelerate and start accelerating toward the opposite direction
	}
	else if ( lx + lwidth >= 800)
	{
		lx = 779;
		xvelo = -xvelo;
	}


	if (ly < 0)
	{
		ly = 0;
		yvelo = -yvelo;// SAME AS ABOVE
	}
	else if ( ly + lheight >= 600)
	{
		ly = 579;
		yvelo = -yvelo;
	}

	


}


///hitbox concept/collison concept: same as for the attackship
bool stones::Hitbox(spaceship & boom)
{
	if ((boom.thex() + boom.theheight() >= lx) && (boom.they() + boom.thewidth() >= ly) && (boom.thex() <= lx + lwidth) && (boom.they() <= ly + lheight))

	{
		
		return iscrashing = true;

	}


	else
	{

		return iscrashing = false;
	}
}

//getters

int stones::newx() const
{
	return lx;
}

int stones::newy() const
{
	return ly;
}

int stones::newwidth() const
{
	return lwidth;
}

int stones::newheight() const
{
	return lheight;
}

int stones::newxvelo() const
{
	return xvelo;
}

int stones::newyvelo() const
{
	return yvelo;
}

bool stones::iscrashing_() const
{
	return iscrashing;
}

