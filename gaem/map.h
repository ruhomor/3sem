/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Ruslan <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/03 17:36:47 by Ruslan            #+#    #+#             */
/*   Updated: 2020/11/03 17:41:01 by Ruslan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MAP_H

# define MAP_H
# include <vector>
# include <iostream>

class	Map : public std::vector < std::vector<int> >
{
private:
//	std::vector < std::vector < int > > matrix;
	bool	init = false;

public:
	Map();
	Map(int m, int n);
	bool isInit();
	void setInit();
	void gameStep();
	void display();
};

#endif