#include <iostream>
#include <cmath>

#define SM 100
#define GR 1000
#define SEC 1

int	main()
{
	double 	a, b, c, d;

	std::cout << "Величина в СИ " << std::endl;
	std::cin >> a;
	std::cout << "Единица измерения величины" 
		<< " в основных величинах СИ"
		<< " (3 числа a, b, c),\n"
		<< "где м^{a} * кг^{b} * сек^{c}" << std::endl;
	std::cin >> b >> c >> d;
	std::cout << "Величина в СГС \n" 
		<< a * pow(SM, b) * pow(GR, c) * pow(SEC, d) 
		<< " см^" << b << " * гр^" << c << " * сек^" << d
		<< std::endl;
	return (0);
}
