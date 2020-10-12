/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bintree.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Ruslan <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/03 01:53:50 by Ruslan            #+#    #+#             */
/*   Updated: 2020/10/12 14:50:19 by Ruslan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bintree.h"
/*
Node::Node(int h, char t, std::any i)
{
	data = i;
	height = h;
	type = t;
	left = NULL;
	right = NULL;
}
*/
Node::Node()
{
	left = NULL;
	right = NULL;
	height = 1;
	depth = 0;
}

Node::~Node() //рекуррентный деструктор для дерева
{
	delete left;
	delete right;
	delete this;
}

Node::Node(Node *tree)
{
	int		value;

	std::cout << "введите значение: ";
	std::cin >> data;
	height = tree->height - 1;
	depth = tree->depth + 1;
	if (data >= tree->data)
		tree->right = this;
	else
		tree->left = this;
}

Node::Node(Node *tree, int value)
{
	data = value;
	height = tree->height - 1;
	depth = tree->depth + 1;
	if (data >= tree->data)
		tree->right = this;
	else
		tree->left = this;
}

void	Node::PostOrderMap(Node *tree, void (*f)(Node *node))
{

}

std::ostream& operator<<(std::ostream& os, const Node *tree)
{
	if (tree)
		os << tree->data << ' ';
	os << tree->left << ' ';
	os << tree->right << ' ';
	return (os);
}

std::istream& operator>>(std::istream& is, Node *tree)
{
	std::cin >> tree->data;
	return (is);
}

void* operator new(size_t size)
{
	return ((Node*)malloc(size));
}

int		main()
{
	Node	tree;

	std::cin >> &tree;
	tree.left = new Node(&tree, 3);
	tree.right = new Node(&tree, 2);
	std::cout << &tree << "height: " << tree.height;
	return (0);
}
