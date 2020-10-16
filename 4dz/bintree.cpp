/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bintree.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Ruslan <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/03 01:53:50 by Ruslan            #+#    #+#             */
/*   Updated: 2020/10/16 23:03:35 by Ruslan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bintree.h"

Tree::Tree()
{
	root = NULL;
}

std::ostream& operator<<(std::ostream& os, const Tree tree)
{
}

std::istream& operator>>(std::istream& is, Tree tree)
{
}

void	Tree::preOrderMap(Node node, std::function<void(Node node)> f)
{
	if (node)
	{
		f(node);
		Tree::preOrderMap(node->left, f);
		Tree::preOrderMap(node->right, f);
	}
}

void	Tree::preOrderMap(std::function<void(Node node)> f)
{
	if (Node node = this->root)
	{
		f(node);
		Tree::preOrderMap(node->left, f);
		Tree::preOrderMap(node->right, f);
	}
}

void	Tree::inOrderMap(Node node, std::function<void(Node node)> f)
{
	if (node)
	{
		f(node);
		Tree::inOrderMap(node->left, f);
		Tree::inOrderMap(node->right, f);
	}
}

void	Tree::inOrderMap(std::function<void(Node node)> f)
{
	if (Node node = this->root)
	{
		f(node);
		Tree::inOrderMap(node->left, f);
		Tree::inOrderMap(node->right, f);
	}
}

void	Tree::postOrderMap(Node node, std::function<void(Node node)> f)
{
	if (node)
	{
		f(node);
		Tree::postOrderMap(node->left, f);
		Tree::postOrderMap(node->right, f);
	}
}

void	Tree::postOrderMap(std::function<void(Node node)> f)
{
	if (Node node = this->root)
	{
		f(node);
		Tree::postOrderMap(node->left, f);
		Tree::postOrderMap(node->right, f);
	}
}

Node	Tree::getRoot()
{
	return (this->root);
}

void	Tree::insert(int k)
{
	Node	next = this->root;
	Node	cur = NULL;
	Node	node = new TypeNode;

	node->data = k;
	while (next)
	{
		cur = next;
		if (node->data < next->data)
			next = next->left;
		else
			next = next->right;
	}
	node->parent = cur;
	if (!(cur))
		root = node;
	else if (node->data < cur->data)
		cur->left = node;
	else
		cur->right = node;
	//balance?????
	int		bs;
	bs = node->left ?

}

int		main()
{
	Tree	tree;

	tree.insert(7);
	tree.insert(3);
	tree.insert(14);
	tree.insert(30);
	tree.insert(9);
	//tree.balance();
	printf("%d\n", tree.getRoot()->data);
	tree.postOrderMap([](Node node){ std::cout << node->data << ' '; });
	return (0);
}
