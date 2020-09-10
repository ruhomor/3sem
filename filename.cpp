#include <iostream>

using namespace std;

typedef	struct	s_something
{
	char	*mem;
}		t_something;

int	main()
{
	std::cout << sizeof(bool) << '\n';
	std::cout << sizeof(char) << endl;
	std::cout << sizeof(short) << endl;
	std::cout << sizeof(int) << endl;
	std::cout << sizeof(long long) << endl;
	std::cout << sizeof(float) << endl;
	std::cout << sizeof(double) << endl;
	std::cout << sizeof(long) << endl << endl;
	std::cout << sizeof(t_something) << endl;
	return (0);
}
