/****************************************************************************************************************************************************************************************************************************************
 * Program Name: Player.cpp
 * Author: Johnny Blanchard
 * Date: 11/22/18
 * Description: This is the implementation file for the player class.
***************************************************************************************************************************************************************************************************************************************/

#include "Player.hpp"
#include "Space.hpp"

//constructor that intializes its variables
Player::Player()
{
	infected = true;
	oxygen = 10;
}

//empty destructor
Player::~Player()
{
}

//setters
void Player::setLocation(Space *location)
{
	this->location = location;
}

int Player::getOxygen()
{
	return oxygen;
}

void Player::setOxygen(int o )
{
	oxygen = o;
}

void Player::setRescued(bool rescued)
{
	this->rescued = rescued;
}

bool Player::isRescued()
{
	return rescued;
}
	

//getters
Space *Player::getLocation()
{
	return location;
}

void Player::moveUp()
{
	if(location->getTop() != NULL)
	{
		this->location = location->getTop();
		std::cout << "You will be going to: " << location->getSpaceName() << std::endl;
	}
	else
	{
		std::cout << "You can't go that way. " << std::endl;
	}
}

void Player::moveDown()
{
	if(location->getBottom() != NULL)
	{
		this->location = location->getBottom();
		std::cout << "You will be going to: " << location->getSpaceName() << std::endl;
	}
	else
	{
		std::cout << "You can't go that way. " << std::endl;
	}
}

void Player::moveLeft()
{
	if(location->getLeft() != NULL)
	{
		this->location = location->getLeft();
		std::cout << "You will be going to: " << location->getSpaceName() << std::endl;
	}

	else
	{
		std::cout << "You can't go that way. " << std::endl;
	}
}

void Player::moveRight()
{
	if(location->getRight() != NULL)
	{
		this->location = location->getRight();
		std::cout << "You will be going to: " << location->getSpaceName() << std::endl;
	}
	else
	{
		std::cout << "You can't go that way. " << std::endl;
	}
}



//function to remove oxygen from player
void Player::removeOxygen(int noAir)
{
	oxygen -= noAir;
//	std::cout << "PDA: Survivor you have " << oxygen << " percent of oxygen remaining. If you reach 0 then you're chances of survival decrease dramatically. " << std::endl;
}

void Player::addOxygen(int air)
{
	oxygen += air;
}
//bool that returns true if survivor has died
bool Player::dead()
{
	if( (oxygen <= 0))
	{
		return true;
	}
	else
	{
		return false;
	}
}

//returns true if player's backpack is full
bool Player::full()
{
	return inventory.full();
}

//prints items in players backpack
void Player::printItems()
{
	inventory.printItems();
}	

//returns true if player has specific item
bool Player::hasItem(std::string itemName)
{
	return inventory.hasItem(itemName);
}

//add specific item to player's backpack
void Player::addItem(std::string itemName)
{
	inventory.addItem(itemName);
}

//removes specific item from player's backpack
void Player::removeItem(std::string itemName)
{
	inventory.removeItem(itemName);
}

//set infected status of survivor
void Player::setInfected(bool infected)
{
	this->infected = infected;
}

//get whether survivor is infected
bool Player::getInfected()
{
	if(infected)
	{
		return true;
	}
	else
	{
	}	return false;
}	


void Player::setEscaped(bool escaped)
{
	this->escaped = escaped;
}

bool Player::getEscaped()
{
	return escaped;
}	
