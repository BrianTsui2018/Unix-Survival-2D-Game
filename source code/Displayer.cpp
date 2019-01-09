/**********************************************************************************  
** Program name:	Rogue-like Survival	 			- Final Project -
** Author:  		Brian Tsui
** Date:  			06/12/2017
** Description: 	This is the Implementation code for Displayer class.
					This class handles most of the display functions.
					It takes in the SpaceList** 2D map, and pointers to player 
					and inventory for printing information.
					After using once with parameters passed in, 
					the consequent use can be called without parameters (using last 
					cached information, assuming caller class did not reset pointers)
										
**********************************************************************************/

#include <string>
#include <iostream>
#include "Displayer.hpp"
#include <stdlib.h>



using namespace std;

void Displayer::set_player(Player* ptr)
{
	P = ptr;
}

void Displayer::set_inv(Container * ptr)
{
	INV = ptr;
}

void Displayer:: gameover() 						//Display when player dies
{
	print();
	cout << endl;
	cout << "[X][X][X][X][X][X][X][X][X][X][X][X][X][X][X][X][X]" << endl;
	cout << "[X]                                             [X]" << endl;
	cout << "[X]                                             [X]" << endl;
	cout << "[X]           Y O U   A R E   D E A D           [X]" << endl;
	cout << "[X]                                             [X]" << endl;
	cout << "[X]              GAME      OVER                 [X]" << endl;
	cout << "[X]                                             [X]" << endl;
	cout << "[X]                                             [X]" << endl;
	cout << "[X][X][X][X][X][X][X][X][X][X][X][X][X][X][X][X][X]" << endl;
	cout << endl << endl;
	hold();
}


void Displayer:: attacked(Enemy* E)					//Display when player gets hit. Needs to know Player's HP and Max HP, and Enemy's attack damage
{
	string DD = " ";
	string D = to_string(E->dmg);
	
	if (E->dmg < 10)
		DD = D;
	else
		DD = DD + D;

	cout<< "[X]---------------------------------------------[X]" << endl
		<< "[X]\\  //\\  //\\  //\\  //\\  //\\  //\\  //\\  //\\  //[X]" << endl
		<< "[X] \\//  \\//  \\//  \\//  \\//  \\//  \\//  \\//  \\// [X]" << endl
		<< "[X]     [!!!] ARGH!! Zombie attacked you!       [X]" << endl
		<< "[X]     [-] Health Points -" << DD << "!                 [X]" << endl
		<< "[X] /\\\\  /\\\\  /\\\\  /\\\\  /\\\\  /\\\\  /\\\\  /\\\\  /\\\\ [X]" << endl
		<< "[X]/  \\\\/  \\\\/  \\\\/  \\\\/  \\\\/  \\\\/  \\\\/  \\\\/  \\\\[X]" << endl
		<< "[X]---------------------------------------------[X]" << endl
	 << endl;			
		show_HP();

	cout << endl << endl;
	hold();
}


void Displayer::level_complete()					//Display when level transition. Needs to know player's HP and Max HP
{
	print();
	cout<< endl << endl  ;
	cout<< "[V]||||||||||||||||||||||||||||||||||||||||[V]" << endl
		<< "                                              " << endl
		<< "         L e v e l      C l e a r             " << endl
		<< "                                              " << endl
		<< "               next    floor                  " << endl
		<< "                                              " << endl
		<< "[V]||||||||||||||||||||||||||||||||||||||||[V]" << endl		
		<< endl << endl;			
		
		show_HP();

	cout << endl << endl;
	hold();
}

void Displayer::print()
{
	print(copy, copy_row, copy_col);
}

void Displayer::print(SpaceList**stage, int row, int col)					//Displays the main UI every round_error. Needs the dimension of the stage
{
	string T;
	copy = stage;
	copy_row = row;
	copy_col = col;
	bool P = false;
	bool E = false;
	int d = 10;
	if (row == col)
	{
		d = row;
	}
	system("cls");
	
	
	/* 
		Print Status and Inventory
	*/
	cout << endl << endl << endl << endl;
	cout << "___________" << endl;
	cout << "INVENTORY  \\_______________________________________________________________________________________" << endl;
	cout << "<Key> x "<<INV->keys<<" / 3     <Bread> x "<<INV->bread<<" / 3        <Water> x "<<INV->water<<" / 3       <Hammer> x "<<INV->hammer<<" / 3    " << endl;
	cout << endl << endl;
	
	/* 
		Print the rest of the map, without "Edge" Space	
	*/
	for (int r = 1; r < d+1 ; r++)
	{
		for (int i = 0; i < 4; i++)
		{
			for (int c = 1; c < d+1 ; c++)
			{
				T = (stage[r]->select(c))-> get_type();
				P = (stage[r]->select(c))-> has_player();
				E = (stage[r]->select(c))-> has_enemy();
				
				if (i == 0)
				{
					if (E == true)
					{
						cout << "         " ;
					}
					else if (T == "WALL")
					{
						cout << (stage[r]->select(c))->line(i) ;
					}
					else 
					{
						cout << " ______  " ;					
					}
				}
				else if (i == 1)
				{
					if (T == "WALL")
					{
						cout << (stage[r]->select(c))->line(i) ;					
					}
					else if (P == true)
					{
						cout << "|x * x | " ;
					}
					else if (E == true)
					{
						cout << "  _____  " ;
					}
					else if (T == "BREAD")
					{
						cout << "((     ) " ;
					}
					else if (T == "WATER")
					{
						cout << "| [~~] | " ;
					}
					else
					{
						cout << "|      | " ;
					}
				}
				else if (i == 2)
				{
					if (P == true)
					{
						cout << "|*YOU* | " ;	
					}
					else if (E == true)
					{
						cout << " (o   0) " ;							
					}
					else 
					{
						if (T == "WALL")
						{
							cout << (stage[r]->select(c))->line(i) ;					
						}
						else if (T == "GATE")
						{
							cout << "| GATE | " ;
						}
						else if (T == "BREAD")
						{
							cout << "||BREAD| " ;
						}
						else if (T == "WATER")
						{
							cout << "| WATER| " ;
						}
						else if (T == "KEY")
						{
							cout << "|O==KEY| " ;
						}
						else if (T == "HAMMER")
						{
							cout << "|HAMMER| " ;
						}
						else if (T == "CLEAR")
						{
							cout << "|      | " ;
						}
					}
				}
				else if (i == 3)
				{		
					if (T == "WALL")
					{
						cout << (stage[r]->select(c))->line(i) ;					
					}
					else if (P == true)
					{
						cout << "|__*___| " ;
					}
					else if (E == true)
					{
						cout << "  [VVV]  " ;
					}
					else if (T == "BREAD")
					{
						cout << "||____|| " ;
					}
					else if (T == "WATER")
					{
						cout << "|_[__]_| " ;
					}
					else
					{
						cout << "|______| " ;
					}
				}

			}

		
			if ( r == 1 )					// Print "Exit" at the end
			{
				if (i == 0)
				{
					cout << " ______  " ;
				}
				else if (i == 1)
				{
					cout << "| /  \\ | " ;
				}
				else if (i == 2)
				{
					cout << "|/EXIT\\| " ;
				}
				else if (i == 3)
				{
					cout << "|______| " ;
				}
			}
		cout << endl;					// end line when every column in that row is printed
		}
	}
	cout << endl;
}

void Displayer::print_all_ID(SpaceList** stage, int row, int col)					//Displays all the ID of every Space in all SpaceLists (the stage). For debugging purposes. Needs the dimension of the stage.
{
	int d = 10;
	if (row == col)
	{
		d = row;
	}
	
	cout << "[Game Debug]-------------------------------------------------------" << endl;
	for (int i = 0; i < d+2; i++)
	{
		stage[i]->traversePrint();
	}
	cout << "-------------------------------------------------------------------" << endl;		
}

void Displayer::vertical_traverse_print(SpaceList** stage, int row, int col)		//Displays all the ID with a vertical traverse, to check if the map is vertically linked
{
	int d = 10;
	if (row == col)
	{
		d = row;
	}
	
	cout << "[Game Debug]-------------------------------------------------------" << endl;

	if(stage[0]->select(0) == NULL)
	{
		cout << "Error: cannot find first row! " << endl;
	}
	else
	{
		for (int c = 0; c < d+2; c++)
		{
			for (int r = 0; r < d+2; r++)
			{
				cout << (stage[r]->select(c))->get_ID() << " " ;		
			}
			cout << endl;
		}
	}
	cout << endl;
	cout << "-------------------------------------------------------------------" << endl;
}
void Displayer::key() 						//Inspect Key
{
	print();
	cout << endl << endl ;
	cout << "     /KK " 	<< endl
		 << "    /EE  " 	<< endl
		 << "   /YY   "   <<"  [Item <Key>] A <Key> is for opening the <Gate>. "	<< endl
		 << " _//     "   <<"  Each level may have one or two lying around. "	<< endl
		 << "|O |     "   <<"  Sometimes breaking walls may drop a <Key>. "	<< endl;
	cout << endl << endl << endl << endl<< endl ;
	hold();
}
void Displayer::hammer()					//Inspect Hammer
{
	print();
	cout 	<< endl << endl ;
	cout 	<< " __,--.__ " << endl
			<< "|        |" << endl
			<< "|________|" << "  [Item <Hammer>] A <Hammer> is for knocking down <Walls> in one hit. "<< endl
			<< "   |  |   " << "  Each level may or may not have one lying around. Each can only be used once. " << endl
			<< "   |__|   " << "  Sometimes breaking walls may drop a <Hammer>. " <<endl <<endl;
	cout 	<< endl << endl << endl << endl ;
	hold();
			
}
void Displayer::no_bread()					//Cannot use Bread
{
	cout << endl<< endl << endl << "[!] You don't have any <Bread> in the inventory!" << endl<< endl << endl <<endl;
	hold();
}
void Displayer::no_water()					//Cannot use Water
{
	cout << endl<< endl << endl << "[!] You don't have any <Water> in the inventory!" << endl<< endl << endl <<endl;
	hold();
}
void Displayer::no_key()					//Cannot use Key
{
	print();
	cout << endl << endl << endl ;
	cout << "     /KK " 	<< endl
		 << "    /EE  " 	<< endl
		 << "   /YY   "    << "  Cannot Unlock Gate. You don't have a O==KEY yet!"	<< endl
		 << " _//     "   << endl
		 << "|O |     "   	<< endl;
	 cout 	<< endl << endl << endl << endl ;
	hold();
}

void Displayer::prompt_hammer()				//To use Hammer ?
{
	print();
	cout 	<< endl << endl << endl ;
	cout 	<< " __,--.__ " << endl
			<< "|        |" << endl
			<< "|________|" << "  [?] Use <Hammer>? Enter [Y] to use or [N] to bust <Wall> with hands : " << endl
			<< "   |  |   " << endl
			<< "   |__|   " << endl;
	cout 	<< endl << endl << endl << endl << endl ;
}
void Displayer::got_bread()					//Obtained a Bread
{
	print();
	cout << endl << endl
		<< "++--------------------------------------------------------++" << endl
		<< "++                                                        ++" << endl
		<< "++       [>] You have found a loaf of Bread!              ++" << endl
		<< "++                                                        ++" << endl
		<< "++ Save it for later (put in inventory) or drink it now?  ++" << endl
		<< "++                                                        ++" << endl
		<< "++ > 1. Put in inventory                                  ++" << endl
		<< "++ > 2. Eat it now (+"<< INV->bread_HP<< " HP)                               ++" << endl
		<< "++--------------------------------------------------------++" << endl
		<< endl << endl;	
}
void Displayer::got_water() 				//Obtained a Water
{
	print();
	cout << endl << endl
		<< "++--------------------------------------------------------++" << endl
		<< "++                                                        ++" << endl
		<< "++       [>] You have found a bottle of Water!            ++" << endl
		<< "++                                                        ++" << endl
		<< "++ Save it for later (put in inventory) or drink it now?  ++" << endl
		<< "++                                                        ++" << endl
		<< "++ > 1. Put in inventory                                  ++" << endl
		<< "++ > 2. Drink it now (+"<< INV->water_HP<< " HP)                             ++" << endl
		<< "++--------------------------------------------------------++" << endl
		<< endl << endl;
}
void Displayer::got_hammer() 				//Obtained a Hammer
{
	print();
	cout << endl << endl<< endl
		<< "++--------------------------------++" << endl
		<< "++                                ++" << endl
		<< "++   [>] You obtained a Hammer!   ++" << endl
		<< "++                                ++" << endl
		<< "++--------------------------------++" << endl
		<< endl << endl << endl<< endl;
	hold();
}
void Displayer::got_key() 					//Obtained a Key
{
	print();
	cout << endl << endl<< endl
		<< "++-----------------------------++" << endl
		<< "++                             ++" << endl
		<< "++   [>] You obtained a key!   ++" << endl
		<< "++                             ++" << endl
		<< "++-----------------------------++" << endl
		<< endl << endl << endl<< endl;
	hold();
}
void Displayer::full() 						//Cannot put in Inventory because this item reached max capacity
{
	print();
	cout << endl << endl<< endl
		<< "++-------------------------------------------------------++" << endl
		<< "++                                                       ++" << endl
		<< "++   [!] Inventory cannot carry any more of this item    ++" << endl
		<< "++                                                       ++" << endl
		<< "++-------------------------------------------------------++" << endl
		<< endl << endl << endl<< endl;
	hold();
}
void Displayer::recover(int X) 				//Takes as string the item used for healing
{
	print();
	cout << endl << endl << endl 
		<< "    __   " << endl
		<< "  _|  |_ " << endl
		<< " |_    _|" << "  [+] Recovers "<< X <<" HP" << endl 
		<< "   |__|  " << endl
		<< endl << endl << endl << endl;	
		

}


void Displayer::show_HP() 					//Displays Current HP
{
	cout << " [=] HP remaining [ " << P->HP << " / " << P->HP_Max << " ] " << endl;
}

void Displayer::hold()
{
	string empty;
	cout << endl;
	cout << "... press [ Enter ]... " << endl;
	getline(cin,empty);
	cout << endl;
}

void Displayer::hold(string S)
{
	string empty;
	cout << endl;
	cout << S << endl;
	getline(cin,empty);
	cout << endl;
}

void Displayer::instruction()
{
	cout 	<<	"     =====================================================" << endl
			<<	"     =====================================================" << endl
			<< 	"                                                          " << endl
			<<  "             G A M E      I N S T R U C T I O N           " << endl
			<< 	"                                                          " << endl
			<<	"     =====================================================" << endl
			<<	"     =====================================================" << endl;
			
			
	cout 	<< 	"      ____________________________________________________ " << endl
			<< 	"     |                                                    |" << endl
			<< 	"     |   Your goal is to get to the exit of each level.   |" << endl
			<<  "     |      Enter [W] [A] [S] [D] to move around.         |" << endl
			<< 	"     |____________________________________________________|" << endl
			<< 	"     |   ______        [W]                  ______        |" << endl
			<< 	"     |  |x * x |        ^                  | /  \\ |       |" << endl
			<< 	"     |  |*YOU* |   [A]<   >[D]  ------->   |/EXIT\\|       |" << endl
			<< 	"     |  |__*___|        v                  |______|       |" << endl
            <<	"     |_________________[S]________________________________|" << endl;  
	cout << endl;
	cout 	<< 	"      ____________________________________________________ " << endl
			<< 	"     |                                                    |" << endl
			<< 	"     |   Find a key to unlock the gate for each level.    |" << endl
			<<  "     |        There may be more than one...               |" << endl
			<< 	"     |____________________________________________________|" << endl
			<< 	"     |   ______                    ______   ______        |" << endl
			<< 	"     |  |      |                  |      | | /  \\ |       |" << endl
			<< 	"     |  |O==KEY|   ----------->   | GATE | |/EXIT\\|       |" << endl
			<< 	"     |  |______|                  |______| |______|       |" << endl
            <<	"     |____________________________________________________|" << endl;
	cout << endl;		
	cout 	<< 	"      ____________________________________________________ " << endl
			<< 	"     |                                                    |" << endl
			<< 	"     |       Zombies are not friends. They bite.          |" << endl
			<< 	"     |    Stay one block away from their surrounding!     |" << endl
			<< 	"     |____________________________________________________|" << endl
			<<	"                   ______   ______   ______  " << endl
			<<	"                  |      | |      | |      | " << endl
			<<	"                  |      | |      | |      | " << endl
			<<	"                  |______| |______| |______| " << endl
			<<	"                   ______            ______  " << endl
			<<	"                  |      |   _____  |      | " << endl
			<<	"                  |      |  (o   0) |      | " << endl
			<<	"                  |______|   [VVV]  |______| " << endl
			<<	"                   ______   ______   ______  " << endl
			<<	"                  |      | |      | |      | " << endl
			<<	"                  |      | |      | |      | " << endl
			<<	"                  |______| |______| |______| " << endl;
	cout << endl;
	cout 	<< 	"      ____________________________________________________ " << endl
			<< 	"     |                                                    |" << endl
			<< 	"     |   This is a walled-up room. You can bust through   |" << endl
			<< 	"     |   with bare-hands, 3 punches.                      |" << endl	
			<< 	"     |   Or if you find a hammer, 1 strike.               |" << endl	
			<< 	"     |   50% chance there's a loot in the Wall block!     |" << endl			
			<< 	"     |____________________________________________________|" << endl
			<<  "                                     ______ " << endl       
			<<	"          ||||||||                  |      |" << endl
			<<  "          ||WALL||    <-------      |HAMMER|" << endl
			<<  "          ||||||||                  |______|" << endl;
	cout << endl;
	hold("------- [Enter] to start game --------\n\n\n");
}

			
	


