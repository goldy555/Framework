#include "Hpbar.h"
#include <iostream>

// constructors
Hpbar::Hpbar()
{
}

Hpbar::Hpbar(int l, int m, int lwidth, int mheight, int count)
{
	a = l;
	b = m;
	nwidth = lwidth;
	nheight = mheight;
	counter = count;

}

///drawing function for HP bar with the addition property of getting shorter and longer acc to the other function interconnected with it + Excepton Handling for safe check.
void Hpbar::rec(Graphics & gfx)
{
	try {

		int xe = a + nwidth + counter;// the counter will increase and decrease based on the crashing and colliding via gain and hitpoint function 


		int j;

		for (int i = b; i < b + nheight; i++)
		{
			for (j = a; j < (xe); j++)
			{
				gfx.PutPixel(j, i, 0, 153, 0);


			}
		}
		if (j > xe)
		{
			gg = true;
			
		}
		else if (j > xe)
		{
			throw temp;
		}
	}
	
	catch ( std::exception& temp)
	{
		
		std::cout << "invalid";

	}
		

	
	
}


///The Hp bar algorithm: the follwing function works as if its colliding with the power then the counter will make the hp bar refill but if its crashing with stone then the counter will decrese with -5 rate
bool Hpbar::hitpoint(const stones &stone)
{
	if (stone.iscrashing_() )
	{

		return counter += -5;

	}
	else {
		return false;
	}

}

bool Hpbar::gain( const powerup & power)
{
	
	if (power.iscolliding && !power.neverfalse) // neverfalse bool condition serve as one time permanent  refill of hp and  then the bool is set to be nevertrue again
	{
		return counter = 1;
		
	}
	else if (!power.iscolliding && power.neverfalse) {
		return counter =0;
	}
}
//getter
bool Hpbar::gg_() const
{
	return gg;
}




