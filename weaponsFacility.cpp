/******************************************************************************************************************************************************************************************************************************************
 * Program Name: weaponsFacility.cpp
 * Author: Johnny Blanchard
 * Date: 11/25/18
 * Description: This is the implementation file for the weapons facility class.
*******************************************************************************************************************************************************************************************************************************************/

#include "weaponsFacility.hpp"

//constructor
WeaponsFacility::WeaponsFacility()
{
	hasWeapon = false;
	teleportRay = "teleportation transporter";
	dimensionalRay = "dimensional transporter";
	freezeCannon = "Freeze cannon";
	choice = -1;
	weaponChoice = -1;
	item = "";
	objectivesCompleted = false;
}

//empty destructor
WeaponsFacility::~WeaponsFacility()
{
}


void WeaponsFacility::complete()
{
	if(!objectivesCompleted)
	{
		spaceBackground();
	}
	else
	{
		std::cout << "You do not need to be here" << std::endl;
	}
}

//function to give background 
void WeaponsFacility::spaceBackground()
{
	if(!hasWeapon)
	{
		std::cout << "Survivor: What do you make of this place? " << std::endl;
		std::cout << "PDA: According to the documents this should be the weapons facility. " << std::endl;
		std::cout << "PDA: Maybe take a look around, if there are working weapons here they could be helpful. " << std::endl;
		std::cout << "Survivor: Yeah, you're right. Time to take a look around! " << std::endl;
	}

	else
	{
		std::cout << "You have already been here and there is nothing left to do here! " << std::endl;
	}
}

//function to explore the area 
void WeaponsFacility::action()
{
	if(!hasWeapon)
	{
		while(choice != 2)
		{
			std::cout << "Please select an option below: " << std::endl;
			std::cout << "1. Go to Armory " << std::endl;
			std::cout << "2. Leave " << std::endl;
			
			choice = validateInt(input);
			while(choice < 1 || choice > 2)
			{
				std::cout << "Please enter a valid choice " << std::endl;
				choice = validateInt(input);
			}

			switch(choice)
			{
				case 1:
				{
					structure.addItem(freezeCannon);
					structure.addItem(teleportRay);
					structure.addItem(dimensionalRay);
					std::cout << "Items in this structure: ";
					structure.printItems();
					std::cout << std::endl;
					std::cout << "You are now in the armory of the Weapons Facility " << std::endl;
					std::cout << "PDA: You should pick a weapon so we can be on our way. " << std::endl;
					std::cout << "Survivor: I have no clue what to pick. " << std::endl;
					std::cout << "PDA: It looks like there are three types of weapons here. " << std::endl;
					std::cout << "PDA: The first weapon is called a Freeze Cannon: ";
					std::cout << " It appears fully functional and will freeze an object, it appears to last a long time. ";
					std::cout << " It appears that when using it on a creature here your survival rate is 50%. " << std::endl;
					std::cout << std::endl;
				
					std::cout << "PDA: The second weapons is a weapon that will teleport an object to another place. " << std::endl;
					std::cout << "PDA: It is a protoype and has a malfunction chance of 20%. " << std::endl;
					std::cout << "PDA: If it does work though your survival rate is 80%. " << std::endl;
	
					std::cout << "PDA: The third weapon is a weapon that transports an object to another dimension. " << std::endl;
					std::cout << "PDA: It is a prototype and has a malfunction chance of 40%. " << std::endl;
					std::cout << "PDA: If it does work though your survival rate is 100%. " << std::endl;
				
					std::cout << "Please select an option below: " << std::endl;
					std::cout << "1. Freeze Cannon " << std::endl;
					std::cout << "2. Teleportation transporter "  << std::endl;
					std::cout << "3. Dimensional transporter " << std::endl;
					
					weaponChoice = validateInt(input);
					while(weaponChoice < 1 || weaponChoice > 3)
					{
						std::cout << "Please enter a valid choice " << std::endl;
						weaponChoice = validateInt(input);
					}

					if (weaponChoice == 1)
					{
						if((player.full()))
						{
							if (hasWeapon)
							{
								std::cout << "You can only take one weapon." << std::endl;
							}
							else
							{
								player.addItem(freezeCannon);
								structure.removeItem(freezeCannon);
								std::cout << "Updated inventory: ";
								player.printItems();
								std::cout << std::endl;
								hasWeapon = true;
							}
						}

						else
						{
							std::cout << "You do not have enough room to carry this item. " << std::endl;
						}
					}

					else if(weaponChoice == 2)
					{
						if((player.full()))
						{
							if (hasWeapon)
							{
								std::cout << "You can only take one weapon. " << std::endl;
							}
							else
							{
								player.addItem(teleportRay);
								structure.removeItem(teleportRay);
								std::cout << "Updated inventory: ";
								player.printItems();
								std::cout << std::endl;
								hasWeapon = true;
							}
						}
						
						else
						{
							std::cout << "You do not have enough room to carry this item. " << std::endl;
						}
					}

					else
					{
						if((player.full()))
						{
							if (hasWeapon)
							{
								std::cout << "You can only take one weapon." << std::endl;
							}
							else
							{
								player.addItem(dimensionalRay);
								structure.removeItem(dimensionalRay);
								std::cout << "Updated inventory: ";
								player.printItems();
								std::cout << std::endl;
								hasWeapon = true;
							}
						}
			
						else
						{
							std::cout << "You do not have enough room to carry this item. " << std::endl;
						}
					}
					hasWeapon = true;
					break;
					
				}
				case 2:
				{
					std::cout << "As you start to leave..." << std::endl;
					std::cout << "There appears to be something that is withering away coming close towards." << std::endl;
					std::cout << "Alien: I need your body so I can leave this place! " << std::endl;
					std::cout << "Surivor: What!? You can't have my body! " << std::endl;
					std::cout << "Survivor: Plus how would you even take it?" << std::endl;
					std::cout << "Alien: You wanna see?" << std::endl;
					std::cout << "Survivor: Nope!" << std::endl;
					std::cout << "You start to pull out your weapon..." << std::endl;
					if (player.hasItem(freezeCannon))
					{
						int freeze = rand() % 100 + 0;
						if (freeze < 50)
						{
							player.setOxygen(0);
							std::cout << "Oxygen: " << player.getOxygen() << std::endl;
						}
						else
						{
							std::cout << "You have frozen the alien which allows you time to escape! " << std::endl;
						}
					}

					else if (player.hasItem(teleportRay))
					{
						int malfunction = rand() % 100 + 0;
						if (malfunction < 20)
						{
							std::cout << "The teleporter ray did not work! " << std::endl;
							player.setOxygen(0);
							std::cout << "Oxygen: " << player.getOxygen() << std::endl;
						}

						else
						{
							int teleport = rand() % 100 + 0;
							if (teleport > 80)
							{
								player.setOxygen(0);
								std::cout << "Oxygen: " << player.getOxygen() << std::endl;
							}
							else
							{
								std::cout << "You have teleported the alien somewhere else, which allows you to escape. " << std::endl;
							}
						}
					}

					else if (player.hasItem(dimensionalRay))
					{
						int malfunction = rand() % 100 + 0;
						if (malfunction < 40)
						{
							std::cout << "The dimensional ray did not work! " << std::endl;
							player.setOxygen(0);
							std::cout << "Oxygen: " << player.getOxygen() << std::endl;
						}
						else
						{
							int dimension = rand() % 100 + 0;
							if (dimension <= 100)
							{
								std::cout << "You have teleported the alien to another dimension, which allows you to escape. " << std::endl;
							}
						}
					}
					
					break;
				}
			}
		}
	}
	objectivesCompleted = true;
}
	


	

