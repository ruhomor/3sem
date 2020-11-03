#include <iostream>
#include <fstream>
#include <stdlib.h>
#include <time.h>
#include <vector>
#include <map>
//#include <sh.h>

std::vector <std::vector <int> >	getMap(char **argv, size_t &x, size_t &y)
{
	const int						m = atoi(argv[1]);
	const int						n = atoi(argv[2]);
	const int						id = atoi(argv[3]);
	const int						playersnum = atoi(argv[4]);
	std::vector<std::vector<int> >	map(n);
	std::map<int, int>				lifes;

	/* reading information about players stored as pairs of id's and lifes */
	std::ifstream					player("players.txt"); //tmp players_file name

	for (int i = 0; i < playersnum * 2; i++)
	{
		int		key, value;

		player >> key; //id
		player >> value; //helth points
		lifes.insert(std::pair<int, int>(key, value));
	}

	/* reading gameMap state stored as player id's on the map itself */
	std::ifstream					mapstate("map.txt"); //tmp map_file name
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			int		someid;

			mapstate >> someid;
			if (someid == id)
			{
				x = j;
				y = i;
			}
			map[j].push_back(lifes[someid]);
		}
	}
	return (map);
}

int									main(int argc, char **argv) // argv[1] - m argv[2] - n argv[3] - id argv[4]
{
	size_t	x, y;
	std::vector <std::vector <int> >	map = getMap(argv, x, y);

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
