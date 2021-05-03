/****************************************************************************************************************************************************************************************************************************************
 * Program Name: Lifepod.cpp
 * Author: Johnny Blanchard
 * Date: 11/22/18
 * Description: This is the implementation file of the lifepod class.
****************************************************************************************************************************************************************************************************************************************/

#include "LifePod.hpp"

//default constructor
Lifepod::Lifepod() : Space(top, bottom, NULL, NULL) 
{
	itemsCollected = false;
	oxygenTank = "oxygen tank";
	choice = -1;
	oxygenChoice = -1;
}

//empty destructor
Lifepod::~Lifepod()
{
}

//check if objectives are done
void Lifepod::complete()
{
	if(!itemsCollected)
	{
		spaceBackground();
	}
	else
	{
		std::cout << "You have already been here and there is nothing left to do here. " << std::endl;
	}
	
}
//funciton gives background for this space
void Lifepod::spaceBackground()
{
	if (!itemsCollected)
	{
		std::cout << "PDA: Greetings surrvivor I am your personal PDA and I will be here with you to assist you on your journey the best I can. " << std::endl;
		std::cout << "PDA: You are currently in the " << getSpaceName() << " ." << std::endl;
		std::cout << "PDA: I have scanned the atmosphere of the planet and the air is breathable for you, but the planet is mostly water. " << std::endl;
		std::cout << "PDA: I am now equipping you with a standard issued diving suit.  Please hold still while I do this... " << std::endl;
		std::cout << "PDA: You are now all set to begin your journey, I will always be here guiding you on your journey. Do you have any questions? " << std::endl;
		std::cout << "Survivor: What happened? I was supposed to wake up from hyper sleep in the main space cargo shuttle. " << std::endl;
		std::cout << "PDA: Ah, yes, well it turns out that the shuttle was destroyed when it entered this planet's atmoshphere and everyone onboard was ejected into personal emergency lifepods. " << std::endl;
		std::cout << "PDA: Any other questions? " << std::endl;
		std::cout << "Survivor: Well, this sucks! Where are the other survivors? " << std::endl;
		std::cout << "PDA: My scans indicate there are no survivors within a 200 m range. " << std::endl;
		std::cout << "Survivor: Alright, thank you. " << std::endl;
		std::cout << "PDA: My suggestion is to connect your superiors with the radio communications built into every lifepod. " << std::endl;
		std::cout << "Survivor: Right, good thinking! " << std::endl;
	
		int choice = 0;
		std::cout << "Please selection an option below: " << std::endl;
		std::cout << "1. Use radio communications " << std::endl;
		std::cout << "2. Explore the rest of the lifepod " << std::endl;
		choice = validateInt(input);
		while(choice < 1 || choice > 2)
		{
			std::cout << "Please enter a valid choice " << std::endl;
			choice = validateInt(input);
		}
	
		if (choice == 1)
		{
			std::cout << "Survivor: What?!? There's no power! " << std::endl;
			std::cout << "PDA: Oh right, I should have told you, the power is out and there is a leak in the lifepod. " << std::endl;
			std::cout << "Survivor: Wait, why didn't you tell me this before ?!? " << std::endl;
			std::cout << "PDA: I didn't wanna freak out, you just woke up from a deep sleep of about 100 years. " << std::endl;
			std::cout << "PDA: My best suggestion is you need to focus on just surviving for a bit. " << std::endl;
			std::cout << "PDA: You need to go to the wrecked space cargo ship and use their communications. " << std::endl;
			std::cout << "Survivor: Right, I should head there now then. " << std::endl;
			std::cout << "PDA: I hate to tell you this, but getting there won't be that easy. " << std::endl;
			std::cout << "PDA: We are not alone on this planet and the creatures that live in this water can be very dangerous. " << std::endl;
			std::cout << "PDA: Since we have arrived here I have been running anlyses on this planet and the creatures that live here. " << std::endl;
			std::cout << "PDA: Where the space cargo ship landed has been classified as the most dangerous parts of the planet. " << std::endl;
			std::cout << "PDA: There are creatures known as leviathans that dwell there.  There are several types of leviathans. " << std::endl;
			std::cout << "PDA: My suggested action is to prepare for this hard journey and explore the planet some more and see what other options arise. " << std::endl;
			std::cout << "PDA: There is a large island not too far from here, maybe try starting there. " << std::endl;
			
			std::cout << "PDA: There are some stuff here that you may need on your journey be sure to grab it before you leave. " << std::endl;
			structure.addItem(oxygenTank);
			std::cout << "Items in this room: ";
			structure.printItems();
			std::cout << std::endl;
			action();
		}

		if (choice == 2)
		{
			std::cout << "PDA: There are some stuff here that you may need on your journey be sure to grab it before you leave. " << std::endl;
			structure.addItem(oxygenTank);
			std::cout << "Items in this room: ";
			structure.printItems();
			std::cout << std::endl;
			action();
		}
	}
}

//function to explore the lifepod and get what you need
void Lifepod::action()
{
	while (!itemsCollected)
	{

		int choice = 0;
		std::cout << "PDA: I am going to run a diagnostic on you to see how your health is. " << std::endl;
		std::cout << "PDA: My analysis shows that you are fine for now. " << std::endl;
		std::cout << "PDA: Uh oh I have some very bad news, during my analysis it seems you have contracted an unknown disease. I will continue to monitor while I am still with you. " << std::endl;
		std::cout << "Survivor: This day couldn't get any worse! " << std::endl;


		std::cout << "As you look around the lifepod trying to find what you need, you spot 4 items that could be useful. " << std::endl;
		std::cout << "In the lifepod the items are: ";
		std::cout << "oxygen tank. " << std::endl;
		while (choice != 2)
		{
			std::cout << "Please select option below: " << std::endl;
			std::cout << "1. Add oxygen tank to inventory " << std::endl;
			std::cout << "2. Taken what you needed and go back  to game " << std::endl;
			
			choice = validateInt(input);
			while(choice < 1 || choice > 2)
			{
				std::cout << "Please enter a valid choice " << std::endl;
				choice = validateInt(input);
			}


			switch (choice)
			{

			case 1:
			{
				if (!structure.areaEmpty())
				{
					player.addItem(oxygenTank);
				}
				structure.removeItem(oxygenTank);
				break;
			}

			case 2:
			{
				std::cout << "Now that you have what you need lets get back to the game! " << std::endl;
				break;
			}
			}
		}


		std::cout << "Items in inventory: ";
		player.printItems();
		std::cout << std::endl;
		std::cout << "Items remaining in the lifepod: ";
		structure.printItems();
		std::cout << std::endl;

		while (oxygenChoice != 2)
		{
			std::cout << "Please select option below: " << std::endl;
			std::cout << "1. Put oxygen tank on diving suit " << std::endl;
			std::cout << "2. All good and want to keep playing? " << std::endl;
			
			oxygenChoice = validateInt(input);
			while(oxygenChoice < 1 || oxygenChoice > 2)
			{
				std::cout << "Please enter a valid choice " << std::endl;
				oxygenChoice = validateInt(input);
			}

			switch (oxygenChoice)
			{
			case 1:
			{
				player.removeItem(oxygenTank);
				player.addOxygen(90);
				std::cout << "Oxygen: " << player.getOxygen() << std::endl;
				break;
			}

			case 2:
			{
				std::cout << "PDA: You are all good to go! " << std::endl;
				break;
			}


			std::cout << "Items in inventory: ";
			player.printItems();
			std::cout << std::endl;

			std::cout << "Oxygen levels on diving suit: " << player.getOxygen() << std::endl;
			}
			itemsCollected = true;

		}
	}
}




	
	
	
	
