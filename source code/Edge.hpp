/**********************************************************************************  
** Program name:	Rogue-like Survival	 			- Final Project -
** Author:  		Brian Tsui
** Date:  			06/12/2017
** Description: 	This is the Header code for Edge (derive) Space class.
					Edge blocks surrounds the map. They do not get printed.
					When player of enemy attempts to walk into this block, the
					action gets rejected
**********************************************************************************/
#ifndef EDGE_HPP
#define EDGE_HPP
#include "Space.hpp"
#include <string>

class Edge : public Space
{
	public:
		Edge(int, Space*, Space*, Space*, Space*);
		int get_ID();
		std::string line(int);
};
#endif