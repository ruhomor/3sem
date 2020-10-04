/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bintree.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Ruslan <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/03 01:53:50 by Ruslan            #+#    #+#             */
/*   Updated: 2020/10/04 05:16:52 by Ruslan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bintree.h"

Node::Node(std::any i, int h, char t)
{
	data = i;
	height = h;
	type = t;
	left = NULL;
	right = NULL;
}

Node::Node()
{
	left = NULL;
	right = NULL;
}

Node::~Node() //рекуррентный деструктор для дерева
{
	delete left;
	delete right;
}

std::ostream& operator<<(std::ostream& os, const Node *tree)
{
	if (tree)
	{
		switch(tree->type)
		{
			case 'c':
				os << std::any_cast<char>tree->data << ' ';
				break;
			case 'd':
				os << std::any_cast<double>tree->data << ' ';
				break;
			case 'i':
				os << std::any_cast<int>tree->data << ' ';
				break;
		}
		os << tree->left << ' ';
		os << tree->right << ' ';
	}
	return (os);
}

std::istream& operator>>(std::istream& is, Node *tree)
{
	switch(tree->type)
	{
		case 'c':
			is >> std::any_cast<char>tree->data;
			break;
		case 'i':
			is >> std::any_cast<int>tree->data;
			break;
		case 'd':
			is >> std::any_cast<double>tree->data;
			break;
	}
	return (is);
}

void* operator new(size_t size, Node& tree, std::any data)
{
	Node	*node;

	node = (Node*)malloc(size);
	if (node != NULL)
	{
		switch(tree.type)
		{
			case 'c':
				node->data = std::any_cast<char>data;
				break;
			case 'i':
				node->data = std::any_cast<int>data;
				break;
			case 'd':
				node->data = std::any_cast<double>data;
				break;
		}
	}
	return (node);
}

int		main()
{
	Node	tree;

	tree.left = new Node;
	tree.right = new Node;
	std::cin >> &tree >> tree.left >> tree.right;
	std::cin >> &tree >> tree.left >> tree.right;
	std::cout << &tree;
	return (0);
}
