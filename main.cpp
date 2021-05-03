#include "game.hpp"
#include <ctime>

int main()
{
	srand(time(NULL));
	Game game;
	game.menu();
	return 0;
}
