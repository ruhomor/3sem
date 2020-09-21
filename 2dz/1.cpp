/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   1.cpp                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Ruslan <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/18 17:49:37 by Ruslan            #+#    #+#             */
/*   Updated: 2020/09/18 21:12:07 by Ruslan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

void	display(double **matrix, int n, int m)
{
	for(int i = 0; i < n; i++)
	{
		for(int j = 0; j < m; j++)
			std::cout << matrix[i][j] << " ";
		std::cout << "\n";
	}
}

void	inputm(double **matrix, int n, int m)
{
	for(int i = 0; i < n; i++)
		for(int j = 0; j < m; j++)
			std::cin >> matrix[i][j];
}

void	divide_row(double *row, int m, float s)
{
	for(int i = 0; i < m; row[i] = row[i] / s, i++);
}

void	substract_row(double *row1, double *row2, int m, float k) //substracts row2 from row1
{
	for(int i = 0; i < m; row1[i] -= row2[i] * k, i++);
}

void	gauss(double **matrix, int n, int m)
{
	for(int i = 0; i < n; i++)
	{
		if (matrix[i][i] != 0)
		{
			divide_row(matrix[i], m, matrix[i][i]);
			for(int j = i; j + 1 < n; j++) //прямой ход
				substract_row(matrix[j + 1], matrix[i], m, matrix[j + 1][i]);

		}
	}
}

void	gauss_reverse(double **matrix, int n, int m)
{
	for(int i = n - 1; i >= 0; i--)
	{
		if (matrix[i][i] != 0)
		{
			divide_row(matrix[i], m, matrix[i][i]);
			for(int j = i; j - 1 >= 0; j--) //обратный ход
				substract_row(matrix[j - 1], matrix[i], m, matrix[j - 1][i]);
		}
	}
}

int		main()
{
	int			n, m;
	double		**matrix;

	std::cout << "Введите n и m";
	std::cin >> n >> m;
	matrix = new double *[n]; //allocation

	for(int i = 0; i < n; matrix[i] = new double [m], i++); //allocation
	inputm(matrix, n, m);
	std::cout << "\n";
	display(matrix, n, m);
	std::cout << "\n";
	gauss(matrix, n, m);
	display(matrix, n, m);
	std::cout << "\n";
	gauss_reverse(matrix, n, m);
	display(matrix, n, m);
	for(int i = 0; i < n; free(matrix[i]), i++); //free
	free(matrix); //free
	return (0);
}
