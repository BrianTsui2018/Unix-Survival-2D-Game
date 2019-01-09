/**********************************************************************************  
** Program name:	Rogue-like Survival	 			- Final Project -
** Author:  		Brian Tsui
** Date:  			06/12/2017
** Description: 	This is the Header code for Hammer (derive) Space class.
					Entering this block players get to loot a Hammer.
					Upon looting, this block is to be replaced with a clear block.
**********************************************************************************/

#ifndef HAMMER_HPP
#define HAMMER_HPP
#include <string>
#include "Space.hpp"

class Hammer : public Space
{
	public:
		Hammer(int, Space*, Space*, Space*, Space*);
		int get_ID();
		std::string line(int);
};
#endif