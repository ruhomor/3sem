#include "game.h"

PlayersState::PlayersState()
{
	printf("creating PlayersState");
}

void	PlayersState::init(int pnum)
{
	playersnum = pnum;
	std::ifstream		player(PLAYERS); //tmp player_file name

	for (int i = 0; i < playersnum; i++)
	{
		int		key, value;

		player >> key; //id
		player >> value; //helth points
		std::cout << "key " << key << " value " << value << '\n';
		this->insert(std::pair<int, int>(key, value));
	}
}

GameState::GameState(char **argv)
{
	const int				m = atoi(argv[1]);
	const int				n = atoi(argv[2]);
	const int				id = atoi(argv[3]);
	std::ifstream			mapstate(GAMEMAP); //tmp map_file name
	PlayersState			lifes;

	lifes.init(atoi(argv[4]));
	this->resize(n, std::vector<int>(m));

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
				std::cout << "my x " << x << " my y " << y << '\n';
			}
			(*this)[i][j] = lifes[someid];
			std::cout << someid << " has " << lifes[someid] << " lifes" << '\n';
		}
	}
}
