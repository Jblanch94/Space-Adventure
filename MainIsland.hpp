/**************************************************************************************************************************************************************************************************************************************
 * Program Name: MainIsland.hpp
 * Author: Johnny Blanchard
 * Date: 11/23/18
 * Description: This is the header file for the MainIsland class which will have an objective of the player once arriving finding the 3 energy cubes which are used to power the teleportation devices that will take them to new places.
******************************************************************************************************************************************************************************************************************************************/

#ifndef MAIN_ISLAND_HPP
#define MAIN_ISLAND_HPP
#include "Space.hpp"
#include "Player.hpp"
#include "Backpack.hpp"

class MainIsland : public Space
{
	private:
		bool objectivesCompleted;
		std::string redCube;
		std::string greenCube;
		std::string blueCube;
		bool redCubeFound;
		bool greenCubeFound;
		bool blueCubeFound;
		int choice;
		int itemChoice1;
		int itemChoice2;
		int itemChoice3;
		std::string item;
		int travelChoice;
		int pickChoice;

	public:
		MainIsland();
		~MainIsland();
		void complete();
		void spaceBackground();
		void action();
		void exploreMenu();
};

#endif
		
