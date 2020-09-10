#include <iostream>

using namespace std;

#define NEWTON 100000

int	main()
{
	double 	a;

	std::cout << "Введите велечину в ньютонах" << endl;
	std::cin >> a;
	a = a * NEWTON;
	std::cout << a << " дин" << endl;
	return (0);
}
