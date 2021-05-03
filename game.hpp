/*************************************************************************************************************************************************************************************************************************************
 * Program Name: game.hpp
 * Author: Johnny Blanchard
 * Date:11/30/18
 * Description: This is the header file for the game class that will implement the game and link the 7 space structures together so the player can travel between them.
***********************************************************************************************************************************************************************************************************************************/

#ifndef GAME_HPP
#define GAME_HPP
#include "Player.hpp"
#include "Space.hpp"
#include "LifePod.hpp"
#include "MainIsland.hpp"
#include "ContaminationFacility.hpp"
#include "weaponsFacility.hpp"
#include "researchFacility.hpp"
#include "spaceShuttle.hpp"
#include "mountainIsland.hpp"

class Game
{
	private:
		Lifepod *lp;
		MainIsland *main;
		ContaminationFacility *cf;
		WeaponsFacility *wf;
		ResearchFacility *rf;
		SpaceShuttle *ss;
		MountainIsland *mount;
		Player p;
		Space *escape;
		Space *currLocation;
		int choice;
		bool won;
		std::string input;
	public:
		void menu();
		void play();
		void win();
		void lost();
		Game();
		~Game();

};

#endif

