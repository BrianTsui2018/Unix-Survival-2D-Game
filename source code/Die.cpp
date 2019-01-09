/*********************************************************************  
** Program name:	Die (Portable)
** Author:  		Brian Tsui
** Date:  			22/10/2017
** Description: 	This is the Implmentation code for Die class.
					Die is a portable random number generator class.
					It takes a min and a max value to set the range for
					the random integer to be selected. 
					The announce function prints out the result as a system message.
					When pass a string into the argument, the message would address it
					as a player's name.
*********************************************************************/

#include "Die.hpp"
#include <iostream>
#include <string>
#include <cstdlib>
#include <ctime>

using namespace std;

Die::Die()
{
	min = 0;
	max = 100;
	result = 0;				
}

/* 	
	Dice Roll:
	To produce a randomly generated value, the random function takes a seed 
	that is a combination of the computer time and a decrementing value,
	so to make sure that even in a millesecond of mutliple dice-rolls, 
	the seed would still be different every time, and thus generates a different result every time.
	
	The result it returns fits in the to provided min, max range. 
*/
	
int Die::roll(int from, int to)
{

	srand(time(NULL)-seed);
	min = from;
	max = to;
	int n = rand();				// stores the random number generated
	int x = max - min + 1; 		// number of possible outcomes. i.e. {2 ~ 5} = (5 - 2) + 1 = 4 outcomes.
	result = n % (x) + min;		// remainder of the random number divided by possible outcomes, also shifts the range to match the input min max range.
	seed --;					// mutates the seed and thus affects the random number next roll
	return result; 
}



void Die::announce()							// announces the last result, addresses the user as "You"
{
	cout << "<Roll> : Between " << min << " and " << max << ", you rolled a [ " << result << " ]!" << endl;  
}

void Die::announce(string name)				// announces the last result, addresses the user as the string passed in the parameter
{
	cout << "<Roll> : Between " << min << " and " << max << ", " << name << " rolled a [ " << result << " ]!" << endl;  
}