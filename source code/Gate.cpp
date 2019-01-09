/**********************************************************************************  
** Program name:	Rogue-like Survival	 			- Final Project -
** Author:  		Brian Tsui
** Date:  			06/12/2017
** Description: 	This is the Implementation code for Gate (derive) Space class.
					Gate cannot be walked into. It is necessarily the goal block.
					When player is next to this block, the direction command
					becomes "unlock". Upon unlocking, this block is replaced 
					with a clear block
**********************************************************************************/

#include "Gate.hpp"
using namespace std;

Gate::Gate(int N, Space* uPtr, Space* dPtr, Space* lPtr, Space* rPtr)
{
	type = "GATE";
	ID = N;
	up = uPtr;
	down = dPtr;
	left = lPtr;
	right = rPtr;
	player = false;
	enemy = false;
}

int Gate::get_ID()
{
	return ID;
}

string Gate::line(int)
{
	return " ";
}