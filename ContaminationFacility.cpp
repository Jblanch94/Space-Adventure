/**************************************************************************************************************************************************************************************************************************************
 * Program Name: ContaminationFacility.cpp
 * Author: Johnny Blanchard
 * Date: 11/23/18
 * Description: This is the implementation file of the ContaminationFacility class.
***************************************************************************************************************************************************************************************************************************************/

#include "ContaminationFacility.hpp"

ContaminationFacility::ContaminationFacility() 
{
	choice = -1;
	 keyCard = "Computer key";
	keyFound = false;
	lockdownChoice = -1;
	objectivesCompleted = false;
}

//empty destructor
ContaminationFacility::~ContaminationFacility()
{
}


void ContaminationFacility::complete()
{
	if(!objectivesCompleted)
	{
		spaceBackground();
	}
	else if(objectivesCompleted)
	{
		std::cout << "You do not need to be here " << std::endl;
	
	}
}

//gives background for the facility
void ContaminationFacility::spaceBackground()
{
	if(!objectivesCompleted)
	{
		std::cout << "You teleport above a massive structure that is underwater. " << std::endl;
		std::cout << "You swim inside and you can breathe again. " << std::endl;
		std::cout << "Survivor: Whoa, where am I? " << std::endl;
		std::cout << "PDA: It appears that the portal you opened was some kind of teleportation device. " << std::endl;
		std::cout << "PDA: We are still on the same planet, we are just at a different location on the planet. " << std::endl;
		std::cout << "Survivor: This place is massive! " << std::endl;
		std::cout << "PDA: It is some kind of alien structure that is powered by the same energy that were in the energy cubes you used to get here. " << std::endl;
		std::cout << "PDA: I would be very careful to not do anything dangerous here, you don't know what will happen and other beings might still be here. " << std::endl;
	}
}

//function to explore the space
void ContaminationFacility::action()
{
	if (!objectivesCompleted)
	{
		while (choice != 4)
		{
			std::cout << "Please select an option below: " << std::endl;
			std::cout << "1. Go to computer terminals " << std::endl;
			std::cout << "2. Go to decontamination center " << std::endl;
			std::cout << "3. Go to main room " << std::endl;
			std::cout << "4. Leave this facility " << std::endl;
			
			choice = validateInt(input);
			while(choice < 1 || choice > 4)
			{
				std::cout << "Please enter a valid choice " << std::endl;
				choice = validateInt(input);
			}

			switch (choice)
			{
			case 1:
			{
				if (keyFound)
				{
					std::cout << "To gain access to terminal you must swipe keycard. " << std::endl;
					player.removeItem(keyCard);
					std::cout << "After you gain access to computer terminal you see tons of documents which could have useful information. " << std::endl;
					while (infoChoice != 5)
					{
						std::cout << "Please select an option below: " << std::endl;
						std::cout << "1. Disease " << std::endl;
						std::cout << "2. Lockdown " << std::endl;
						std::cout << "3. Weapons Facility " << std::endl;
						std::cout << "4. Research Facility " << std::endl;
						std::cout << "5. Leave computer terminal " << std::endl;

						
						infoChoice = validateInt(input);
						while(infoChoice < 1 || infoChoice > 5)
						{
							std::cout << "Please enter a valid choice " << std::endl;
							infoChoice = validateInt(input);
						}

						switch (infoChoice)
						{
						case 1:
						{
							std::cout << "PDA: I can translate for as it is not written in english. " << std::endl;
							std::cout << "This planet has been plagued by a bacterium disease that is fatal. " << std::endl;
							std::cout << "PDA: It says here that the disease broke out about 10,000 years ago. " << std::endl;
							std::cout << "PDA: We are alone, everyone that was here is either dead or left. " << std::endl;
							std::cout << "The final stages of the disease is your strength becomes about nothing and your body will start to fade. " << std::endl;
							std::cout << "It was too late for us by the time we realized we were infected. " << std::endl;
							std::cout << "There are two more facilities just like this one that were dedicated to finding a cure. " << std::endl;
							std::cout << "As far as we know there is no cure. " << std::endl;
							break;
						}

						case 2:
						{
							std::cout << "After we discovered there was a disease on this planet we put it into full lockdown. " << std::endl;
							std::cout << "Anything that attempts to leave or enter this planet will be destroyed! " << std::endl;
							std::cout << "PDA: That would explain how the cargo ship was destroyed. " << std::endl;
							std::cout << "The only way to lift the lockdown is to go to the research facility and shut it down, but to do that you have to be cured. " << std::endl;
							std::cout << "Survivor: So, there is no cure and if I call for a rescue they can't help. Yep, I'm screwed! " << std::endl;
							std::cout << "PDA: Survivor, no need to panic yet.  We still have the rest of this facility to search plus two others. " << std::endl;
							break;
						}

						case 3:
						{
							std::cout << "There is a weapons facility that can be reached by going through green portal on the main island. " << std::endl;
							std::cout << "The weapons facility was made to manufacture weapons to protect ourselves from the creatures in the water. " << std::endl;
							std::cout << "We believe the cure is contained in one of the createures of this planet. " << std::endl;
							std::cout << "We use the weapons as a means of safe transportation around this planet. " << std::endl;
							std::cout << "The weapons do not harm the creatures here by any means! " << std::endl;
							break;
						}

						case 4:
						{
							std::cout << "There is a research facility that was used to try to find a cure." << std::endl;
							std::cout << "We collected different species of creatures on this planet and study them. " << std::endl;
							std::cout << "Still as research goes there is no known cure yet! " << std::endl;
							std::cout << "You can get to the research facility by going through the blue portal. " << std::endl;
							break;
						}

						case 5:
						{
							objectivesCompleted = true;
							break;
						}

						}
					}
				}
				else
				{
					std::cout << "You need to go get the keycard. " << std::endl;
				}
			}
			break;


			case 2:
			{
				std::cout << "Decontamination Center " << std::endl;
				std::cout << "AI: Greetings! " << std::endl;
				std::cout << "AI: Welcome to the Decontmination Center! " << std::endl;
				std::cout << "AI: This center is used to treat infected with the cure. " << std::endl;
				std::cout << "AI: This center is not operational yet! " << std::endl;
				std::cout << "AI: We are still waiting for the cure to be found! " << std::endl;
				std::cout << "AI: But once it is we can treat you as soon as possible." << std::endl;
				std::cout << "Have a good day! " << std::endl;
				break;
			}

			case 3:
			{
				std::cout << "Main Room " << std::endl;

				std::cout << "1. Pick up keycard " << std::endl;
				std::cout << "2. Leave keycard " << std::endl;
				std::cin >> choice;
				if (choice == 1)
				{
						player.addItem(keyCard);
						keyFound = true;
						std::cout << "Inventory: ";
						player.printItems();
						std::cout << std::endl;
				}
				else
				{
					std::cout << "You left the keycard " << std::endl;
				}
				

				break;
			}
			

			case 4:
			{
				break;
			}
			}
		}
	}
}
	
					
						

		
