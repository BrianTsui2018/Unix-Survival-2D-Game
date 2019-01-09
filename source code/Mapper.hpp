/**********************************************************************************  
** Program name:	Rogue-like Survival	 			- Final Project -
** Author:  		Brian Tsui
** Date:  			06/12/2017
** Description: 	This is the Header code for Mapper class.
					This class creates map and sets object in it with some random factors.
					Some factors are configurable (for difficulty adjustment).
										
**********************************************************************************/

#ifndef MAPPER
#define MAPPER
#include "Die.hpp"
#include "SpaceList.hpp"
#include "Space.hpp"
#include "Clear.hpp"
#include "Bread.hpp"
#include "Water.hpp"
#include "Hammer.hpp"
#include "Key.hpp"
#include "Gate.hpp"
#include "Edge.hpp"
#include "Wall.hpp"
#include "GameObjs.hpp"
#include <string>


class Mapper
{
	private:
		SpaceList ** new_stage;
		int dimension;
		Die dice;

	public:
		SpaceList ** map(int, Player*, Enemy*, Enemy *);
		void create();			// Creates empty 2D map (with Clear type Space)
		void link();			// Links the vertically adjacent Spaces
		void set_edge();		// set Edge blocks
		void set_gate();		// set Gate block
		void set_key(int);		// set Key blocks
		void set_walls(int);	// set Wall blocks
		void set_bread(int);	// set Breads
		void set_water(int);	// set Waters
		void set_hammer(int);	// set Hammers
		void set_player(Player*, int, int, SpaceList**);	//set player
		void set_enemy(Enemy *, int, int, SpaceList**);		//set an enemy
		void set_null();		// reset to null, deletes current stage (SpaceList)
};

#endif
