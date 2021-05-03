/***************************************************************************************************************************************************************************************************************************************
 * Program Name: ContaminationFacility.hpp
 * Author: Johnny Blanchard
 * Date: 11/23/18
 * Description: This is the header file for the ContaminationFacility class which will let the player find out about what happened on this planet and needs the player to turn off the lockdown so that the player can call to leave the planet.
******************************************************************************************************************************************************************************************************************************************/

#ifndef CONTAMINATION_FACILITY_HPP
#define CONTAMINATION_FACILITY_HPP
#include "Space.hpp"
#include "Player.hpp"

class ContaminationFacility : public Space
{
	private:
		int choice;
		int infoChoice;
		int lockdownChoice;
		std::string keyCard;
		bool keyFound;
		bool objectivesCompleted;

	public:
		ContaminationFacility();
		~ContaminationFacility();
		void spaceBackground();
		void exploreMenu();
		void action();
		void printMenu();
		void complete();
};

#endif
