#include "map.h"

Map::Map(int m, int n) //Matrix[n][m]
{
	this->resize(n, std::vector<int>(m));
	init = true;
}

Map::Map() //Matrix[n][m]
{
	srand((unsigned int)time(0));
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

void	Map::randPlace(int id)
{
	int		x, y;

	y = rand() % (*this).size();
	x = rand() % (*this)[0].size();
	std::cout << "random placement x: "
		<< x << " y " << y << '\n';
	while ((*this)[y][x] != 0)
	{
		y = rand() % (*this).size();
		x = rand() % (*this)[0].size();
		std::cout << "random placement x: "
			<< x << " y " << y << '\n';
	}
	(*this)[y][x] = id;
}

bool	Map::isInit()
{
	return (init);
}

void	Map::setInit()
{
	init = true;
}
