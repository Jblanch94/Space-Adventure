/*************************************************************************************************************************************************************************************************************************************
 * Program Name: researchFacility.hpp
 * Author: Johnny Blanchard
 * Date: 11/25/18
 * Description: This is the header file for the researchFacility class which will allow the user to get the cure so they can lift the lockdown.
*************************************************************************************************************************************************************************************************************************************/

#ifndef RESEARCH_FACILITY_HPP
#define RESEARCH_FACILITY_HPP
#include "Space.hpp"
#include "Player.hpp"

class ResearchFacility : public Space
{
	private:
		bool hasCure;
		int choice;
		std::string cure;
		int cureChoice;
		std::string item;
		int infectChoice;
	
	public:
		ResearchFacility();
		~ResearchFacility();
		void spaceBackground();
		void exploreMenu();
		void action();
		void printMenu();
		void gameOver();
		void complete();
};

#endif
