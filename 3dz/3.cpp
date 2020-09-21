#include <array>
#include <iostream>
#include <functional>

void	printarr(std::array<int, 10> arr)
{
	for (auto a: arr)
	{
		std::cout << a << " ";
	}
}

int		main()
{
	std::array<int, 10> arr = {1, 3, 8, 9, 5, 3, 2, 8, 6, 0};

	std::sort(arr.begin(), arr.end(), [](int a, int b) { return a > b; });
	printarr(arr);
	return (0);
}
