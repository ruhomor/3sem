#include "map.h"

Map::Map(int m, int n) //Matrix[n][m]
{
	this->resize(n, std::vector<int>(m));
	init = true;
}

Map::Map() //Matrix[n][m]
{
	init = false;
}

void	Map::display()
{
	for (int i = 0; i < (*this).size(); i++)
	{
		for (int j = 0; j < (*this)[i].size(); j++)
			 std::cout << (*this)[i][j] << ' ';
		std::cout << '\n';
	}
}

bool	Map::isInit()
{
	return (init);
}

void	Map::setInit()
{
	init = true;
}
