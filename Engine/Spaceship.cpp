#include "Spaceship.h"
#include "Graphics.h"
#include "Game.h"


/// Display function to keep the ship and other objects inside the console screen...
void spaceship::display()
{
	
	
	//incase it goes below 0 or = to 0 then the x coordinate will be set to zero
		if (x < 0)
		{
			x = 0;
		}

		//while considering the width of obj in any case if it goes beyond the console limits 800 it will be set back to 779
		else if (x + width >= 800)
		{
			x = 770;
		}

		//same as above but in y-axis
		if (y < 0)
		{
			y = 0;
		}
		else if (y + height >= 600)
		{
			y = 570;
		}
	}
	


///User-controlled movement: adds or subtract 2 pixels if condition with up,down,left,right arrow keys gets true to move the ship

void spaceship::control( const Keyboard & kbd)
{
	if (kbd.KeyIsPressed(VK_RIGHT)) {
		x += 2;
	}
	if (kbd.KeyIsPressed(VK_LEFT)) {
		x -= 2;
	}
	if (kbd.KeyIsPressed(VK_DOWN)) {
		y += 2;
	}
	if (kbd.KeyIsPressed(VK_UP)) {
		y -= 2;
	}



}
//getters
int spaceship::thex() const
{
	return x;
}

int spaceship::they() const
{
	return y;
}

int spaceship::thewidth() const
{
	return width;
}

int spaceship::theheight() const
{
	return height;
}

int spaceship::elapsed() const
{
	return std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::steady_clock::now() - start).count();
}

void spaceship::rec(Graphics & gfx)
{
	
	gfx.DrawSprite(x, y, ship, Colors::White);
	}


///CountingScore Algorithm: This function is used to count score according to the time ship took to reach and collide with the enemy ship. Every enemy is already alloacated with 50 points.
void spaceship::countScore() {
	int elapsedTime = elapsed();
	elapsedTime = (elapsedTime == 0) ? 1 : elapsedTime;// condition in case denominator become 0;
	Game::playerScore += 50 / elapsedTime; // dividing with the time elasped(took the player to get to enemy)
	start =  std::chrono::steady_clock::now();
	
}  



