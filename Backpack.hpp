/****************************************************************************************************************************************************************************************************************************************
 * Program Name: Backpack.hpp
 * Author: Johnny Blanchard
 * Date: 11/22/18
 * Description: This is the header file for the backpack class that will be used to hold items collected throughout the game.  The backpack will use a vector to store the items.
*****************************************************************************************************************************************************************************************************************************************/

#ifndef BACKPACK_HPP
#define BACKPACK_HPP
#include <string>
#include <vector>
#include <algorithm>
#include <iostream>

class Backpack
{
	private:
		std::vector <std::string> items;
		int capacity;

	public:
		Backpack();
		~Backpack();
		void addItem(std::string itemName);
		void removeItem(std::string itemName);
		void printItems();
		bool full();
		bool hasItem(std::string itemName);
	
};

#endif
