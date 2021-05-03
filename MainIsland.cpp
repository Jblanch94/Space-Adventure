/**************************************************************************************************************************************************************************************************************************************
 * Program Name: MainIsland.cpp
 * Author: Johnny Blanchard
 * Date: 11/23/18
 * Description: This is the implementation file for the MainIsland class.
****************************************************************************************************************************************************************************************************************************************/

#include "MainIsland.hpp"

//constructor
MainIsland::MainIsland() : Space(top, bottom, left, right)
{
	 objectivesCompleted = false;
	 redCube = "Red energy cube";
	 greenCube = "Green energy cube";
	 blueCube = "Blue energy cube";
	 redCubeFound = false;
	 greenCubeFound = false;
	 blueCubeFound = false;
	choice = -1;
	itemChoice1 = -1;
	itemChoice2 = -1;
	itemChoice3 = -1;
	travelChoice = -1;
	std::string item = "";
}

//empty destructor
MainIsland::~MainIsland()
{
}

//function to check if objectives are complete
void MainIsland::complete()
{
	if((redCubeFound && (player.hasItem(redCube))) && (greenCubeFound && (player.hasItem(greenCube))) && (blueCubeFound && (player.hasItem(greenCube))))
	{
		
		std::cout << "You don't need to be here, you should leave. " << std::endl;
		
		
	}
	else
	{
		objectivesCompleted = false;
	}
}

//gives background and objective
void MainIsland::spaceBackground()
{
	if(!objectivesCompleted)
	{
		std::cout << "PDA: Survivor, my analyis of this island shows that we are not the first ones to be here. " << std::endl;
		std::cout << "PDA: It is unclear if they are still here. " << std::endl;
		std::cout << "PDA: I am picking up some strong energy waves resonating from this island. " << std::endl;
		std::cout << "PDA: There seem to 3 objects that are red, green and blue that require a large amount of energy." << std::endl;
		std::cout << "PDA: We need to find a way to power these." << std::endl;
		std::cout << "PDA: It is of your best interest to investigate this island fully, but be careful as other species may be violent. " << std::endl;
		structure.addItem(redCube);
		structure.addItem(greenCube);
		structure.addItem(blueCube);
		std::cout << "Items in this structure: ";
		structure.printItems();
		std::cout << std::endl;
	}
}
	

void MainIsland::action()
{
	
	if(!objectivesCompleted)
	{
		exploreMenu();
		
		choice = validateInt(input);
		while(choice < 1 || choice > 3)
		{
			std::cout << "Please enter a valid choice " << std::endl;
			choice = validateInt(input);
		}
	
		if (choice == 1)
		{

		
			std::cout << "You can't seem to find anything in the caves. " << std::endl;
			std::cout << "PDA: There seems to be something glowing the water down there. " << std::endl;
			std::cout << "Survivor: Guess I have no choice. " << std::endl;


			std::cout << "Survivor: Whoa, would you look at that!? " << std::endl;
			std::cout << "Survivor: It's so bright, I think it is red, but what do I know I'm color blind! " << std::endl;
			std::cout << "Survivor: Do you know what it does? " << std::endl;
			std::cout << "PDA: Its purpose is unclear to me, but it does have a signficant amount of enegy contained inside. " << std::endl;
			std::cout << "PDA: My guess would be that it is used to power something. " << std::endl;
				
			while(itemChoice1 != 1)
			{
				std::cout << "Please select an option below: " << std::endl;
				std::cout << "1. Add red cube to backpack " << std::endl;
				std::cout << "2. Leave red cube " << std::endl;
				
			itemChoice1 = validateInt(input);
			while(itemChoice1 < 1 || itemChoice1 > 2)
			{
				std::cout << "Please enter a valid choice " << std::endl;
				itemChoice1 = validateInt(input);
			}
			
				if ((itemChoice1 == 1) && (player.full()))
				{
					player.addItem(redCube);
					std::cout << "Items in inventory: ";
					player.printItems();
					std::cout << std::endl;
					structure.removeItem(redCube);
				 	redCubeFound = true;
				}
				else if((itemChoice1 == 1) && (!player.full())) 
				{
					std::cout << "You can not carry this item. " << std::endl;
				}
				else
				{
					std::cout << "You left the red cube. " << std::endl;
				}
				
				
					
			}
			exploreMenu();
			
			choice = validateInt(input);
			while(choice < 1 || choice > 3)
			{
				std::cout << "Please enter a valid choice " << std::endl;
				choice = validateInt(input);
			}
		}

		if(choice == 2)
		{
			std::cout << "You come across a glowing object that blends in with the grass. " << std::endl;
			std::cout << "You start to examine the object. " << std::endl;
			if (redCubeFound)
			{
				std::cout << "Survivor: Hey, look it is another cube but this one is green. " << std::endl;
				std::cout << "PDA: It would seem they are connected somehow. " << std::endl;
			}
			else if(!redCubeFound)
			{
				std::cout << "Survivor: What do you think this glowing green cube is? " << std::endl;
				std::cout << "PDA: I'm not quite sure of its purpose but it is emitting a lot energy so it could be used to power something. " << std::endl;
			}
				
			while(itemChoice2 != 1)
			{
				std::cout << "Please select an option below: " << std::endl;
				std::cout << "1. Add green cube to backpack " << std::endl;
				std::cout << "2. Leave green cube " << std::endl;
				
			itemChoice2 = validateInt(input);
			while(itemChoice2 < 1 || itemChoice2 > 2)
			{
				std::cout << "Please enter a valid choice " << std::endl;
				itemChoice2 = validateInt(input);
			}
		
				if((itemChoice2 == 1) && (player.full()))
				{
					player.addItem(greenCube);
					structure.removeItem(greenCube);
					std::cout << "Items in inventory: ";
					player.printItems();
					std::cout << std::endl;
				 	greenCubeFound = true;
				}
				else if((itemChoice2 == 1) && (player.full()))
				{
					std::cout << "You do not have enough room to carry this item. " << std::endl;
				}
				else
				{
					std::cout << "You chose to leave the green cube. " << std::endl;
				}
			
			}
			
			exploreMenu();
			
			choice = validateInt(input);
			while(choice < 1 || choice > 3)
			{
				std::cout << "Please enter a valid choice " << std::endl;
				choice = validateInt(input);
			}
		}

		if (choice == 3)
		{
			std::cout << "You come across a glowing object that is in the hands of a dead alien creature. " << std::endl;
			std::cout << "PDA: This is not good! " << std::endl;
			std::cout << "PDA: Whatever killed him was not violent. " << std::endl;
			std::cout << "PDA: My analysis shows that the same unknow disease you have contracted since landing is what killed our friend here. " << std::endl;
			std::cout << "Survivor: I guess this day could get worse! " << std::endl;

			while (itemChoice3 != 1)
			{
				std::cout << "Please select an option below: " << std::endl;
				std::cout << "1. Add blue cube to backpack " << std::endl;
				std::cout << "2. Leave blue cube " << std::endl;
				
			itemChoice3 = validateInt(input);
			while(itemChoice3 < 1 || itemChoice3 > 2)
			{
				std::cout << "Please enter a valid choice " << std::endl;
				itemChoice3 = validateInt(input);
			}

				if ((itemChoice3 == 1) && (player.full()))
				{
					player.addItem(blueCube);
					std::cout << "Items in inventory: " << std::endl;
					player.printItems();
					std::cout << std::endl;
					structure.removeItem(blueCube);
					blueCubeFound = true;
				}
				else if ((itemChoice3 == 1) && (!player.full()))
				{
					std::cout << "You do not have enough room to carry  this item. " << std::endl;

				}

				else
				{
					std::cout << "You chose to leave the blue cube. " << std::endl;
				}
			}
			if (!player.hasItem(redCube) && !player.hasItem(blueCube) && !player.hasItem(greenCube))
			{
				exploreMenu();
				
				choice = validateInt(input);
				while(choice < 1 || choice > 3)
				{
					std::cout << "Please enter a valid choice " << std::endl;
					choice = validateInt(input);
				}
			}
		}
		if(player.hasItem(redCube) && player.hasItem(blueCube) && player.hasItem(greenCube))
			{
				//std::cout << "You can only go to the portals if you have all three cubes. " << std::endl;
				std::cout << "You approach the three portals" << std::endl;
				std::cout << "You place all three cubes on the portals " << std::endl;
				player.removeItem(redCube);
				player.removeItem(blueCube);
				player.removeItem(greenCube);
				objectivesCompleted = true;
			}
		
			
			
		

	}
	
}




void MainIsland::exploreMenu()
{
	
	std::cout << "Please select an option below: " << std::endl;
	std::cout << "1. Explore the caves " << std::endl;
	std::cout << "2. Explore the forest " << std::endl;
	std::cout << "3. Explore the beach " << std::endl;

}



	
