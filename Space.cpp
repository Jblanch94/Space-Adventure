/****************************************************************************************************************************************************************************************************************************************
 * Program Name: Space.cpp
 * Author: Johnny Blanchard
 * Date: 11/22/18
 * Description: This is the implementation of the space class.
******************************************************************************************************************************************************************************************************************************************/

#include "Space.hpp"
#include <iostream>

/* default constructor that will
 * intialize each of the spaces to null
 * and intialize the name of the space to nothing. */
Space::Space()
{
	top = NULL;
	bottom = NULL;
	left = NULL;
	right = NULL;
	spaceName = "";
	//lockdown = true;
	escaped = false;
	input = "";
	
	
}

/* constructor that will intialize 
 * the space pointers and name of the space */
Space::Space(Space *top, Space *bottom, Space *left, Space *right)
{
	this->top = top;
	this->bottom = bottom;
	this->left = left;
	this->right = right;
}

//empty destructor
Space::~Space()
{
}

void Space::setSpaces(Space *top, Space *bottom, Space *left, Space *right, std::string spaceName)
{
	this->top = top;
	this->bottom = bottom;
	this->left = left;
	this->right = right;
	this->spaceName = spaceName;
}

//setters
void Space::setSpaceName(std::string spaceName)
{
	this->spaceName = spaceName;
}


void Space::setTop(Space *top)
{
	this->top = top;
}

void Space::setBottom(Space *bottom)
{
	this->bottom = bottom;
}

void Space::setLeft(Space *left)
{
	this->left = left;
}

void Space::setRight(Space *right)
{
	this->right = right;
}

void Space::setEscaped(bool escaped)
{
	this->escaped = escaped;
}

//getters
std::string Space::getSpaceName()
{
	std::cout << "You are currently in: " << spaceName << std::endl;
	return spaceName;
}

Space *Space::getTop()
{
	return top;
}

Space *Space::getBottom()
{
	return bottom;
}

Space *Space::getLeft()
{
	return left;
}

Space *Space::getRight()
{
	return right;

}
	
bool Space::getEscaped()
{
	if(escaped)
	{
		return  true;
	}
	else
	{
		return false;
	}
}



