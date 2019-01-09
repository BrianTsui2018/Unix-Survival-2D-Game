/**********************************************************************************  
** Program name:	Rogue-like Survival	 			- Final Project -
** Author:  		Brian Tsui
** Date:  			06/12/2017
** Description: 	This is the Header code for Space (base) class.
					This is mainly based on lab 6 (Node class)
**********************************************************************************/

#ifndef SPACE_HPP
#define SPACE_HPP
#include "Validate.hpp"
#include <string>

class Space
{
	protected:
		int ID;					// Represents the column in the row it belongs
		std::string type;		// Space Type	
								/*--------------------------------
									Types: 
										CLEAR
										GATE
										KEY
										BREAD
										WATER
										WALL
										EDGE
										HAMMER
								--------------------------------*/
		bool player;			// False if player is here
		bool enemy;				// True if enemy is here
		char last_choice;		// Records the last chosen option
		
	public:
		Space * up;
		Space * down;
		Space * right;
		Space * left;

		Space();
		~Space();
		
		virtual int get_ID() = 0;				// Return block ID as an Int
		std::string get_type();					// Return block type as String
		bool has_player();						// Returns true if this Space is where player currently is
		void set_player(bool);					// Sets this space to where player currently is
		bool has_enemy();						// Returns true if this Space currently has an enemy occupying
		void set_enemy(bool);					// Sets this space that an enemy occupies
				
		Space* action ();						// Generate display of available action according to situation, prompts input
		bool confirm_movement(Space*);			// Check if player is attempting to walk into an Edge or Enemy
		std::string check_space(Space*);		// Generates a string command from the valid next action (for Game.cpp to execute)
		virtual std::string line(int) = 0;		// Unique function for some derived class to perform
		
		// Debug functions
		void debug(); 
		void print_all_ID();
		void cast();
};
#endif