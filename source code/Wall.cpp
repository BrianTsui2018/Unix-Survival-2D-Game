/**********************************************************************************  
** Program name:	Rogue-like Survival	 			- Final Project -
** Author:  		Brian Tsui
** Date:  			06/12/2017
** Description: 	This is the Implementatoin code for Wall (derive) Space class.
					Player and Enemies cannot walk into this block.
					Player can break this wall. It takes 3 hits (display changes).
					If player has a hammer, it is broken instantly.
					Upon breaking, this block has a chance to be replaced by an
					item (loot) block, or clear block. 
**********************************************************************************/

#include "Wall.hpp"
#include <iostream>
using namespace std;



Wall::Wall(int N, Space* uPtr, Space* dPtr, Space* lPtr, Space* rPtr)
{
	type = "WALL";
	HP = 3;
	ID = N;
	up = uPtr;
	down = dPtr;
	left = lPtr;
	right = rPtr;
	player = false;
	enemy = false;
}

int Wall::get_HP()
{
	return HP;
}

string Wall::line(int l)
{
	string str;
	if (l == 0)
	{
		str = "         " ;
	}
	else if (l == 1)
	{
		if (HP == 3)
			str = "|||||||| " ;
		else if (HP < 3)
			str = "         " ;
	}
	else if (l == 2)
	{
		if (HP > 1)
			str = "||WALL|| " ;
		else if (HP == 1)
			str = "  wall   " ;
	}
	else if (l == 3)
	{
		str = "|||||||| " ;
	}

	return str;
}

void Wall::bust(int x)
{
	HP -= x;
	if (HP == 2)
	{
		cout << "<Wall>: *Crack*! (need two more hits) " << endl;
	}
	else if (HP == 1)
	{
		cout << "<Wall>: *Crack*!! (need one more hit) " << endl;
	}
	else if (HP == 0)
	{
		cout << "<Wall>: *Crumble*!!!" << endl;
	}
}

int Wall::get_ID()
{
	return ID;
}

