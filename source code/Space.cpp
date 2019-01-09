/**********************************************************************************  
** Program name:	Rogue-like Survival	 			- Final Project -
** Author:  		Brian Tsui
** Date:  			06/12/2017
** Description: 	This is the Implementation code for Space (base) class.
					This is mainly based on lab 6 (Node class)
**********************************************************************************/
#include "Space.hpp"
#include <iostream>
#include <string>
#include "Displayer.hpp"

using namespace std;

/***************************
*					       *
*		Constructor 	   *
*					       *
***************************/
Space::Space()
{
	type = "TEMPLATE";
	ID = -1;
	up = NULL;
	down = NULL;
	left = NULL;
	right = NULL;
	player = false;
	enemy = false;
}
/***************************
*					       *
*		Destructor 	       *
*					       *
***************************/
Space::~Space()
{
	
}

/***************************
*					       *
*		Accessors	       *
*					       *
***************************/

int Space::get_ID()
{
	return ID;
}

string Space::get_type()
{
	return type;
}

bool Space::has_player()
{
	return player;
}

void Space::set_player(bool B)
{
	player = B;
}
	
bool Space::has_enemy()
{
	return enemy;
}

void Space::set_enemy(bool B)
{
	enemy = B;
}

/***********************************************
*					                           *
*		Action Generator and Validation	       *
*					                           *
***********************************************/
Space * Space::action()
{
	Validate val;
	bool confirm = false;
	char choice;
	Space * aTarget; 
	
	/*------------------------------------
		
		Returns a Space pointer 
		pointing to where the player
		choose to interact
		
	------------------------------------*/
	while (!confirm)
	{
		/*------------------------------------
			Display Options (Dynamic)
		------------------------------------*/
		
		cout 	<< "Action ------------------------------------- " << endl
				<< "      [W]" << endl
				<< "       ^ " << endl
				<< "[A] <     > [D]" << endl
				<< "       v"  << endl
				<< "      [S]" << endl
				<< "Options: "<< endl
				<< "[W] UP ^ " << check_space(up) << " \t\t\t"
				<< "[A] LEFT < " << check_space(left) << endl 
				<< "[D] RIGHT > " << check_space(right) << "\t\t\t"
				<< "[S] DOWN v " << check_space(down) << endl
				<< "Items in Invetory: " << endl
				<< "[1]  Inspect <Key> " << "\t\t"
				<< "[2]  Eat <Bread> " << "\t\t"
				<< "[3]  Drink <Water> " <<  "\t\t"
				<< "[4]  Inspect <Hammer> " << endl;
		
		/*------------------------------------
			Input (with char validation)
		------------------------------------*/
		choice = toupper(val.qC("[?]Enter an [ ] Option: "));

		
		/*--------------------------------------------
			Partial Validation for each direction
		--------------------------------------------*/
		if (choice == 'W')
		{
			aTarget = up;
			confirm = confirm_movement(up);
		}
		else if (choice == 'A')
		{
			aTarget = left;
			confirm = confirm_movement(left);
		}
		else if (choice == 'S')
		{
			aTarget = down;
			confirm = confirm_movement(down);
		}
		else if (choice == 'D')
		{
			aTarget = right;
			confirm = confirm_movement(right);
		}
		else if (choice == '1' || choice == '2' || choice == '3' || choice == '4')
		{
			aTarget = NULL;
			confirm = true;					/* When this is called, it is called from outside. 
											/* This is when player uses an item. (or call for instruction)
											/* Do not use confirm action or it would take the wrong last_choice */
		}
		else 
		{
			cout << endl << "[!] Invalid input, please try again. " << endl << endl;
			confirm = false;
		}
		last_choice = choice;
	}

	return aTarget;
}



bool Space::confirm_movement(Space* ptr)			
{
	/*---------------------------------------
	
		The player is attempting to move
		to a neighbouring block.
		Check if its available to do so.
		
	---------------------------------------*/	
	
	string s = check_space(ptr);
	
	
	if ( s == "--")							//Player walking into an Edge
	{
		cout << "[!]Cannot proceed: it is the edge!" << endl;
		return false;
	}
	else if ( s == "!!!")					//Player walking into a space that is occupied by an enemy
	{
		cout << "[!]Cannot proceed: there is an enemy!" << endl;
		return false;
	}
	return true;
}



string Space::check_space(Space* direction)	 		
{
	/*-------------------------------------------------
	
		Generates a code that represents the 
		next action according to the user input.
		The Space that the direction is point to 
		affects the outcome. 
		
	-------------------------------------------------*/
	string check;
	string S;
	
	if (direction == up)
	{
		S = "up";
	}
	else if (direction == down)
	{
		S = "down";
	}
	else if (direction == left)
	{
		S = "left";
	}
	else if (direction == right)
	{
		S = "right";
	}
	
	if (direction == NULL)
	{
		if (last_choice == '1')
		{
			check = "Key";
		}
		else if (last_choice == '2')
		{
			check = "Bread";
		}
		else if (last_choice == '3')
		{
			check = "Water";
		}
		else if (last_choice == '4')
		{
			check = "Hammer";
		}
		else 
		{
			check = "NULL";
		}
	}
	else if (direction-> has_enemy())
	{	
		check = "!!!";
	}		
	else
	{
		string T = direction->type;
		if (T == "CLEAR")
		{
			check = "Go "+S;
		}
		else if (T == "BREAD")
		{
			check = "Go "+S;
		}
		else if (T == "WATER")
		{
			check = "Go "+S;
		}
		else if (T == "KEY")
		{
			check = "Go "+S;
		}
		else if (T == "HAMMER")
		{
			check = "Go "+S;
		}
		else if (T == "GATE")
		{
			check = "Unlock <Gate>";
		}
		else if (T == "WALL")
		{
			check = "Bust <Wall>";
		}
		else if (T == "EDGE")
		{
			check = "--";
		}
	}
	return check;
}

// For specific derived classes only
string Space::line(int)
{
	return " ";
}

/*******************************
*					           *
*		Debug functions	       *
*				               *
*******************************/	

void Space::cast()
{
	Space * ptr = NULL;
	cout << "My ID : "<< ID << endl;

	if (right != NULL)
	{
		ptr = right;
		cout << "right Cast : ";
		while (ptr->right != NULL)
		{	
			cout <<	ptr->get_ID() << " " ;
			ptr = ptr->right;
		}
		cout << endl;
	}		
	if (down != NULL)
	{
		ptr = down;
		cout << "down Cast : ";
		while (ptr->down != NULL)
		{	
			cout <<	ptr->get_ID() << " " ;
			ptr = ptr->down;
		}
		cout << endl;
	}
}	
	
	
void Space::debug()
{
	cout 	<< "[System] Created Space type : " << type << " >> ID : " << ID << " >> ";
	
	if (up != NULL)
		cout << " up = " << up-> ID << " / ";
	else
		cout << " up = NULL / ";

	if (down != NULL)
		cout << " down = " << down-> ID << " / ";
	else
		cout << " down = NULL / ";

	if (left != NULL)
		cout << " left = " << left-> ID << " / ";
	else
		cout << " left = NULL / ";
	
	if (right != NULL)
		cout << " right = " << right-> ID << " / ";
	else
		cout << " right = NULL / ";
	
	cout << endl;
}

	
	
	
	
	