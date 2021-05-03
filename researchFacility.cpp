/**************************************************************************************************************************************************************************************************************************************
 * Program Name: researchFacility.cpp
 * Author: Johnny Blanchard
 * Date: 11/25/18
 * Description: This is the implementation file for the ResearchFacility class.
***************************************************************************************************************************************************************************************************************************************/

#include "researchFacility.hpp"

//constructor
ResearchFacility::ResearchFacility()
{
	hasCure = false;
	cure = "Unknown disease cure";
	choice = -1;
	cureChoice = -1;
	item = "";
	infectChoice = -1;
	lockdown = true;
}

//empty destructor
ResearchFacility::~ResearchFacility()
{
}


void ResearchFacility::complete()
{
	if(!hasCure)
	{
		spaceBackground();
	}
	else
	{
		std::cout << "You are already cured, there is nothing else for you to do here. " << std::endl;
	}
}

//function to give background
void ResearchFacility::spaceBackground()
{
	if(!hasCure)
	{
		std::cout << "PDA: This is the last facility, if there is nothing that can help us get a cure we might be in a lot of trouble. " << std::endl;
		std::cout << "Survivor: Yeah, thanks for reminding me! " << std::endl;
		std::cout << "PDA: My analysis of this structure shows that some of it has been destroyed in the lower part. " << std::endl;
		std::cout << "Survivor: That might be a good place to start. " << std::endl;
	}
	else
	{
		std::cout << "You've already found the cure, you don't need to be here." << std::endl;
		
	}
}

//function to explore the structure
void ResearchFacility::action()
{
	while (choice != 3)
	{
		std::cout << "Please select an option below: " << std::endl;
		std::cout << "1. Search  the lower part " << std::endl;
		std::cout << "2. Go to lift lockdown" << std::endl;
		std::cout << "3. Leave " << std::endl;
		
		choice = validateInt(input);
		while(choice < 1 || choice > 3)
		{
			std::cout << "Please enter a valid choice " << std::endl;
			choice = validateInt(input);
		}

		switch (choice)
		{
		case 1:
		{
			structure.addItem(cure);
			std::cout << "As you start exploring the lower part... " << std::endl;
			std::cout << "You hear an ear-piercing screech. " << std::endl;
			std::cout << "Survivor: Yep, this is where I die! " << std::endl;
			std::cout << "You find an area named 'Cure research'. " << std::endl;
			std::cout << "You enter the area and it is completely destroyed and submerged in water. " << std::endl;
			std::cout << "Sea dragon Leviathan: Hello survivor, I have been waiting for your arrival! " << std::endl;
			std::cout << "Survivor: What do you mean? " << std::endl;
			std::cout << "Sea dragon Leviathan: The species that was here before you was extremely violent and only wanted to use the disease for war. " << std::endl;
			std::cout << "Sea dragon Leviathan: They were the ones who created the disease and planned to use it as a weapon. " << std::endl;
			std::cout << "Sea dragon Leviathan: It went wrong and plagues this entire planet. " << std::endl;
			std::cout << "Sea dragon Leviathan: It turns out that a Sea dragon Leviathan's offspring are born with a rare genetic mutation that are the cure. " << std::endl;
			std::cout << "Sea dragon Leviathan: I could cure you, or let you die? ";
			std::cout << " How do I know I can trust you? " << std::endl;
			std::cout << "Please select an option below: " << std::endl;
			std::cout << "1. You're right I come here as a means to further creation of weapons. " << std::endl;
			std::cout << "2. I am just lost and want to go home. " << std::endl;
			std::cout << "3. My planet has been destroyed and I wish to stay here and help cure the planet. I come in peace. " << std::endl;
			std::cout << "4. I will not harm another being for myself " << std::endl;
			
			cureChoice = validateInt(input);
			while(cureChoice < 1 || cureChoice > 4)
			{
				std::cout << "Please enter a valid choice " << std::endl;
				cureChoice = validateInt(input);
			}

			if (cureChoice == 1)
			{
				std::cout << "Sea dragon Leviathan: I will not help you, you can die a slow painful death! That is all you deserve for a person as low as yourself! " << std::endl;
				
			}

			else if (cureChoice == 2)
			{
				std::cout << "Sea dragon Leviathan: I am truly sorry and can't help you! I will not harm an offspring for you, as we are an endangered species. " << std::endl;
				
			}

			else if (cureChoice == 3)
			{
				std::cout << "Sea dragon Leviathan: Ah, if you are interested in helping then I will give you the cure. " << std::endl;
				hasCure = true;
				if ((player.full()))
				{
					player.addItem(cure);
					std::cout << "Updated inventory: ";
					player.printItems();
					std::cout << std::endl;
					player.setInfected(false);
				}
				else if (player.full())
				{
					std::cout << "You do not have enough room to carry this item. " << std::endl;
				}
			}


			else
			{
				std::cout << "Sea dragon Leviathan: I respect your decision and hope your last days are not painful. " << std::endl;
				
			}

			if (hasCure)
			{
				std::cout << "You leave the area with the Sea dragon Leviathan. " << std::endl;
				std::cout << "PDA: Why did you lie? You have no intentions of staying. " << std::endl;
				std::cout << "Survivor: Sometimes you do it because you have to. " << std::endl;
				std::cout << "PDA: I don't think you should have lied. " << std::endl;
			}
			break;

		}

		case 2:
		{
			std::cout << "Please insert your hand to test for unknown disease. " << std::endl;
			std::cout << "1. Insert hand" << std::endl;
			std::cout << "2. Do not insert hand" << std::endl;
			
			infectChoice = validateInt(input);
			while(infectChoice < 1 || infectChoice > 2)
			{
				std::cout << "Please enter a valid choice " << std::endl;
				infectChoice = validateInt(input);
			}

			if (infectChoice == 1)
			{
				if (player.getInfected())
				{
					std::cout << "Error you are infected, will not lift lockdown! " << std::endl;
				}
				else
				{
					std::cout << "The lockdown has been lifted. " << std::endl;
				}
			}
			break;
		}

		case 3:
		{

			break;
		}
		}
	}
}



