/*****************************************************************************************************************************************************************************************
** Program Name: valdiation.cpp
** Author: Johnny Blanchard
** Date: 11/2/18
** Description:  This is the implmentation file for the function getInt which will take in an integer and determine whether it is valid or not, if it is not valid the user will be prompted to enter a number that is qualified as a valid integer.
******************************************************************************************************************************************************************************************/

#include "validation.hpp"
#include <string>
#include <cctype>
#include <iostream>

/*take in user input as a string and make sure 
 * it is an integer, if it is not then prompt user 
 * to enter a valid integer and keep asking until
 * a valid integer is entered. */
int validateInt(std::string userInt)
{
	int input;
	bool isValid = true;	
	std::getline(std::cin,userInt);
	while(isValid)
	{
		while(userInt.empty())
		{
			isValid = true;
			std::cout << "No input was entered please try again! " << std::endl;
			std::cin.clear();
			std::getline(std::cin,userInt);
			if (!userInt.empty())
			{
				isValid = false;
			}
		}
		for (int i = 0; i < userInt.length(); i++)
		{ 
			while (userInt[i] == '.' || userInt[i] == ' ' || isalpha(userInt[i]))
			{
				std::cout << "Error please only enter integers. Please enter a valid number. " << std::endl;
				std::cin.clear();
				std::getline(std::cin,userInt);
				isValid = false;
				
				while(userInt.empty())
				{
					isValid = true;
					std::cout << "No input was entered please try again! " << std::endl;
					std::cin.clear();
					std::getline(std::cin,userInt);
					if (!userInt.empty())
					{
						isValid = false;
					}
				}
			}
		
			if (isdigit(userInt[i]))
			{
				isValid = false;
			}
			
		
		}
	}	
	input = std::stoi(userInt);
	
	return input;
	
}



	
			
 
		
