/*********************************************************************  
** Program name:	Validate (Portable)
** Author:  		Brian Tsui
** Date:  			10/11/2017
** Description: 	This is the Implementation code for Validate class.
					This class object offers functions that takes in a string 
					to prompt user for an input, and then valides the input 
					before returning the expected type. 
*********************************************************************/

#include "Validate.hpp"
#include <iostream>
#include <string>
#include <cctype>
using namespace std;

Validate::Validate()
{
	
}

/*
	Integer
*/
int Validate::qI(string myLine)
{
/*
	cout << myLine << endl;
	cin >> f;
	i = f;

	while (!cin || f > i)	
	{
		cout << "Invalid input. Please retry. Enter an integer." << endl;
		cin.clear();
		cin.ignore();
		cin >> f;
		i = f;
	}

	return i;
*/

	cout << myLine << endl;
	bool validate = false;
	i = 0;
	

	while (!cin || validate == false)	
	{	
		getline (cin, s);
		
		if (!s.empty())
		{
			if (!cin)
			{
				cin.clear();
				cin.ignore();
			}
			else
			{
				validate = true;
				for (int k = 0; k < s.length(); k++)
				{
					if(isdigit(s[k]) == false || s[k] == ' ')
					{
						validate = false;
					}
				}
			}
			
			if (validate == true && s.length() < 8)
			{
				i = stoi(s);
				return i;
			}
			
			validate = false;
		}

		cout << "Invalid input. Please retry. Enter an integer."<< endl;

	}

}

/*
	Positive Integer
*/
int Validate::qPI(string myLine)		
{
/*
	cout << myLine << endl;
	cin >> f;
	i = f;
	while (!cin || i < 1  || f > i)	
	{
		cout << "Invalid input. Please retry. Enter positive integer." << endl;
		cin.clear();
		cin.ignore();
		cin >> f;
		i = f;
	}
	cin.clear();
	cin.ignore();
	return i;
*/

	cout << myLine << endl;
	bool validate = false;
	i = 0;
	

	while (!cin || validate == false)	
	{	
		getline (cin, s);
		
		if (!s.empty())
		{
			if (!cin)
			{
				cin.clear();
				cin.ignore();
			}
			else
			{
				validate = true;
				for (int k = 0; k < s.length(); k++)
				{
					if(isdigit(s[k]) == false || s[k] == ' ')
					{
						validate = false;
					}
				}
			}
			
			if (validate == true && s.length() < 8)
			{
				i = stoi(s);
				if( i >= 0  )
				{
					return i;
				}
			}
			validate = false;
		}

		cout << "Invalid input. Please retry. Enter positive integer."<< endl;

	}
	
	
	
}

/*
	Range of Integer
*/

int Validate::qRI(string myLine, int min, int max)		
{
	/*
	cout << myLine << endl;
	cin >> f;
	i = f;

	while (!cin || i < min || i > max  || f > i)	
	{
		cout << "Invalid input. Please retry. Enter integer between the range [" << min << "] and [" << max << "]"<< endl;
		cin.clear();
		cin.ignore();

		cin >> f;
		i = f;
	}
	
	return i;
	*/
	
	cout << myLine << endl;
	bool validate = false;
	i = 0;
	

	while (!cin || validate == false)	
	{	
		getline (cin, s);
		
		if (!s.empty())
		{
			if (!cin)
			{
				cin.clear();
				cin.ignore();
			}
			else
			{
				validate = true;
				for (int k = 0; k < s.length(); k++)
				{
					if(isdigit(s[k]) == false || s[k] == ' ')
					{
						validate = false;
					}
				}
			}
			
			if (validate == true && s.length() < 8)
			{
				i = stoi(s);
				if( i >= min && i <= max  )
				{
					return i;
				}
			}
			validate = false;
		}

		cout << "Invalid input. Please retry. Enter integer between the range [" << min << "] and [" << max << "]"<< endl;

	}

}

/*
	Char
*/
char Validate::qC(string myLine)
{
	cout << myLine << endl;
	cin >> c;
	
	while (!cin)	
	{
		cout << "Invalid input. Please retry. Enter only one character." << endl;
		cin.clear();
		cin.ignore();
		cin >> c;
	}
	cin.clear();
	cin.ignore();
	return c;
	
}

/*
	Y / N
*/
char Validate::qYN(string myLine)
{
	cout << myLine << endl;
	cin >> c;
	bool input = false;
	while (input == false)	
	{
		if (c == 'Y' || c == 'y')
		{
			input = true;
			c = 'Y';
		}
		else if (c == 'N' || c == 'n')
		{
			input = true;
			c = 'N';
		}
		else
		{
			cout << "Invalid input. Please try again. Enter Y or N." << endl;
			cin.clear();
			cin.ignore();
			cin >> c;
			input = false;
		}
	}
	cin.clear();
	cin.ignore();
	return c;
	
}

/*
	Char / Char
*/
char Validate::q2C(string myLine, char c1, char c2)
{
	cout << myLine << endl;
	cin >> c;
	char temp = toupper(c);
	c = temp;
 
	while (c != c1 && c != c2)
	{
		cout << "Invalid input. Please try again. Enter "<< c1 <<" or "<< c2 <<"." << endl;
		cin.clear();
		cin.ignore();
		cin >> c;
	}
	cin.clear();
	cin.ignore();
	return c;
	
}


int Validate::printOptions()
{
	int options = 5;
	string qArr [] = 	{			"Noodle"	, 
									"Sushi"		,
									"Burger"	,
									"Taco"		,
									"Pizza"		
												};
										
	for (int n = 0 ; n < options ; n++)
	{
		cout << "> " << n+1 << ". " << qArr[n] << endl;
	}

	cin >> i;
	while (!cin || i < 1 || i > options )	
	{
		cout << "Invalid input. Please retry. Enter integer between the range [" << 1 << "] and [" << options << "]"<< endl;
		cin.clear();
		cin.ignore();
		cin >> i;
	}
	cin.clear();
	cin.ignore();
	return i;
	
}		
	
/*
	String
*/
string Validate::qS(string myLine)
{
	cout << myLine << endl;
	
	while(true)
	{
		getline (cin, s);
			
		if (!s.empty())
		{
			if (!cin)
			{
				cin.clear();
				cin.ignore();
			}
			else
			{
				return s;
			}

		}
		
		cout << "Invalid input. Please retry. Enter an integer."<< endl;
	
	}
	
}
