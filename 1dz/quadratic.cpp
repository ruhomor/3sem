#include <cmath>
#include <iostream>
#include <complex>

#define COMPLEX std::complex<double>

int	main()
{
	COMPLEX a, b, c, d, r;

	std::cout << "Введите a, b, c" << std::endl;
	std::cin >> a >> b >> c;
	if (real(a) == 0)
	{
		if (real(b) == 0)
		{
			if (real(c) == 0)
				std::cout << "Бесконечное кол-во решений" << std::endl;
			else
				std::cout << "Нет решений" << std::endl;
		}
		else
			std::cout << -real(c) / real(b) << std::endl;
	}
	else
	{
		d = b * b - COMPLEX(4, 0) * a * c;
		{
			{
				r = (-b + sqrt(d)) / (COMPLEX(2, 0) * a);
				if (imag(r) == 0)
					std::cout << "x1 = " << real(r) << std::endl;
				else
					std::cout << "x1 = " << real(r) << " + " << imag(r) << 'i' << std::endl;
				r = (-b - sqrt(d)) / (COMPLEX(2, 0) * a);
				if (imag(r) == 0)
					std::cout << "x2 = " << real(r) << std::endl;
				else
					std::cout << "x2 = " << real(r) << " + " << imag(r) << 'i' << std::endl;
			}
		}
	}
	return (0);
}
