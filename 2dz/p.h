/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   p.h                                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Ruslan <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/21 19:14:05 by Ruslan            #+#    #+#             */
/*   Updated: 2020/09/22 04:34:30 by Ruslan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef P_H
# define P_H

# include <iostream>
# include <algorithm>
# include <vector>

void	vec_remove_zeros(std::vector< std::vector <double> > &vc, int m);
void	display(double **matrix, int n, int m);
void	inputm(double **matrix, int n, int m);
void	vec_display(std::vector < std::vector < double > > &vc, int n, int m, int sn=0, int sm=0);
void	vec_inputm(std::vector < std::vector < double > > &vc, int n, int m);
void	divide_row(double *row, int m, float s);
void	vec_divide_row(std::vector <double> &row, int m, float s);
void	substract_row(double *row1, double *row2, int m, float k); //substracts row2 from row1
void	vec_substract_row(std::vector <double> &row1, std::vector <double> &row2, int m, float k); //substracts row2 from row1
void	vec_gauss(std::vector <std::vector <double> > &vc, int n, int m);
void	gauss(double **matrix, int n, int m);
bool	vec_is_zerorow(std::vector <double> &row);
void	vec_remove_zeros(std::vector< std::vector <double> > &vc, int m);
void	vec_gauss_reverse(std::vector< std::vector <double> > &vc, int n, int m);
void	gauss_reverse(double **matrix, int n, int m);

#endif
