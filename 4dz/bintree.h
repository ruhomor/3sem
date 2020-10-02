/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bintree.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Ruslan <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/02 22:00:28 by Ruslan            #+#    #+#             */
/*   Updated: 2020/10/02 22:44:51 by Ruslan           ###   ########.fr       */
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
		node		*left;
		node		*right;
	node(int i)
	{
		data.i = i;
		type = 'i';
		left = NULL;
		right = NULL;
	}
	node(char c)
	{
		data.c = c;
		type = 'c';
		left = NULL;
		right = NULL;
	}
	node(double d)
	{
		data.d = d;
		type = 'd';
		left = NULL;
		right = NULL;
	}
	~node(node *root) //рекуррентный деструктор для дерева
	{
		if (root)
		{
			delete root->left;
			delete root->right;
			delete root;
		}
	}
	ostream& operator<<(ostream& os, const node& tree)
	{
		switch(tree.type)
		{
			case 'i':
				os << tree.data.i <<
		}
		os << dt.mo << '/' << dt.da << '/' << dt.yr;
		return os;
	}
}

#endif
