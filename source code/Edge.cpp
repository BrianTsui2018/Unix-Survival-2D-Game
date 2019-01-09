/**********************************************************************************  
** Program name:	Rogue-like Survival	 			- Final Project -
** Author:  		Brian Tsui
** Date:  			06/12/2017
** Description: 	This is the Implementation code for Edge (derive) Space class.
					Edge blocks surrounds the map. They do not get printed.
					When player of enemy attempts to walk into this block, the
					action gets rejected
**********************************************************************************/

#include "Edge.hpp"
using namespace std;

Edge::Edge(int N, Space* uPtr, Space* dPtr, Space* lPtr, Space* rPtr)
{
	type = "EDGE";
	ID = N;
	up = uPtr;
	down = dPtr;
	left = lPtr;
	right = rPtr;
	player = false;
	enemy = false;
}

int Edge::get_ID()
{
	return ID;
}

string Edge::line(int)
{
	return " ";
}