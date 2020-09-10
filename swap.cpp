#include <iostream>

using namespace std;

int	main()
{
	unsigned int a;
	unsigned int b;

	std::cin >> a >> b;
	a = a + b;
	b = a - b;
	a = a - b;
	std::cout << a << b;
	return (0);
}
