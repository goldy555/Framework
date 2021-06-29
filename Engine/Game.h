/****************************************************************************************** 
 *	Chili DirectX Framework Version 16.07.20											  *	
 *	Game.h																				  *
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
#pragma once

#include "Keyboard.h"
#include "Mouse.h"
#include "Graphics.h"
#include "Spaceship.h"
#include "attackship.h"
#include "Stones.h"
#include "Hpbar.h"
#include "Powerup.h"
#include "Surface.h"
#include <vector>
#include "FrameTimer.h"

class Game
{
public:
	Game( class MainWindow& wnd );
	Game( const Game& ) = delete;
	Game& operator=( const Game& ) = delete;
	void Go();
	static float playerScore;//static variable gets update by the countscore function
	std::string name;
private:
	void ComposeFrame();
	void UpdateModel();
	/********************************/
	/*  User Functions              */
	void drawgameovr(int h, int l);
	void drawstart(int f, int g);
	
	/********************************/
private:
	MainWindow& wnd;
	Graphics gfx;
	/********************************/
	/*  User Variables              */
	
	static constexpr int arr = 3;
	static constexpr int strr = 5;
	FrameTimer ft;
	std::vector<attackship>enemy; //creating objects
	std::vector<stones>stone;
	Surface start = Surface( "Spirtes\\startscreen_(2).bmp" ); // creating surface where sprites can be added
	Surface endgame = Surface ( "Spirtes\\gameovr1.bmp" );
	const Surface alienn = Surface("Spirtes\\alien.bmp");
	const Surface aestroid= Surface ("Spirtes\\aestroid.bmp");
	
	powerup power;
	spaceship boom;
	Hpbar bar;
	bool begin = false;
	bool winner = false;
	bool isDone = false;
	
	/********************************/
};