/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   4.cpp                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kachiote <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/22 22:35:40 by kachiote          #+#    #+#             */
/*   Updated: 2020/09/24 19:32:50 by Ruslan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <functional>
#include <iostream>
#include <vector>

double	calculate(double x, double y, std::function<double(double, double)> f)
{
	return (f(x, y));
}

void	init_fonk(std::vector< std::function<double(double, double)> >	&fonk)
{
	fonk.push_back([](double x, double y){ return (x + y); });
	fonk.push_back([](double x, double y){ return (x - y); });
	fonk.push_back([](double x, double y){ return (x * y); });
	fonk.push_back([](double x, double y){ return (x / y); });
}

int		main()
{
	std::vector< std::function<double(double, double)> >	fonk;
	int														a, b;

	std::cout << "Введите числа a и b:\n";
	std::cin >> a >> b;
	init_fonk(fonk);
	for(auto funk: fonk)
		std::cout << funk(a, b) << '\n';
	return (0);
}
