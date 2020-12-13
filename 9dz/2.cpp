/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   2.cpp                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Ruslan <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/13 18:17:29 by Ruslan            #+#    #+#             */
/*   Updated: 2020/12/13 18:33:37 by Ruslan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

//с выражением свертки

class Box
{
public:
	Box(int xi, int yi, int zi)
	{
		x = xi;
		y = yi;
		z = zi;
		std::cout << x << y << z << '\n';
	}
private:
	double x, y, z;
};

template <typename... Types>
auto	createObj(typename objname, Types... args)
{
	return (new objname(args...));
}

int		main()
{
	createObj(Box, 1, 2, 3);
	return (0);
}
