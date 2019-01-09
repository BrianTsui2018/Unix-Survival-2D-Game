/**********************************************************************************  
** Program name:	Rogue-like Survival	 			- Final Project -
** Author:  		Brian Tsui
** Date:  			06/12/2017
** Description: 	This is the Implementation code for Mapper class.
					This class creates map and sets object in it with some random factors.
					Some factors are configurable (for difficulty adjustment).
										
**********************************************************************************/


#include <iostream>
#include "Mapper.hpp"
using namespace std;



SpaceList ** Mapper::map(int D, Player * player, Enemy * zombieA, Enemy * zombieB)
{
	
	dimension = D; 
	
	// Create a 2D map by the dimension provided
	create();
	
	// Set player to starting point (bottom left of the map)
	set_player(player, dimension, 1, new_stage);

	// Set enemies
	set_enemy(zombieA, 1, dice.roll(1, dimension-1), new_stage);					// Enemies should never spawn at row 1 col 10
	set_enemy(zombieB, dice.roll(2, dimension), dimension, new_stage);
		
	// Generate blocks (Space objects)
	set_edge();
	set_gate();
	set_key(1);	
	set_walls(dice.roll(7,10));
	set_bread(1);
	set_water(dice.roll(1,2));
	set_hammer(dice.roll(0,1));
	
	return new_stage;
}

void Mapper::create()
{
	int d = dimension;
	new_stage = new SpaceList* [d+2];				// Total of dimension + 2 rolls (including edges)
	
	// Add Rows
	for (int i = 0; i < d+2 ; i++)
	{
		new_stage[i] = NULL;
		new_stage[i] = new SpaceList;				// This memory will be freed in Game.cpp
	}
	
	// Add Columns 
	for (int r = 0; r < d+2; r++)
	{
		for (int c = 0; c < d+2; c++)
		{
			new_stage[r]-> addTail(r*(d+2)+c);
		}
	}	
	
	// Link up the vertical adjacent Space
	link();
	
}

void Mapper::link()
{
	int d = dimension;
	int above = 0;
	int below = 0;
	Space * linkThis = NULL;
	Space * toThis = NULL;
	
	for (int i = 0 ; i < d+1 ; i++)
	{
		above = i;
		below = i+1;
		
		for (int k = 0; k < d+2; k++)
		{
			linkThis = new_stage[above]->select(k);
			toThis = new_stage[below]->select(k);
			
			linkThis-> down = toThis;
			toThis-> up = linkThis;
			
		}
	}
}

void Mapper::set_player(Player* P, int R, int C, SpaceList** SL)
{
	SpaceList ** stage = SL;
	P->row = R;
	P->col = C;
	(stage[R]->select(C))->set_player(true);	
}


void Mapper::set_edge()
{
	int d = dimension;
	Space * take = NULL;
	Space * make = NULL;

	for (int c = 0; c < d+2 ; c++)
	{
		take = new_stage[0]->select(c);
		make = new Edge(0, NULL, NULL, NULL, NULL);
		new_stage[0]-> replace (take, make);							// After replacing, the previous space that take holds is deleted, and take is set to NULL 
	}

	for (int c = 0; c < d+2 ; c++)
	{	
		take = new_stage[d+1]->select(c);
		make = new Edge(-1, NULL, NULL, NULL, NULL);
		new_stage[d+1]-> replace (take, make);
	}

	for (int r = 1; r < d+1 ; r++)
	{
		take = new_stage[r]->select(0);
		make = new Edge(-1, NULL, NULL, NULL, NULL);
		new_stage[r]-> replace(take, make);

		
		take = new_stage[r]->select(d+1);	
		make = new Edge(-1, NULL, NULL, NULL, NULL);		
		new_stage[r]-> replace(take, make);
	}
}

void Mapper::set_gate()
{
	int d = dimension;
	Space * take = new_stage[1]->select(d);
	Space * make = new Gate(-1, NULL, NULL, NULL, NULL);
	new_stage[1]-> replace (take, make);
}

void Mapper::set_key(int N)
{
	int d = dimension;
	int r = 0;
	int c = 0;
	bool done;
	Space * take = NULL;
	Space * make = NULL;
	for (int i = 0; i < N; i++)
	{
		done = false;
		while(!done)
		{
			r = dice.roll(1,d);
			c = dice.roll(1,d);
			
	
			if ((new_stage[r]->select(c))->get_type() == "CLEAR" && (new_stage[r]->select(c))->has_player() == false && (new_stage[r]->select(c))->has_enemy() == false)
			{
				take = new_stage[r]->select(c);
				make = new Key(-1, NULL, NULL, NULL, NULL);
				new_stage[r]->replace(take, make);
				done = true;
			}	
		}
	}
}

void Mapper::set_walls(int N)
{
	int d = dimension;
	int r = 0;
	int c = 0;
	int length = 0; 							// Length of wall sequence
	int orient = 0; 							// Orientation 0 = horizontal, 1 = vertical
	Space * take = NULL;
	Space * make = NULL;
	
	for (int i = 0; i < N; i++)					// N is the number of wall piece, each can be length 1 to 3
	{
		orient = dice.roll(0,1);
		length = dice.roll(1,3);
		if (orient == 0)
		{ 
			r = dice.roll(1,d);
			c = dice.roll(1,d+1-length);		// Reserve space for adding a longer horizontal wall on the right of the map
		}
		else if (orient == 1)
		{
			r = dice.roll(1,d+1-length);		// Reserve space for adding a longer vertical wall at the bottom of the map
			c = dice.roll(1,d);
		}
		
		for (int l = 0; l < length; l++)
		{
			if ((new_stage[r]->select(c))->get_type() == "CLEAR" && (new_stage[r]->select(c))->has_player() == false && (new_stage[r]->select(c))->has_enemy() == false)
			{
				take = new_stage[r]->select(c);
				make = new Wall(-1, NULL, NULL, NULL, NULL);
				new_stage[r]->replace(take , make);

			}
			
			if (orient == 0)
			{
				c++;
			}
			else if (orient == 1)
			{
				r++;
			}
		}

	}	
}

void Mapper::set_bread(int N)
{
	int d = dimension;
	int r = 0;
	int c = 0;
	bool done;
	Space * take = NULL;
	Space * make = NULL;
		
	for (int i = 0; i < N; i++)
	{
		done = false;
		while(!done)
		{
			r = dice.roll(1,d);
			c = dice.roll(1,d);
			if ((new_stage[r]->select(c))->get_type() == "CLEAR"  && (new_stage[r]->select(c))->has_player() == false && (new_stage[r]->select(c))->has_enemy() == false)
			{
				take = new_stage[r]->select(c);
				make = new Bread(-1, NULL, NULL, NULL, NULL);
				new_stage[r]->replace(take, make);
				done = true;

			}	
		}
	}	
}

void Mapper::set_water(int N)
{
	int d = dimension;
	int r = 0;
	int c = 0;
	bool done;
	Space * take = NULL;
	Space * make = NULL;
			
	for (int i = 0; i < N; i++)
	{
		done = false;
		while(!done)
		{
			r = dice.roll(1,d);
			c = dice.roll(1,d);
			if ((new_stage[r]->select(c))->get_type() == "CLEAR" && (new_stage[r]->select(c))->has_player() == false && (new_stage[r]->select(c))->has_enemy() == false)
			{
				take = new_stage[r]->select(c);
				make = new Water(-1, NULL, NULL, NULL, NULL);
				new_stage[r]->replace( take, make);
				done = true;
			}	
		}
	}	
}

void Mapper::set_hammer(int N)
{
	int d = dimension;
	int r = 0;
	int c = 0;
	bool done;
	Space * take = NULL;
	Space * make = NULL;
	
	for (int i = 0; i < N; i++)
	{
		done = false;
		while(!done)
		{
			r = dice.roll(1,d);
			c = dice.roll(1,d);
			if ((new_stage[r]->select(c))->get_type() == "CLEAR" && (new_stage[r]->select(c))->has_player() == false && (new_stage[r]->select(c))->has_enemy() == false)
			{
				take = new_stage[r]->select(c);
				make = new Hammer(-1, NULL, NULL, NULL, NULL);
				new_stage[r]->replace(take, make);
				done = true;
			}	
		}
	}	
}		

void Mapper::set_enemy(Enemy * E, int R, int C, SpaceList** SL)
{
	SpaceList ** stage = SL;
	E->moved = true;
	E->row = R;
	E->col = C;
	(stage[R]->select(C))->set_enemy(true);
}


void Mapper::set_null()
{
	int d = dimension;

	if (new_stage != NULL)
	{
		for (int i = 0; i < d+2; i++)
		{
			if (new_stage[i] != NULL)
			{
				new_stage[i]->removeAll();
				new_stage[i] = NULL;
			}
		}
		delete [] new_stage;
		new_stage = NULL;
	}
	dimension = 0;
}
