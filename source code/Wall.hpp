/**********************************************************************************  
** Program name:	Rogue-like Survival	 			- Final Project -
** Author:  		Brian Tsui
** Date:  			06/12/2017
** Description: 	This is the Header code for Wall (derive) Space class.
					Player and Enemies cannot walk into this block.
					Player can break this wall. It takes 3 hits (display changes).
					If player has a hammer, it is broken instantly.
					Upon breaking, this block has a chance to be replaced by an
					item (loot) block, or clear block. 
**********************************************************************************/

#ifndef WALL_HPP
#define WALL_HPP
#include <string>
#include "Space.hpp"
class Wall : public Space
{
	private: 
		int HP;						//Hit point of the wall
	public:
		Wall(int, Space*, Space*, Space*, Space*);
		
		int get_HP();
		int get_ID();
		void bust(int);
		std::string line(int);

};
#endif