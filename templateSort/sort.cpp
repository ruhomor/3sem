/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Ruslan <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/13 20:54:43 by Ruslan            #+#    #+#             */
/*   Updated: 2020/12/13 21:25:25 by Ruslan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <algorithm>

template <typename T, std::size_t N>
void	print( T (&array)[N])
{
	for(auto i = 0U; i < N ;++i)
		std::cout << array[i] << std::endl;
	for(auto value : array)
		std::cout << value << std::endl;
	std::for_each(array, array + N, [](auto value)
	{
		std :: cout << value << std :: endl ;
	});
}

template <typename T, typename F>
void	merge(T *a, std::size_t Firstindex, std::size_t m, std::size_t Lastindex, F cmp);

template <typename T, typename F>
void	mergeSort(T *a, std::size_t Firstindex, std::size_t Lastindex, F cmp)
{
	if (Firstindex < Lastindex)
	{
		std::size_t m = Firstindex + (Lastindex - Firstindex) / 2;

		mergeSort(a, Firstindex, m, cmp);
		mergeSort(a, m + 1, Lastindex, cmp);
		merge(a, Firstindex, m, Lastindex, cmp);
	}
}

template <typename T, typename F>
void	merge(T *a, std::size_t Firstindex, std::size_t m, std::size_t Lastindex, F cmp)
{
	std::size_t		x;
	std::size_t		y;
	std::size_t		z;
	std::size_t		sub1 = m - Firstindex + 1;
	std::size_t		sub2 =  Lastindex - m;
	T First[sub1];  //temp array
	T Second[sub2];

	for (x = 0; x < sub1; x++)
		First[x] = a[Firstindex + x];
	for (y = 0; y < sub2; y++)
		Second[y] = a[m + 1+ y];
	x = 0;
	y = 0;
	z = Firstindex;
	while (x < sub1 && y < sub2)
	{
		if (cmp(First[x], Second[y])) //cmp function
		{
			a[z] = First[x];
			x++;
		}
		else
		{
			a[z] = Second[y];
			y++;
		}
		z++;
	}
	while (x < sub1)
	{
		a[z] = First[x];
		x++;
		z++;
	}
	while (y < sub2)
	{
		a[z] = Second[y];
		y++;
		z++;
	}
}

template <typename T, typename F>
void	sort(T *array, std::size_t size, F cmp)
{
	mergeSort(array, 0, size - 1, cmp);
}


int		main()
{
	int a[] = { 2, 3, 2, 1 };

	print(a);
	sort(a, 4, [](int a, int b){ return (a > b); });
	print(a);
	return (0);
}
