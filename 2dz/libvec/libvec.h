/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libvec.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kachiote <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/22 18:40:19 by kachiote          #+#    #+#             */
/*   Updated: 2020/09/22 20:03:23 by kachiote         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBVEC_H

# define LIBVEC_H

# include <vector>
# include <iostream>
# define TRUE 1
# define FALSE 0

void	vec_input(std::vector<int> &vc);
bool	vec_isin(std::vector<int> &vc, int num);
void	vec_display(std::vector < std::vector < double > > &vc, int n, int m, int sn=0, int sm=0);

#endif
