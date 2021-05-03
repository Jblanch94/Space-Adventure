/***************************************************************************************************************************************************************************************************************************************
 * Program Name: Backpack.cpp
 * Author: Johnny Blanchard
 * Date: 11/22/18
 * Description: This is the implementation file for the backpack class.
*****************************************************************************************************************************************************************************************************************************************/

#include "Backpack.hpp"

//constructor that sets the capacity of items 
Backpack::Backpack()
{
	capacity = 5;
}

//empty destructor
Backpack::~Backpack()
{
}

//function to add item to backpack
void Backpack::addItem(std::string itemName)
{
	if (items.size() < capacity)
	{
		items.push_back(itemName);
		std::cout << itemName << " added to backpack. " << std::endl;
	}

	else
	{
		std::cout << "Backpack is full! " << std::endl;
	}
}

//funciton to remove item from backpack
void Backpack::removeItem(std::string itemName)
{
	for (int i = 0; i < items.size(); i++)
	{
		if (items.at(i) == itemName)
		{
			items.erase(items.begin() + i);
			std::cout << itemName << " has been removed from backpack. " << std::endl;
		}
		else
		{
			std::cout << itemName << " was not found in backpack. " << std::endl;
		}
	}

}

//function to print contents of backpack
void Backpack::printItems()
{
	if(items.size() == 0)
	{
		std::cout << "There are currnetly no items in your backpack. " << std::endl;
	}
	else
	{
		for (int i = 0; i < items.size(); i++)
		{
			std::cout << items.at(i) << " " << std::endl;
		}
	}
}

//function to test if backpack is full
bool Backpack::full()
{
	if(items.size() >= capacity)
	{
		return false;
	}
	else
	{
		return true;
	}
}

//checks to see if has specfic item
bool Backpack::hasItem(std::string itemName)
{
	if(std::find(items.begin(), items.end(), std::string(itemName)) != items.end())
	{
		return true;
	}
	else
	{
		return false;
	}
}

