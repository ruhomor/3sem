#include <cmath>
#include <iostream>

using namespace std;

int	main()
{
	double 	a, b, c, d;

	std::cout << "Введите a, b, c" << endl;
	std::cin >> a >> b >> c;
	if (a == 0)
	{
		if (b == 0)
		{
			if (c == 0)
				std::cout << "Бесконечное кол-во решений" << endl;
			else
				std::cout << "Нет решений" << endl;
		}
		else
			std::cout << -c / b << endl;
	}
	else
	{
		d = b * b - 4 * a * c;
		if (d < 0)
			std::cout << "Нет решений" << endl;
		else
		{
			if (d == 0)
				std::cout << "x = " << -b / (2 * a) << endl;
			else
			{
				std::cout << "x1 = " << (-b + sqrt(d)) / (2 * a) << endl;
				std::cout << "x2 = " << (-b - sqrt(d)) / (2 * a) << endl;
			}
		}
	}
	return (0);
}
