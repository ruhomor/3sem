/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bintree.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Ruslan <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/02 22:00:28 by Ruslan            #+#    #+#             */
/*   Updated: 2020/10/03 03:36:09 by Ruslan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BINTREE_H

# define BINTREE_H

# include <iostream>
# include <stdlib.h>

union	node_data //я не знаю как это сделать нормально
{
	void	*ptr;
	int		i;
	double	d;
	char	c;
};

class	node
{
	public:
		//void	*data;
		node_data	data;
		char		type;
		int			height;
		node		*left;
		node		*right;

	node(int i, int h = 0);
	node(char c, int h = 0);
	node(double d, int h = 0);

	~node(); //рекуррентный деструктор для дерева

	std::ostream& operator<<(std::ostream& os, const node& tree);
	std::istream& operator>>(std::istream& is, node& tree);
	}
}

#endif
