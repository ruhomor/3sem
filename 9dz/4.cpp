/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   4.cpp                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Ruslan <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/13 20:08:24 by Ruslan            #+#    #+#             */
/*   Updated: 2020/12/13 20:15:19 by Ruslan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

void	printWords(void)
{
	return ;
}

template <typename First, typename... Types>
void	printWords(First mem, Types... args)
{
	std::cout << mem;
	printWords(args...);
}

int		main()
{
	printWords("meme", "2", "keke", 3, 4);
	return (0);
}
