/******************************************************************************************************************************************************************************************************************************************
 * Program Name: mountainIsland.cpp
 * Author: Johnny Blanchard
 * Date: 11/29/18
 * Description: This is the implementation file for the Mountain Island class. 
****************************************************************************************************************************************************************************************************************************************/

#include "mountainIsland.hpp"

MountainIsland::MountainIsland() 
{
}

//empyt destructor
MountainIsland::~MountainIsland()
{
}

void MountainIsland::complete()
{
}

void MountainIsland::spaceBackground()
{
	std::cout << "You are arrive at Mountain Island. " << std::endl;
	std::cout << "PDA: If there is anything you forgot to do, you can still go back and do it. " << std::endl;
	std::cout << "You hear a loud explosion in the distance. " << std::endl;
	std::cout << "The space shuttle has blown up. " << std::endl;
	std::cout << "Survivor: I don't think that is an option anymore. " << std::endl;
	std::cout << "Survivor: Only thing we can do now is wait. " << std::endl;
}

void MountainIsland::action()
{
	std::cout << "You continue to wait to be rescued. " << std::endl;
	std::cout << "Rescue shuttle: Hello, is there anyone there? " << std::endl;
	std::cout << "Rescue shuttle: I've locked onto your pda gps and will land at your location. " << std::endl;
	if(lockdown)
	{
		std::cout << "Rescue ship: Wait, what is that!? " << std::endl;
		std::cout << "The rescue ship has been blown up by the cannon that is part of the lockdown procedure. " << std::endl;
		player.setOxygen(0);
		player.setRescued(false);
		std::cout << "Game over! You have lost! " << std::endl;
	}

	else
	{
		std::cout << "Rescue ship: How have you survived this long? " << std::endl;
		std::cout << "Survivor: I thought I was dead! " << std::endl;
		std::cout << "You escape the planet successfully! " << std::endl;
		player.setRescued(true);
	}
}


	
