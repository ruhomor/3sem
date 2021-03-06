/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   1.cpp                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Ruslan <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/18 17:49:37 by Ruslan            #+#    #+#             */
/*   Updated: 2020/09/22 04:38:26 by Ruslan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "p.h"

/*
void	swap_rows(double **matrix, int i, int j)
{
	double	*tmp;

	tmp = matrix[i];
	matrix[i] = matrix[j];
	matrix[j] = tmp;
}
*/

void	display(double **matrix, int n, int m)
{
	for(int i = 0; i < n; i++)
	{
		for(int j = 0; j < m; j++)
			std::cout << matrix[i][j] << " ";
		std::cout << "\n";
	}
}
/*
void	vec_display(std::vector < std::vector < double > > &vc, int n, int m, int sn, int sm)
{
	for (int i = sn; i < n; i++) //n is not vec.size() on purpose ок да
	{
		for (int j = sm; j < m; j++) //tut tozhe m ne vec[i].size() on purpose
            std::cout << vc[i][j] << " ";
		std::cout << "\n";
	}
}
*/
void	inputm(double **matrix, int n, int m)
{
	for(int i = 0; i < n; i++)
		for(int j = 0; j < m; j++)
			std::cin >> matrix[i][j];
}

void	vec_inputm(std::vector < std::vector < double > > &vc, int n, int m)
{
	double				a;

	for(int i = 0; i < n; i++)
	{
		std::vector<double>	row;
		for(int j = 0; j < m; j++)
		{
			std::cin >> a;
			row.push_back(a);
		}
		vc.push_back(row);
	}
}

void	divide_row(double *row, int m, float s)
{
	for(int i = 0; i < m; row[i] = row[i] / s, i++);
}

void	vec_divide_row(std::vector <double> &row, int m, float s)
{
	for(int i = 0; i < m; row[i] = row[i] / s, i++);
}

void	substract_row(double *row1, double *row2, int m, float k) //substracts row2 from row1
{
	for(int i = 0; i < m; row1[i] -= row2[i] * k, i++);
}

void	vec_substract_row(std::vector <double> &row1, std::vector <double> &row2, int m, float k) //substracts row2 from row1
{
	for(int i = 0; i < m; row1[i] -= row2[i] * k, i++);
}

void	vec_gauss(std::vector <std::vector <double> > &vc, int n, int m)
{
	for(int i = 0; i < vc.size(); i++)
	{
		vec_remove_zeros(vc, m);
		if (vc[i][i] != 0)
		{
			vec_divide_row(vc[i], m, vc[i][i]);
			for(int j = i; j + 1 < vc.size(); j++) //прямой ход
				vec_substract_row(vc[j + 1], vc[i], m, vc[j + 1][i]);
		}
	}
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

bool	vec_is_zerorow(std::vector <double> &row)
{
	for(int i = 0; i < row.size(); i++)
		if (row[i] != 0)
			return (0);
	return (1);
}

void	vec_remove_zeros(std::vector< std::vector <double> > &vc, int m)
{
	for(int i = 0; i < vc.size(); i++)
		if(vec_is_zerorow(vc[i]))
		{
			vc[i].clear();
			vc.erase(vc.begin() + i);
		}
}

void	vec_gauss_reverse(std::vector< std::vector <double> > &vc, int n, int m)
{
	for(int i = vc.size() - 1; i >= 0; i--)
	{
		if (vc[i][i] != 0)
		{
			vec_divide_row(vc[i], m, vc[i][i]);
			for(int j = i; j - 1 >= 0; j--) //обратный ход
				vec_substract_row(vc[j - 1], vc[i], m, vc[j - 1][i]);
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

int		vec_first_nonzero(std::vector<double> &row)
{
	return (distance(begin(row), find_if(begin(row), end(row), [] (double x) { return x != 0; })));
}

void	vec_fill_zeros(std::vector<double> &row, int zeros)
{
	for(;zeros--;row.push_back(0));
}

std::vector<std::vector<double> >	vec_solve_plz(std::vector< std::vector <double> > vc, int n, int m)
{
	int									rang = vc.size();
	std::vector<std::vector<double> >	fsr(m - 1, std::vector<double> (m - rang, 0));
	//std::vector<std::vector<double> >	fsr(m, std::vector<double> (m - rang, 0));
	int									zeros;

	for(int i = 0; i < vc.size(); i++)
	{
		zeros = vec_first_nonzero(vc[i]);
		for(int j = zeros + 1; j < vc[i].size(); j++) //-1(b)
			vc[i][j] = -vc[i][j];
	}
	for(int i = 0; i < m - rang; i++) ////-1(b) stolbiki
		for(int j = 0; j < m - 1; j++) //-1(b)TODO make branchless //stroki
		{
			if(j < rang)
				fsr[j][i] = vc[j][i + rang];
			else
			{
				if(j == rang + i)
					fsr[j][i] = 1;
				else
					fsr[j][i] = 0;
			}
		}
	return (fsr);
}

int		main()
{
	int									n, m;
	double								**matrix;
	std::vector<std::vector<double> >	vc;
	std::vector<std::vector<double> >	fsr;

	std::cout << "Введите n и m\n";
	std::cin >> n >> m;
	matrix = new double *[n]; //allocation

	for(int i = 0; i < n; matrix[i] = new double [m], i++); //allocation
	//inputm(matrix, n, m);
	vec_inputm(vc, n, m);
	std::cout << "\n";
	//display(matrix, n, m);
	vec_display(vc, n, m);
	std::cout << "\n";
	//gauss(matrix, n, m);
	//display(matrix, n, m);
	vec_gauss(vc, n, m);
	vec_display(vc, vc.size(), m);
	std::cout << "\n";
	vec_gauss_reverse(vc, n, m);
	vec_display(vc, vc.size(), m);
	std::cout << "\nФСР\n";
	fsr = vec_solve_plz(vc, n, m);
	vec_display(fsr, m - 1, m - vc.size() - 1);
	std::cout << "\nЧАСТНОЕ РЕШЕНИЕ\n";
	vec_display(fsr, m - 1, m - vc.size(), 0, vc.size());
	//gauss_reverse(matrix, n, m);
	//display(matrix, n, m);
	//for(int i = 0; i < n; free(matrix[i]), i++); //free
	//free(matrix); //free
	return (0);
}
