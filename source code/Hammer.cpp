/**********************************************************************************  
** Program name:	Rogue-like Survival	 			- Final Project -
** Author:  		Brian Tsui
** Date:  			06/12/2017
** Description: 	This is the Implementation code for Hammer (derive) Space class.
					Entering this block players get to loot a Hammer.
					Upon looting, this block is to be replaced with a clear block.
**********************************************************************************/
#include "Hammer.hpp"
using namespace std;

Hammer::Hammer(int N, Space* uPtr, Space* dPtr, Space* lPtr, Space* rPtr)
{
	type = "HAMMER";
	ID = N;
	up = uPtr;
	down = dPtr;
	left = lPtr;
	right = rPtr;
	player = false;
	enemy = false;
}

int Hammer::get_ID()
{
	return ID;
}

string Hammer::line(int)
{
	return " ";
}