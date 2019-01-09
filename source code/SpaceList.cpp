/**********************************************************************************  
** Program name:	Rogue-like Survival	 			- Final Project -
** Author:  		Brian Tsui
** Date:  			06/12/2017
** Description: 	This is the Implementation code for ListSpace class.
					It is essentially a "list" Space "nodes".
					This is mainly based on lab 6 (ListNode class).
**********************************************************************************/
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

#include <iostream>

using namespace std;

/****************************
*							*
*	Default Constructor		*
*							*
****************************/
SpaceList::SpaceList()
{
	head = NULL;
	tail = NULL;
}


/****************************
*							*
*	Function #1				*
*							*
****************************/
void SpaceList::addHead(int X)
{
	if ( head == NULL )
	{
		head = new Clear(X, NULL, NULL, NULL, NULL);
		tail = head;
	}
	else
	{
		head->left = new Clear (X, NULL, NULL, NULL, head);			// Space constructor parameter: up , down , left , right
		head = head->left;
	}
}



/****************************
*							*
*	Function #2				*
*							*
****************************/
void SpaceList::addTail(int X)
{

	if ( head == NULL )
	{
		head = new Clear(X, NULL, NULL, NULL, NULL);
		tail = head;
	}
	else 
	{
		tail->right = new Clear (X, NULL, NULL, tail, NULL);
		tail = tail->right;
	}

}



/****************************
*							*
*	Function #3				*
*							*
****************************/
void SpaceList::delFirst()
{
	if ( head == NULL )
	{
		empty();
	}
	else if ( head == tail )
	{
		delete head;
		head = NULL;
		tail = NULL;
	}
	else
	{
		head = head->right;
		delete head->left;
		head->left = NULL;
	}
}



/****************************
*							*
*	Function #4				*
*							*
****************************/
void SpaceList::delLast()
{
	if ( head == NULL )
	{
		empty();
	}
	else if ( head == tail )
	{
		delete tail;
		head = NULL;
		tail = NULL;
	}
	else
	{
		tail = tail->left;
		delete tail->right;
		tail->right = NULL;
	}
}



/****************************
*							*
*	Function #5				*
*							*
****************************/
void SpaceList::reversePrint()
{
	if ( head == NULL )
	{
		empty();
	}
	else
	{
		Space * ptr = tail;
		cout << endl << "Your linked list is: ";
		while (ptr != NULL)
		{
			cout << ptr->get_ID() << " " ;
			ptr = ptr->left; 
		}
		cout << endl;
	}
}



/****************************
*							*
*	Function #6				*
*							*
****************************/
void SpaceList::traversePrint()
{
	if ( head == NULL )
	{
		cout << "List clear." << endl << endl;
	}
	else
	{
		Space * ptr = head;
		cout << endl;
		while (ptr != NULL)
		{
			cout << ptr->get_ID()  << " " ;
			ptr = ptr->right;
		}
		cout << endl << endl;
	}
}



/****************************
*							*
*	Function #7				*
*							*
****************************/
void SpaceList::printHead()
{
	if ( head == NULL )
	{
		cout << endl << "[!] The head is pointing to NULL. (The list is empty) " << endl;
	}
	else
	{
		cout << endl << "Value of the Node the head is pointing to  :  " << head->get_ID()  << endl;
	}
}



/****************************
*							*
*	Function #8				*
*							*
****************************/
void SpaceList::printTail()
{
	if ( tail == NULL )
	{
		cout << endl << "[!] The tail is pointing to NULL. (The list is empty) " << endl << endl;
	}
	else
	{
		cout << endl << "Value of the Node the tail is pointing to  :  " << tail->get_ID()  << endl << endl;
	}
}




/****************************
*							*
*	Internal Utilities		*
*							*
****************************/

void SpaceList::empty()					// Prints message regarding empty list
{
	cout << endl << "[!] Your list is empty at the moment." << endl << endl; 
}


int SpaceList::promptMenu()				// Prints menu of option and returns the input
{
	cout << "_______________________" << endl << endl;
	cout << "\t Menu " << endl;
	cout << "_______________________" << endl;
	cout << "1. Add a new node to the head" << endl;
	cout << "2. Add a new node to the tail" << endl;
	cout << "3. Delete the first node in the list" << endl;
	cout << "4. Delete the last node in the list" << endl;
	cout << "5. Traverse the list reversely" << endl;
	cout << "6. Exit" << endl;
	cout << "7. Print the ID of the Node the head is pointing to" << endl;
	cout << "8. Print the ID of the Node the tail is pointing to" << endl;	
	cout << endl;
	return val.qRI("Enter an option [1] to [8]  :  ", 1,8);
}


/****************************
*							*
*	Deconstructor			*
*							*
****************************/
SpaceList::~SpaceList()
{
	while (tail != head)
	{
		tail = tail->left;
		delete tail->right;
		tail->right = NULL;
	}
	delete head;
	head = NULL;
	tail = NULL;
}


bool SpaceList::menu()					// Calls print menu and executes the input
{
/*
	int option = promptMenu();
	int x = 0;
	
	switch (option)
	{
		case 1	:	x = promptValue();
					add2Head(x);
					break;
					
		case 2	:	x = promptValue();
					add2Tail(x);
					break;
					
		case 3	:	delFirst();
					break;
					
		case 4	:	delLast();
					break;
					
		case 5	:	reversePrint();
					break;
					
		case 6	:	return true;
					break;
					
		case 7	:	printHead();
					break;
					
		case 8 	:	printTail();
					break;
	}
*/
	return false;
}


int SpaceList::promptValue()				// Prompt to input an integer as node ID
{
	cout << endl;
	cout << endl;
	int x = val.qPI ("Please enter a positive integer  :  ");
	cout << endl;
	cout << endl;
	return x;
}


void SpaceList::run()						// Runs the program until Exit
{
	bool done = false;
	while (!done)
	{
		cout << endl << endl << endl;
		done = menu();
	}
	cout << endl << "Good-bye!" << endl;
}


/****************************************
*										*
*	New functions for final project		*
*							            *
****************************************/

Space* SpaceList::select(int N)
{
	/*----------------------------------------------------------------
		
		Returns the pointer to the specific column in this row  
		
	----------------------------------------------------------------*/
	if ( head == NULL )
	{
		cout << "Head is null" << endl;
		return NULL;
	}
	else
	{
		ptr = head;
		for (int i = 0; i < N; i++)
		{
			ptr = ptr->right;
		}
	}
	return ptr;
}

void SpaceList::removeAll()
{
	/*----------------------------------------------
		
		Cleans up the Space list (this row) 
		
	----------------------------------------------*/
	while (tail != head)
	{
		tail = tail->left;
		delete tail->right;
		tail->right = NULL;
	}

	delete head;
	head = NULL;
	tail = NULL;
}

void SpaceList::replace(Space* A, Space* B)
{
	/*----------------------------------------------
		
		Replaces the two passed in Space nodes
		Deletes the old one after linking the 
		new one with the neighbouring Space
		nodes of 4 directions. 
		
	----------------------------------------------*/
	int ID = A->get_ID();
	string type = B->get_type();
	
	
	if (type == "GATE")
	{
		delete B;
		B = NULL;
		B = new Gate(ID, A->up, A->down, A->left, A->right);
	}
	else if (type == "KEY")
	{
		delete B;
		B = NULL;
		B = new Key(ID, A->up, A->down, A->left, A->right);
	}
	else if (type == "BREAD")
	{
		delete B;
		B = NULL;
		B = new Bread(ID, A->up, A->down, A->left, A->right);
	}
	else if (type == "WATER")
	{
		delete B;
		B = NULL;
		B = new Water(ID, A->up, A->down, A->left, A->right);
	}	
	else if (type == "HAMMER")
	{
		delete B;
		B = NULL;
		B = new Hammer(ID, A->up, A->down, A->left, A->right);
	}		
	else if (type == "WALL")
	{
		delete B;
		B = NULL;
		B = new Wall(ID, A->up, A->down, A->left, A->right);
	}	
	else if (type == "EDGE")
	{
		delete B;
		B = NULL;
		B = new Edge(ID, A->up, A->down, A->left, A->right);
	}	
	else if (type == "WALL")
	{
		delete B;
		B = NULL;
		B = new Wall(ID, A->up, A->down, A->left, A->right);
	}
	else
	{
		delete B;
		B = NULL;
		B = new Clear(ID, A->up, A->down, A->left, A->right);
	}
	
	
	if (B->up != NULL)
	{
		B->up-> down = B;
	}
	if (B->left != NULL)
	{
		B->left->right = B;
	}
	if (B->right != NULL)
	{
		B->right->left = B;
	}
	if (B->down != NULL)
	{
		B->down->up = B;
	}
	
	if (A == head)
	{
		head = B;
	}
	
	if (A == tail)
	{
		tail = B;
	}
	
	delete A;
	
	A = NULL;

	
}