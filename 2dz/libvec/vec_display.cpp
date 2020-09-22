/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vec_display.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kachiote <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/22 18:55:09 by kachiote          #+#    #+#             */
/*   Updated: 2020/09/22 18:55:09 by kachiote         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libvec.h"

void	vec_display(std::vector < std::vector < double > > &vc, int n, int m, int sn, int sm)
{
	for (int i = sn; i < n; i++)
	{
		for (int j = sm; j < m; j++)
            std::cout << vc[i][j] << " ";
		std::cout << "\n";
	}
}
