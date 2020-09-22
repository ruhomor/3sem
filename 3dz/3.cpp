/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   3.cpp                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kachiote <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/22 21:52:11 by kachiote          #+#    #+#             */
/*   Updated: 2020/09/22 21:52:11 by kachiote         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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
	std::cout << '\n';
	std::sort(arr.begin(), arr.end(), [](int a, int b) { return a < b; });
	printarr(arr);
	return (0);
}
