/****************************************************************************************** 
 *	Chili DirectX Framework Version 16.07.20											  *	
 *	Game.cpp																			  *
 *	Copyright 2016 PlanetChili.net <http://www.planetchili.net>							  *
 *																						  *
 *	This file is part of The Chili DirectX Framework.									  *
 *																						  *
 *	The Chili DirectX Framework is free software: you can redistribute it and/or modify	  *
 *	it under the terms of the GNU General Public License as published by				  *
 *	the Free Software Foundation, either version 3 of the License, or					  *
 *	(at your option) any later version.													  *
 *																						  *
 *	The Chili DirectX Framework is distributed in the hope that it will be useful,		  *
 *	but WITHOUT ANY WARRANTY; without even the implied warranty of						  *
 *	MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the						  *
 *	GNU General Public License for more details.										  *
 *																						  *
 *	You should have received a copy of the GNU General Public License					  *
 *	along with The Chili DirectX Framework.  If not, see <http://www.gnu.org/licenses/>.  *
 ******************************************************************************************/
#include "MainWindow.h"
#include "Game.h"
#include <random>
#include <ctime>
#include <iomanip>
#include <sstream>
#include <fstream>
#include <iostream>
#include <thread>

float Game::playerScore = 0.0;

Game::Game(MainWindow& wnd)
	:
	wnd(wnd),
	gfx(wnd),
	power(rand() % 770, rand() % 550, rand() % 1, rand() % 1)

	{	
	//reserving the number of different  obj inside containers.
	enemy.reserve(arr);
  stone.reserve(strr);



  //creats new elements right after last using args from its constructor
for (int i=0; i < arr; i++)
{
	enemy.emplace_back(rand() % 770, rand() % 570, rand() % 6, rand() % 6,&alienn);
}
for (int i=0; i < strr; i++)
{

	stone.emplace_back(rand() % 760, rand() % 560, rand() % 4, rand() %4, &aestroid);

}

		
}

void Game::Go()
{
	// game loop for the whole the whole program
	
	if (!isDone) {
		gfx.BeginFrame();
		UpdateModel();
		ComposeFrame();
		gfx.EndFrame();
	}
}
void Game::UpdateModel()
{
	//control of the ship  and display function to keep the ship inside the bounds of console screen.
	boom.display();
	boom.control(wnd.kbd);



	//creating hitbox and binding the enemy inside console screen by using display function
	for (int i = 0; i < arr; ++i)
	{
		enemy[i].display();
		
		enemy[i].Hitbox(boom);  

	}
	

	//same function as above but with the logic of ship colliding with asteroid results in decrease of hp bar.
	for (int i = 0; i < strr; ++i)
	{
		stone[i].display();
		stone[i].Hitbox(boom);

		//if its crashing it will call hitpoint func from HP bar class
		if (stone[i].iscrashing_()) {
			bar.hitpoint(stone[i]);
		
		}

	}
	// same as above but with increase in hp instead of decrease 
	{

		power.display();
		power.Hitbox(boom);



		if (power.Hitbox(boom)) {

			bar.gain(power);
			power.iscolliding = true;
			power.neverfalse = false;

		}
		else if (power.iscolliding) {

			power.neverfalse = true;
		}


//Until space is not pressed, Game will not start
		if (wnd.kbd.KeyIsPressed(VK_SPACE)) {
			begin = true;
		}

	}

	
}
	
/// Drawing sprites of start and end screen

void Game::drawgameovr(int h, int l)
{
	gfx.DrawSpriteNonChroma(h, l, endgame);
}

void Game::drawstart(int f, int g)
{
	gfx.DrawSpriteNonChroma(f, g, start);
}





///game logic for drawing moving object spirtes, saving the score in file and making a backup file.
void Game::ComposeFrame()
{
	if (!begin) {
		
		drawstart(25, 20);
		
		// get current local time
		auto t = std::time(nullptr);
		auto tm = *std::localtime (&t);
		
		// format the current local time to a string
		std::ostringstream oss;
		oss << std::put_time(&tm, "%d/%m/%Y %H:%M:%S");

		// assign to our name variable
		name = oss.str();
	}
	else{
		//counter k to calculate how many times ship collided with the enemy
		int k = 0;
		
	
		for (int i = 0; i < strr; i++) {
			stone[i].rec(gfx);
	}	



			if (!power.iscolliding)//drawing power sprite till its not colliding with ship.
			{
				power.rec(gfx);
				
				
			}
	
		for (int i = 0; i < arr; ++i)
		{
			
			//drawing enemy till they are not colliding and increasing counter of k.
			if (!enemy[i].iscolliding) {
			
				enemy[i].rec(gfx);
				
				
			}
			else {
				//updating counter each time they collide
				k++;
			}
			
			
		}
		//makes winner bool true which help in drawing the gameover screeen
		if(k==arr){
			winner = true;


		}
		
		boom.rec(gfx);
		bar.rec(gfx);
		
		///in case any of the following condition got true i.e hp bar became zero or ship destroyed all the enemy, gameover screen will be drawen.
		
		if (bar.gg_() || winner) { 
			drawgameovr(1, 1);
			gfx.EndFrame();


			///Storing algorithm: using file handling to store the score inside a file then using dynamic allocation to make a backup file.
			
			unsigned int count = 0;
			std::ofstream writeHandler;
			std::ifstream readHandler;

			
		
				// write timestamp and score to highscore.txt
				writeHandler.open("scorelist.txt", std::ios::out | std::ios::app );
				writeHandler << name + "-" + std::to_string(roundf(playerScore * 100) / 100) + "\n";
				writeHandler.close();

				// open highscore file 
				readHandler.open("scorelist.txt", std::ios::in);
				// get total lines in highscore file
				int totalLines = std::count(std::istreambuf_iterator<char>(readHandler), std::istreambuf_iterator<char>(), '\n');
				// create dynamic array to store the scores in memory
				std::string *allScores = new std::string[totalLines];
				std::string line;
				int index = 0;
				
				// reset the pointer to the start of the file (moved because of totalLine iterators)
				readHandler.seekg(0);

				// load highscores into memory
				while (std::getline(readHandler, line)) {
					allScores[index++] = line;
				}

				// create a backup for scorelist
				writeHandler.open("score_backup.txt");

				for (int i = 0; i < totalLines; ++i)
					writeHandler << allScores[i] << '\n';

				delete[] allScores;
				
				system("scorelist.txt");
			isDone = true;
		}
		
		
	}
}
