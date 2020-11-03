#include "game.h"

int									main(int argc, char **argv) // argv[1] - m argv[2] - n argv[3] - id argv[4]
{
	GameState	map(argv);

	srand(time(NULL));
	std::cout << rand() % 9;
	// 0 - stand still
	// 1 - move up
	// 2 - move right
	// 3 - move down
	// 4 - move left
	// 5 - shoot ip
	// 6 - shoot right
	// 7 - shoot down
	// 8 - shoot left
	return (0);
}
