/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   2.cpp                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Ruslan <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/13 18:17:29 by Ruslan            #+#    #+#             */
/*   Updated: 2020/12/13 19:36:58 by Ruslan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "box.h"

template <typename T, typename... Ts>
T* createObj(Ts... args)
{
	return (new T(args...));
}

int		main()
{
	int		*arr = createObj<int>(1);
	std::cout << *arr << '\n';

	Box *mem = createObj<Box>(1, 2, 3);

	return (0);
}
