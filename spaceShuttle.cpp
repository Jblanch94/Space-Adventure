/*****************************************************************************************************************************************************************************************************************************************
 * Program Name: spaceShuttle.cpp
 * Author: Johnny Blanchard
 * Date: 11/28/18
 * Description: This is the implementation of the SpaceShuttle class.
****************************************************************************************************************************************************************************************************************************************/

#include "spaceShuttle.hpp"
#include <cstdlib>

SpaceShuttle::SpaceShuttle()
{
	objectiveCompleted = false;
	choice = -1;
}

//empty destructor
SpaceShuttle::~SpaceShuttle()
{
}


void SpaceShuttle::complete()
{
	if(!objectiveCompleted)
	{
		spaceBackground();
	}
	else
	{
		std::cout << "There is nothing else for you to do here. " << std::endl;
	}
}

//function to give background info for this space
void SpaceShuttle::spaceBackground()
{
	if(!objectiveCompleted)
	{
		std::cout << "Now that you have finally reached the shuttle you can call for a rescue. " << std::endl;
		std::cout << "PDA: Do you know where you need to go? " << std::endl;
		std::cout << "Survivor: Not really, I was never actually awake when I was onboard. " << std::endl;
		std::cout << "PDA: Hold on, I can download a map of the shuttle. " << std::endl;
		std::cout << "PDA: So, it looks like we need to go to the Crew cabin and the communications are there. " << std::endl;
	}

	else
	{
		std::cout << "You have already been here and completed your task.  Please go to Mountain Island and await rescue! " << std::endl;
	}
}

void SpaceShuttle::action()
{
	if (!objectiveCompleted)
	{
		std::cout << "You head down a hallway and there is no one on board. " << std::endl;
		std::cout << "As you enter the room that has all the communications, you see multiple people dead in the room who were probably killed on impact. " << std::endl;
		std::cout << "You turn on the communications and start to reach out for help... " << std::endl;
		std::cout << "Survivor: HELLO?!? Is anyone there? " << std::endl;
		std::cout << "Captain: Yes, what seems to be the problem? " << std::endl;
		std::cout << "Survivor: This space shuttle was on an expedition for a planet and it was shot down. " << std::endl;
		std::cout << "Survivor: Please you have to help me! " << std::endl;
		std::cout << "Capatin: Okay, I used the gps that is installed in the space shuttle you are on and help is on the way. " << std::endl;
		std::cout << "Captain: There is an island due west of your current location, I need you to be there by nightfall. " << std::endl;
		std::cout << "Survivor: Okay I'll be there. Thank you! " << std::endl;

	
		objectiveCompleted = true;


	}

}
