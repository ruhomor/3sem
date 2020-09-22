/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vec_isin.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kachiote <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/22 18:45:04 by kachiote          #+#    #+#             */
/*   Updated: 2020/09/22 18:45:04 by kachiote         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libvec.h"

bool	vec_isin(std::vector<int> &vc, int num)
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
