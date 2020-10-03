/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bintree.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Ruslan <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/03 01:53:50 by Ruslan            #+#    #+#             */
/*   Updated: 2020/10/03 03:27:25 by Ruslan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bintree.h"

node::node(int i, int h)
{
	data.i = i;
	type = 'i';
	height = h;
	left = NULL;
	right = NULL;
}

node::node(char c, int h)
{
	data.c = c;
	type = 'c';
	height = h;
	left = NULL;
	right = NULL;
}

node::node(double d, int h)
{
	data.d = d;
	type = 'd';
	height = h;
	left = NULL;
	right = NULL;
}

node::~node() //рекуррентный деструктор для дерева
{
	delete left;
	delete right;
}

std::ostream& node::operator<<(std::ostream& os, const node& tree)
{
	if (tree)
	{
		switch(tree.type)
		{
			case 'i':
				os << tree.data.i;
				os << tree.left;
				os << tree.right;
				break;
			case 'd':
				os << tree.data.d;
				os << tree.left;
				os << tree.right;
				break;
			case 'c':
				os << tree.data.c;
				os << tree.left;
				os << tree.right;
				break;
			default:
				break;
		}
	}
	return (os);
}

std::istream& node::operator>>(std::istream& is, node& tree)
{
	if (!(tree.type)) //TODO set default value
	{
		std::cout << "whats data type? 'i' for int 'd' for double 'c' for char: ";
		is >> tree.type;
	}
	switch(tree.type)
	{
		case 'i':
			is >> tree.data.i;
			break;
		case 'd':
			is >> tree.data.d;
			break;
		case 'c':
			is >> tree.data.c;
			break;
		default:
			std::cout << "whats data type? 'i' for int 'd' for double 'c' for char: ";
			is >> tree.type;
			break;
	}
	return (is);
}

int		main()
{

	return (0);
}
