/**********************************************************************************  
** Program name:	Rogue-like Survival	 			- Final Project -
** Author:  		Brian Tsui
** Date:  			06/12/2017
** Description: 	This is the Header code for Gate (derive) Space class.
					Gate cannot be walked into. It is necessarily the goal block.
					When player is next to this block, the direction command
					becomes "unlock". Upon unlocking, this block is replaced 
					with a clear block
**********************************************************************************/

#ifndef GATE_HPP
#define GATE_HPP
#include <string>
#include "Space.hpp"

class Gate : public Space
{
	public:
		Gate(int, Space*, Space*, Space*, Space*);
		int get_ID();
		std::string line(int);
};
#endif