/****************************************************************************************************************************************************************************************************************************************
 * Program Name: Lifepod.hpp
 * Author: Johnny Blanchard
 * Date: 11/23/18
 * Description: This is the header file for the lifepod class which will inheirt from the space class and is the starting area for the player.  It will explain what is going on and the objective of the game as well getting the player 
 * prepared for their journey.  
******************************************************************************************************************************************************************************************************************************************/

#ifndef LIFEPOD_HPP
#define LIFEPOD_HPP
#include "Player.hpp"
#include "Space.hpp"
#include <iostream>

class Lifepod : public Space
{
	private:
		bool itemsCollected;
		std::string oxygenTank;
		int choice;
		SpaceContainer structure;
		Player player;
		int oxygenChoice;

	public:
		Lifepod();
		~Lifepod();
		void spaceBackground();
		void complete();
		void action();
};

#endif

