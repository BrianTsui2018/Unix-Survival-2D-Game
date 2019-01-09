/*********************************************************************  
** Program name:	Validate (Portable)
** Author:  		Brian Tsui
** Date:  			10/11/2017
** Description: 	This is the Header code for Validate class.
					This class object offers functions that takes in a string 
					to prompt user for an input, and then valides the input 
					before returning the expected type. 
*********************************************************************/

#ifndef VALIDATE_HPP
#define VALIDATE_HPP
#include <string>

class Validate
{
	private:
		int i;							// for holding int
		char c;							// for holding char
		std::string s;					// for honlding string
		float f;						// for holding float
	public:
		Validate();							
		int qI(std::string);			// Prompts for an integer
		int qPI(std::string);			// Prompts for a positive integer
		int qRI(std::string, int, int);	// Prompts for an interger within the specific min and max value
		char qC(std::string);			// Prompts for a char
		char q2C(std::string, char, char);
		char qYN(std::string);			// Prompts for a Yes No input, non-case sensitive
		int printOptions();				// Prompts for hard-coded options 
		std::string qS(std::string);	// Prompts for a string
};

#endif