/************************************************************************************************************************************************************************************************************************************
 * Program Name: game.cpp
 * Author: Johnny Blanchard
 * Date: 11/30/18
 * Description: This is the implementation of the game class.
 ***************************************************************************************************************************************************************************************************************************************/

#include "game.hpp"
#include <iostream>

Game::Game()
{
	choice = -1;
	won = false;

	//create spaces and player
	lp = new Lifepod();
	main = new MainIsland();
	cf = new ContaminationFacility();
	rf = new ResearchFacility();
	wf = new WeaponsFacility();
	ss = new SpaceShuttle();
	mount = new MountainIsland();
	p = Player();

	
	//link spaces
	lp->setTop(NULL);
	lp->setBottom(main);
	lp->setLeft(NULL);
	lp->setRight(NULL);
	lp->setSpaceName("life pod");
	
	main->setTop(ss);
	main->setBottom(cf);
	main->setLeft(wf);
	main->setRight(rf);
	main->setSpaceName("Main Island");
	
	cf->setTop(main);
	cf->setBottom(NULL);
	cf->setRight(NULL);
	cf->setLeft(NULL);
	cf->setSpaceName("Contamination Facility");

	wf->setTop(NULL);
	wf->setBottom(NULL);
	wf->setLeft(NULL);
	wf->setRight(main);
	wf->setSpaceName("Weapons Facility");

	rf->setTop(NULL);
	rf->setBottom(NULL);
	rf->setLeft(main);
	rf->setRight(NULL);
	rf->setSpaceName("Research Facility");

	ss->setTop(mount);
	ss->setBottom(NULL);
	ss->setLeft(NULL);
	ss->setRight(NULL);
	ss->setSpaceName("Space Shuttle");
	
	mount->setTop(NULL);
	mount->setBottom(ss);
	mount->setLeft(NULL);
	mount->setRight(NULL);
	mount->setSpaceName("Mountain Island");
	
	p.setLocation(lp);
	
}

void Game::menu()
{
	std::cout << "Welcome to a Subnautica based game! " << std::endl;
	std::cout << "This is a game based off the game Subnautica. " << std::endl;
	std::cout << "It is an open-world survival game where the goal of the game is to survive and escape. " << std::endl;
	std::cout << "This game has the same objective as the original game but is not the same. " << std::endl;
	std::cout << "You crash land on an unknown planet and you have to find a way to survive and escape. " << std::endl;
	std::cout << "If you can't find a way off the planet then it is game over. " << std::endl;
	std::cout << "You must travel to different parts of the world to complete the game. " << std::endl;
	std::cout << "Please select an option below: " << std::endl;
	std::cout << "1. Play " << std::endl;
	std::cout << "2. Quit " << std::endl;
	
	choice = validateInt(input);
	while(choice < 1 || choice > 2)
	{
		std::cout << "Please enter a valid choice " << std::endl;
		choice = validateInt(input);
	}
		
	if(choice == 1)
	{	
		play();
	}

	else
	{
		std::cout << "Goodbye " << std::endl;
	}
}

void Game::play()
{
	if ((!p.getOxygen() <= 0) && !p.isRescued())
	{
		if (p.getLocation() == lp)
		{
			p.getLocation()->complete();
			p.getLocation()->spaceBackground();
			p.getLocation()->action();
			p.setOxygen(100);
			std::cout << "Oxygen: " << p.getOxygen() << std::endl;
			p.moveDown();

		}



		if (p.getLocation() == main)
		{
			p.removeOxygen(20);
			std::cout << "Oxygen: " << p.getOxygen() << std::endl;
			p.getLocation()->getSpaceName();
			p.getLocation()->complete();
			p.getLocation()->spaceBackground();
			p.getLocation()->action();


			std::cout << "PDA: We should go through the red portal first. " << std::endl;
			std::cout << "Please select an option below: " << std::endl;
			std::cout << "1. Go through red portal" << std::endl;
			
			choice = validateInt(input);
		while(choice < 1 || choice > 1)
			{
				std::cout << "Please enter a valid choice " << std::endl;
				choice = validateInt(input);
			}

			if (choice == 1)
			{
				p.moveDown();
			}
		}
		if (p.getLocation() == cf)
		{
			
			p.removeOxygen(15);
			std::cout << "Oxygen: " << p.getOxygen() << std::endl;
			p.getLocation()->getSpaceName();
			p.getLocation()->complete();
			p.getLocation()->spaceBackground();
			p.getLocation()->action();

			p.setLocation(main);
			std::cout << "PDA: I think we should go through the green portal then the blue portal to get a weapon, hopefully. " << std::endl;
			std::cout << "Please select an option below: " << std::endl;
			std::cout << "1. Go through green portal" << std::endl;
			std::cout << "2. Go through blue portal" << std::endl;
			std::cout << "3. Go to space shuttle " << std::endl;
			
			choice = validateInt(input);
			while(choice < 1 || choice > 3)
			{
				std::cout << "Please enter a valid choice " << std::endl;
				choice = validateInt(input);
			}

			if (choice == 1)
			{
				p.moveLeft();
			}

			else if (choice == 2)
			{
				p.moveRight();
			}

			else if (choice == 3)
			{
				p.moveUp();
			}

		}

		if (p.getLocation() == wf)
		{
			
			p.removeOxygen(15);
			std::cout << "Oxygen: " << p.getOxygen() << std::endl;
			p.getLocation()->getSpaceName();
			p.getLocation()->complete();
			p.getLocation()->spaceBackground();
			p.getLocation()->action();
			std::cout << "Please select an option below: " << std::endl;
			std::cout << "1. Go through blue portal" << std::endl;
			std::cout << "2. Go to space shuttle " << std::endl;
			
			choice = validateInt(input);
			while(choice < 1 || choice > 2)
			{
				std::cout << "Please enter a valid choice " << std::endl;
				choice = validateInt(input);
			}

			if (choice == 1)
			{
				p.setLocation(rf);

			}
			else
			{
				p.setLocation(ss);
			}
		}

		if (p.getLocation() == rf)
		{
			
			p.removeOxygen(15);
			std::cout << "Oxygen: " << p.getOxygen() << std::endl;
			p.getLocation()->getSpaceName();
			p.getLocation()->complete();
			p.getLocation()->spaceBackground();
			p.getLocation()->action();
			std::cout << "Please select an option below: " << std::endl;
			std::cout << "1. Go to space shuttle " << std::endl;
			std::cout << "2. Go through green portal" << std::endl;
			
			choice = validateInt(input);
			while(choice < 1 || choice > 2)
			{
				std::cout << "Please enter a valid choice " << std::endl;
				choice = validateInt(input);
			}

			if (choice == 1)
			{
				p.setLocation(ss);
			}
			else
			{
				p.setOxygen(0);
				p.setLocation(wf);
			}


		}

		if (p.getLocation() == ss)
		{
			
			p.removeOxygen(15);
			std::cout << "Oxygen: " << p.getOxygen() << std::endl;
			p.getLocation()->getSpaceName();
			p.getLocation()->complete();
			p.getLocation()->spaceBackground();
			p.getLocation()->action();
			std::cout << "Please select an option below: " << std::endl;
			std::cout << "1. Go to mountain island " << std::endl;
			
			choice = validateInt(input);
			while(choice < 1 || choice > 1)
			{
				std::cout << "Please enter a valid choice " << std::endl;
				choice = validateInt(input);
			}

			if (choice == 1)
			{
				p.moveUp();

			}	
		}
		if (p.getLocation() == mount)
		{
			
			p.removeOxygen(15);
			std::cout << "Oxygen: " << p.getOxygen() << std::endl;
			p.getLocation()->getSpaceName();
			p.getLocation()->complete();
			p.getLocation()->spaceBackground();
			p.getLocation()->action();

		}
	else
	{
		std::cout << "Game over! You have died! " << std::endl;
	}
	}
}
	

Game::~Game()
{
	delete lp;
	delete main;
	delete cf;
	delete rf;
	delete wf;
	delete ss;
	delete mount;
}

	
