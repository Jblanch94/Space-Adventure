/***************************************************************************************************************************************************************************************************************************************
 * Program Name: weaponsFacility.hpp
 * Author: Johnny Blanchard
 * Date: 11/25/18
 * Description: This is the the header file for the weapons facility space which will allow the user to explore the area and get a weapon that will be needed later.
*******************************************************************************************************************************************************************************************************************************************/

#ifndef WEAPONS_FACILITY_HPP
#define WEAPONS_FACILILTY_HPP
#include "Player.hpp"
#include "Space.hpp"

class WeaponsFacility : public Space
{
	private:
		bool hasWeapon;
		std::string freezeCannon;
		std::string teleportRay;
		std::string dimensionalRay;
		int choice;
		int weaponChoice;
		std::string item;
		bool objectivesCompleted;

	public:
		WeaponsFacility();
		~WeaponsFacility();
		void spaceBackground();
		void exploreMenu();
		void action();
		void complete();
};

#endif
