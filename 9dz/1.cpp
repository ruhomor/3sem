/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   1.cpp                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Ruslan <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/13 17:04:27 by Ruslan            #+#    #+#             */
/*   Updated: 2020/12/13 18:15:04 by Ruslan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

//с выражением свертки
template <typename... Types>
auto	sizeOfSum1(Types... args)
{
	return (... + sizeof(args));
}

//во что транслируется код ниже
/*
//sizeOfSum(1, 1, 1.2, 'c');
int		sizeOfSum(int a, int b, double c, char d)
{
	return (sizeof(a) + sizeof(b) + sizeof(c) + sizeof(d));
}
*/
//перегрузка (условие выхода из рекурсии)
auto	sizeOfSum2(void)
{
	return (0);
}
//Без свертки (рекурсия)
template <typename First, typename... Types>
auto	sizeOfSum2(First a, Types... args)
{
	return (sizeof(a) + sizeOfSum2(args...));
}

int		main()
{
	std::cout << sizeOfSum1(1, 1, 1.2, 'c') << '\n';
	std::cout << sizeOfSum2(1, 1, 1.2, 'c') << '\n';
	return (0);
}
