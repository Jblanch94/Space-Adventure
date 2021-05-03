
/***************************************************************************************************************************************************************************************************************************************
 * Program Name: ContaminationFacility.hpp
 * Author: Johnny Blanchard
 * Date: 11/29/18
 * Description: This is the header file for the MountianIsland class where you will be rescued if you turned off the lockdown if not then the rescue ship will be shot down and you will lose.
******************************************************************************************************************************************************************************************************************************************/

#ifndef MOUNTAIN_ISLAND_HPP
#define MOUNTAIN_ISLAND_HPP
#include "Space.hpp"
#include "Player.hpp"

class MountainIsland : public Space
{
	private:

	public:
		MountainIsland();
		~MountainIsland();
		void spaceBackground();
		void action();
		void complete();
};

#endif
