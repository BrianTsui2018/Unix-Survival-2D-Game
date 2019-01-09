/**********************************************************************************  
** Program name:	Rogue-like Survival	 			- Final Project -
** Author:  		Brian Tsui
** Date:  			06/12/2017
** Description: 	This is the Implementation code for Clear (derive) Space class.

**********************************************************************************/

#include "Clear.hpp"

using namespace std;

Clear::Clear(int N, Space* uPtr, Space* dPtr, Space* lPtr, Space* rPtr)
{
	type = "CLEAR";
	ID = N;
	up = uPtr;
	down = dPtr;
	left = lPtr;
	right = rPtr;
	player = false;
	enemy = false;
}

int Clear::get_ID()
{
	return ID;
}

string Clear::line(int)
{
	return " ";
}