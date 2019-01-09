/**********************************************************************************  
** Program name:	Rogue-like Survival	 			- Final Project -
** Author:  		Brian Tsui
** Date:  			06/12/2017
** Description: 	This is the Header code for Key (derive) Space class.
					Entering this block players get to loot a Key.
					Upon looting, this block is to be replaced with a clear block.
**********************************************************************************/
#ifndef KEY_HPP
#define KEY_HPP
#include <string>
#include "Space.hpp"

class Key : public Space
{
	public:
		Key(int, Space*, Space*, Space*, Space*);
		int get_ID();
		std::string line(int);
};
#endif