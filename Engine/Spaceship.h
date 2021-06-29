#pragma once
#include "Keyboard.h"
#include "Graphics.h"
#include <chrono>
#include "Vec2.h"
//#include "Surface.h"

class spaceship {
public:

	virtual void display();
	void control(const Keyboard & kbd);
	void countScore();
	virtual void rec(Graphics &gfx);
	//getters
	int thex() const;
	int they() const;
	int thewidth() const;
	int theheight() const;
	int elapsed() const;

private:
	//variables
	int x = 400;
	int y = 300;
	int width = 30;
	int height = 30;
	Surface ship = Surface("Spirtes\\shuttle2.bmp");
	std::chrono::steady_clock::time_point start = std::chrono::steady_clock::now();
	
	
	







};
