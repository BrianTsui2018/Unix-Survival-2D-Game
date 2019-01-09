/**********************************************************************************  
** Program name:	Rogue-like Survival	 			- Final Project -
** Author:  		Brian Tsui
** Date:  			06/12/2017
** Description: 	This is the Header code for Displayer class.
					This class handles most of the display functions.
					It takes in the SpaceList** 2D map, and pointers to player 
					and inventory for printing information.
					After using once with parameters passed in, 
					the consequent use can be called without parameters (using last 
					cached information, assuming caller class did not reset pointers)
										
**********************************************************************************/

#ifndef DISPLAYER
#define DISPLAYER
#include <string>
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


class Displayer
{
	private:
		Player* P;
		Container* INV;
		SpaceList** copy;
		int copy_row;
		int copy_col;
		
	public:
		void set_player(Player*);				//Sets the player object
		void set_inv(Container*);				//Sets the inventory container object
		void gameover();						//Display gameover message
		void attacked(Enemy*);					//Display when player gets hit. Needs to know Player's HP and Max HP, and Enemy's attack damage
		void level_complete();					//Display when level transition. Needs to know player's HP and Max HP
		void print();							//Displays the map and objects
		void print(SpaceList**, int, int);		//Displays the main UI every round_error. Needs the dimension of the stage
		void print_all_ID(SpaceList**, int, int);		//Displays all the ID of every Space in all SpaceLists (the stage). For debugging purposes. Needs the dimension of the stage.
		void vertical_traverse_print(SpaceList**, int, int);	//Displays all the ID with a vertical traverse, to check if the map is vertically linked
		void key();								//Inspect Key
		void hammer();							//Inspect Hammer
		void no_bread();						//Cannot use Bread
		void no_water();						//Cannot use Water
		void no_key();							//Cannot use Key
		void prompt_hammer();					//To use Hammer?
		void got_bread();						//Obtained a Bread
		void got_water();						//Obtained a Water
		void got_hammer();						//Obtained a Hammer
		void got_key();							//Obtained a Key
		void full();							//Cannot put in Inventory because this item reached max capacity
		void recover(int);						//Display how much HP has been healed
		void show_HP();							//Displays Current HP
		void hold();							//Prompts wait
		void hold(std::string);					//Prompts wait with custom message
		void instruction();
};

#endif