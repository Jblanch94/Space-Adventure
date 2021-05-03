/*****************************************************************************************************************************************************************************************************************************************
 * Program Name: Player.hpp
 * Author: Johnny Blanchard
 * Date: 11/22/18
 * Description: This is the header file for the player class that will have specfic attributes for the player, functions to set and move the players around the map and have access to their backpack.
******************************************************************************************************************************************************************************************************************************************/

#ifndef PLAYER_HPP
#define PLAYER_HPP
#include "Backpack.hpp"
//#include "Space.hpp"
#include <string>
#include <iostream>

class Space;

class Player
{
	private:
		int oxygen;
		bool infected;
		Backpack inventory;
		Space *location;
		bool rescued;
		bool escaped;
	
	public:
		Player();
		~Player();
		Space *getLocation();
		void setLocation(Space *location);
		void moveUp();
		void moveDown();
		void moveLeft();
		void moveRight();
		int getOxygen();
		void setOxygen(int o);
		void addOxygen(int air);
		void setRescued(bool rescued);
		bool dead();
		bool isRescued();
		void removeOxygen(int noAir);
		void addItem(std::string itemName);
		void removeItem(std::string itemName);
		void printItems();
		bool full();
		bool hasItem(std::string itemName);
		void setInfected(bool infected);
		bool getInfected();
		void setEscaped(bool);
		bool getEscaped();
		

		
};

#endif

