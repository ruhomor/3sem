/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   3.cpp                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Ruslan <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/22 12:30:58 by Ruslan            #+#    #+#             */
/*   Updated: 2020/09/22 12:48:24 by Ruslan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libvec/libvec.h"

bool	vec_isin(std::vector<int> &vc, int num) //бинпоиск здесь!
{
	int		r = vc.size() - 1;
	int		l = 0;

	for(int m = (l + r) / 2; l <= r; )
	{
		if (vc[m] < num)
			l = m + 1;
		else
		{
			if (vc[m] > num)
				r = m - 1;
		}
		return (1);
	}
	return (0);
}

int		main()
{
	std::vector<int>	vc;
	int					num;

	std::cout << "Введите число, которое необходимо найти: ";
	std::cin >> num;
	vec_input(vc);
	std::cout << vec_isin(vc, num) << " ";
	return (0);

}
