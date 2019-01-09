/**********************************************************************************  
** Program name:	Rogue-like Survival	 			- Final Project -
** Author:  		Brian Tsui
** Date:  			06/12/2017
** Description: 	This class holds the struct definitions for Game objects.

**********************************************************************************/

#ifndef GAMEOBJS
#define GAMEOBJS


struct Player
{
	int row;				
	int col;
	int HP;
	int HP_Max;
};

struct Enemy
{
	bool moved;
	bool attacked;
	int row;
	int col;
	int dmg; 
	Enemy (int d)
	{
		dmg = d;
	}
};
struct Container
{
	int max;
	int keys;
	int bread;
	int water;
	int hammer;
	int bread_HP;
	int water_HP;
	
};



#endif