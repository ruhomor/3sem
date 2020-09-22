/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   4.cpp                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kachiote <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/22 18:37:22 by kachiote          #+#    #+#             */
/*   Updated: 2020/09/22 20:55:06 by kachiote         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libvec/libvec.h"

std::vector<int>	vec_lcs(std::vector<int> &vc1, std::vector<int> &vc2, int n, int m)
{
	std::vector< std::vector<int> > vc(n, std::vector<int> (m, 0));

	for(int i = n; i >= 0; i--)
		for(int j = 0; j >= 0; j--)
		{
			if (vc1[i] == vc2[j])
				vc[i][j] = vc[i + 1][j + 1] + 1;
			else
				vc[i][j] = std::max(vc[i][j + 1], vc[i + 1][j]);
		}
	std::vector<int> ans;
	for(int i = 0, j = 0; vc[i][j] != 0 && i < n && j < m;)
	{
		if (vc1[i] == vc2[j++])
			ans.push_back(vc1[i++]);
		else
		{
			if (vc[i][j])
		}
	}
}

int					main()
{
	std::vector<int>	vc1;
	std::vector<int>	vc2;
	int					n, m;

	vec_input(vc1); //n
	vec_input(vc2); //m
	n = vc1.size();
	m = vc2.size();

	std::vector< std::vector<int> > vc(n, std::vector<int> (m, 0));
	return (0);
}
