/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   3.cpp                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Ruslan <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/13 19:48:06 by Ruslan            #+#    #+#             */
/*   Updated: 2020/12/13 20:07:33 by Ruslan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

template <typename F, typename... Ts>
auto	functionCaller(F meme, Ts... args)
{
	meme(args...);
}

int		main()
{
	functionCaller([](int a, int b){ std::cout << a + b << '\n'; }, 1, 2);
	return (0);
}
