/**********************************************************************************  
** Program name:	Rogue-like Survival	 			- Final Project -
** Author:  		Brian Tsui
** Date:  			06/12/2017
** Description: 	This is the Header code for ListSpace class.
					It is essentially a "list" Space "nodes".
					This is mainly based on lab 6 (ListNode class).
**********************************************************************************/
#ifndef INTLIST_HPP
#define INTLIST_HPP
#include "Validate.hpp"
#include "Space.hpp"


class SpaceList
{
	private:
		Space * head;
		Space * tail;
		Space * ptr;
		Validate val;
		

		void empty();
		int promptMenu();
		int promptValue();
		bool menu();
		
	public:
		SpaceList();
		~SpaceList();

		void addHead(int);
		void addTail(int);
		void delFirst();
		void delLast();
		void traversePrint();
		void reversePrint();
		void run();
		void printHead();
		void printTail();

		
		// New functions for Final Project
		Space * select(int);			// Return a pointer to a Space in the list, pass an int as offset
		void removeAll();				// Clean this row
		void replace(Space*, Space*);	// Replace 1st Space with 2nd Space
		void cast();					// Debugging purpose only
			
};

#endif