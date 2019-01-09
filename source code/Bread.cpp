/**********************************************************************************  
** Program name:	Rogue-like Survival	 			- Final Project -
** Author:  		Brian Tsui
** Date:  			06/12/2017
** Description: 	This is the Implementation code for Bread (derive) Space class.
					Entering this block players get to loot a Bread.
					Upon looting, this block is to be replaced with a clear block.
**********************************************************************************/

#include "Bread.hpp"
using namespace std;

Bread::Bread(int N, Space* uPtr, Space* dPtr, Space* lPtr, Space* rPtr)
{
	type = "BREAD";
	ID = N;
	up = uPtr;
	down = dPtr;
	left = lPtr;
	right = rPtr;
	player = false;
	enemy = false;
}


int Bread::get_ID()
{
	return ID;
}

string Bread::line(int)
{
	return " ";
}