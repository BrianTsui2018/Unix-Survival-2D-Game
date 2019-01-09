/**********************************************************************************  
** Program name:	Rogue-like Survival	 			- Final Project -
** Author:  		Brian Tsui
** Date:  			06/12/2017
** Description: 	This is the Implementation code for Water (derive) Space class.
					Entering this block players get to loot a Water.
					Upon looting, this block is to be replaced with a clear block.
**********************************************************************************/

#include "Water.hpp"
using namespace std;
Water::Water(int N, Space* uPtr, Space* dPtr, Space* lPtr, Space* rPtr)
{
	type = "WATER";
	ID = N;
	up = uPtr;
	down = dPtr;
	left = lPtr;
	right = rPtr;
	player = false;
	enemy = false;
}

int Water::get_ID()
{
	return ID;
}

string Water::line(int)
{
	return " ";
}


