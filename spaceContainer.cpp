/***************************************************************************************************************************************************************************************************************************************
 * Program Name: spaceContainer.cpp
 * Author: Johnny Blanchard
 * Date: 11/26/18
 * Description: This is the implementation file for the SpaceContainer class.
*************************************************************************************************************************************************************************************************************************************/

#include "spaceContainer.hpp"


//empty constructor
SpaceContainer::SpaceContainer()
{
	oxygen = 10;
}

//empty destructor
SpaceContainer::~SpaceContainer()
{
}

//function to add item to space
void SpaceContainer::addItem(std::string itemName)
{
	objects.push_back(itemName);
}

//function to remove item from space
void SpaceContainer::removeItem(std::string itemName)
{
	if (objects.size() == 0)
	{
		std::cout << "There is nothing here." << std::endl;
	}
	else
	{


		for (int i = 0; i < objects.size(); i++)
		{
			if (objects.at(i) == itemName)
			{
				objects.erase(objects.begin() + i);
				std::cout << itemName << " has been removed from this space " << std::endl;
			}
			else
			{
				std::cout << itemName << " was not found in space. " << std::endl;
			}
		}
	}

}

//function to print contents of backpack
void SpaceContainer::printItems()
{
	if(objects.size() == 0)
	{
		std::cout << "There are currnetly no items in this space. " << std::endl;
	}
	
	else
	{
		std::vector<std::string>::iterator object;
		for (object = objects.begin(); object != objects.end(); object++)
		{
			std::cout << *object << std::endl;
		}
	}
}

bool SpaceContainer::areaEmpty()
{
	if (objects.size() <= 0)
	{
		return true;
	}
	else
	{
		return false;
	}

	
}

