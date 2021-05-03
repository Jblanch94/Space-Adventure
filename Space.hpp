/*****************************************************************************************************************************************************************************************************************************************
 * Program Name: Space.hpp
 * Author: Johnny Blanchard
 * Date: 11/22/18
 * Description: This is the header file for the parent space class that will have four space pointers that will point to the surrounding spaces occupied by the player.  It will have virtual functions for the player to do that are specific to each space. 
******************************************************************************************************************************************************************************************************************************************/

#ifndef SPACE_HPP
#define SPACE_HPP
#include <string>

//forward delcaration
//https://en.cppreference.com/w/cpp/language/class
class Player;
#include "Player.hpp"
#include "spaceContainer.hpp"
#include "validation.hpp"

class Space
{
	protected:
		Space *top;
		Space *bottom;
		Space *left;
		Space *right;
		std::string spaceName;
		bool lockdown;
		bool escaped;
		Player player;
		SpaceContainer structure;
		std::string oxygenTank;
		std::string input;


	public:
		Space();
		Space(Space *top, Space *bottom, Space *left, Space *right);
		virtual ~Space();
		void setTop(Space *top);
		void setBottom(Space *bottom);
		void setLeft(Space *left);
		void setRight(Space *right);
		void setSpaceName(std::string spaceName);
		std::string getSpaceName();
		void setSpaces(Space *, Space *, Space *, Space *, std::string);
		Space *getTop();
		Space *getBottom();
		Space *getLeft();
		Space *getRight();
		bool getEscaped();
		void setEscaped(bool);
		virtual void spaceBackground() = 0;
		virtual void action() = 0;
		virtual void complete() = 0;
};

#endif
