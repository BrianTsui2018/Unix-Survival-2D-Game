/**********************************************************************************  
** Program name:	Rogue-like Survival	 			- Final Project -
** Author:  		Brian Tsui
** Date:  			06/12/2017
** Description: 	This is the Header code for Clear (derive) Space class.

**********************************************************************************/

#ifndef CLEAR_HPP
#define CLEAR_HPP
#include "Space.hpp"
#include <string>

class Clear : public Space
{
	public:
		Clear(int, Space*, Space*, Space*, Space*);
		int get_ID();
		std::string line(int);

};
#endif