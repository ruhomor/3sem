/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gaem.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Ruslan <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/03 12:19:49 by Ruslan            #+#    #+#             */
/*   Updated: 2020/11/03 14:54:06 by Ruslan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GAEM_H

# include <GLFW/glfw3.h>
# include <vector>
# include <tuple>
# include <iostream>
# define WINX 640
# define WINY 480
# define MAPX 4
# define MAPY 3

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
