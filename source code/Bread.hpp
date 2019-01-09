/**********************************************************************************  
** Program name:	Rogue-like Survival	 			- Final Project -
** Author:  		Brian Tsui
** Date:  			06/12/2017
** Description: 	This is the Header code for Water (derive) Space class.
					Entering this block players get to loot a Water.
					Upon looting, this block is to be replaced with a clear block.
**********************************************************************************/

#ifndef BREAD_HPP
#define BREAD_HPP
#include <string>
#include "Space.hpp"

class Bread : public Space
{
	public:
		Bread(int, Space*, Space*, Space*, Space*);
		int get_ID();
		std::string line(int);
};
#endif