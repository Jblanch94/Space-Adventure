/***************************************************************************************************************************************************************************************************************************************
 * Program Name: spaceContainer.hpp
 * Author: Johnny Blanchard
 * Date: 11/26/18
 * Description: This is the header file for the SpaceContainer class which will be a vector that will hold all of the objects in a specific space.  It will have methods to add objects, take away objects from the space and display what objects are in the space.
****************************************************************************************************************************************************************************************************************************************/

#ifndef SPACE_CONTAINER_HPP
#define SPACE_CONTAINER_HPP
#include <vector>
#include <string>
#include <iostream>


class SpaceContainer
{
	private:
		std::vector <std::string> objects;
		int oxygen;

	public:
		SpaceContainer();
		~SpaceContainer();
		void addItem(std::string itemName);
		void removeItem(std::string itemName);
		void printItems();
		bool areaEmpty();
	
};

#endif
