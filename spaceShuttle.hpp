/***********************************************************************************************************************************************************************************************************************************
 * Program Name: spaceShuttle.hpp
 * Author: Johnny Blanchard
 * Date: 11/28/18
 * Description: This is the header file for the space shuttle class which will allow the player to go to the broken space shuttle and use their radio communications to get picked up.  There will also be a monster that a player has to fight to survive and if they do not have a weapon they are guaranteed to die.
**************************************************************************************************************************************************************************************************************************************/

#ifndef SPACE_SHUTTLE_HPP
#define SPACE_SHUTTLE_HPP
#include "Player.hpp"
#include "Space.hpp"

class SpaceShuttle : public Space
{
	private:
		bool objectiveCompleted;
		int choice;

	
	public:
		SpaceShuttle();
		~SpaceShuttle();
		void spaceBackground();
		void action();
		void complete();
};

#endif
