/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   2.cpp                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Ruslan <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/22 11:34:35 by Ruslan            #+#    #+#             */
/*   Updated: 2020/09/22 12:56:19 by Ruslan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <vector>
#include <iostream>

int		main(int argc, char **argv)
{
	std::vector<int>	vc;
	int					len;

	*argv++;
	argc--;
	while (argc--)
		vc.push_back(atoi(*argv++));
	len = vc.size();
	for(int i = 1; i < len; i++)
		for (int j = i; (j > 0) && (vc[j - 1] > vc[j]); j--)
			std::swap(vc[j], vc[j - 1]);
	for(int i = 0; i < len; i++)
		std::cout << vc[i] << " ";
	return (0);
}
