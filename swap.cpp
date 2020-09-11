#include <iostream>

int	main()
{
	int a;
	int b;

	std::cout << "Введите a, b" << std::endl;
	std::cin >> a >> b;
	a = a + b;
	b = a - b;
	a = a - b;
	std::cout << a << b;
	return (0);
}
