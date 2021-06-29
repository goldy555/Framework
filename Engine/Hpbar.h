#pragma once

#include "Stones.h"
#include "Powerup.h"
 


class Hpbar  {

public:
	//constructors
	Hpbar();
	Hpbar(int l, int m, int lwidth, int mheight, int count);
	//Functions
	void rec(Graphics &gfx);
	bool hitpoint(const stones &stone);
	bool gain(const powerup &power);
	bool gg_()const;

private:
	//variables
	int a = 20;
	int b = 20;
	int counter = 0;
	int nwidth = 100;
	int nheight = 10;
	bool gg = false;
	bool isdone = false;
	bool temp = true;




};