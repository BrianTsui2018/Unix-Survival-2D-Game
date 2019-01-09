/**********************************************************************************  
** Program name:	Rogue-like Survival	 			- Final Project -
** Author:  		Brian Tsui
** Date:  			06/12/2017
** Description: 	This is the Header code for Key (derive) Space class.
					Entering this block players get to loot a Key.
					Upon looting, this block is to be replaced with a clear block.
**********************************************************************************/
#include "Key.hpp"
using namespace std;

Key::Key(int N, Space* uPtr, Space* dPtr, Space* lPtr, Space* rPtr)
{
	type = "KEY";
	ID = N;
	up = uPtr;
	down = dPtr;
	left = lPtr;
	right = rPtr;
	player = false;
	enemy = false;
}

int Key::get_ID()
{
	return ID;
}

string Key::line(int)
{
	return " ";
}