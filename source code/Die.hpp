/*********************************************************************  
** Program name:	Die (Portable)
** Author:  		Brian Tsui
** Date:  			22/10/2017
** Description: 	This is the Header code for Die class.
					Die is a portable random number generator class.
					It takes a min and a max value to set the range for
					the random integer to be selected. 
					The announce function prints out the result as a system message.
					When pass a string into the argument, the message would address it
					as a player's name.
*********************************************************************/

#ifndef DIE_HPP
#define DIE_HPP
#include <string>

class Die
{
	protected:
		int min;
		int max;
		int result;
		int seed;				// for manipulating the seed in srand()
	
	public:
		Die();
		int roll(int, int);
		void announce();
		void announce(std::string);
};


#endif