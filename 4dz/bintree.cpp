/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bintree.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Ruslan <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/03 01:53:50 by Ruslan            #+#    #+#             */
/*   Updated: 2020/10/18 22:50:56 by Ruslan           ###   ########.fr       */
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

int		balance(Node node)
{
	if (node)
		return (height(node->left) - height(node->right));
	return (0);
}

int		height(Node node)
{
	if (node)
		return (node->height);
	return (0);
}

void	Tree::leftRotate(Node rroot)
{
	Node newroot = rroot->right;

	rroot->right = newroot->left;
	if (newroot->left != NULL)
		newroot->left->parent = rroot;
	newroot->parent = rroot->parent;
	if (rroot->parent == NULL)
		this->root = newroot;
	else if (rroot == rroot->parent->left)
		rroot->parent->left = newroot;
	else
		rroot->parent->right = newroot;
	newroot->left = rroot;
	rroot->parent = newroot;
}

void	Tree::rightRotate(Node rroot)
{
	Node newroot = rroot->left;

	rroot->left = newroot->right;
	if (newroot->right != NULL)
		newroot->right->parent = rroot;
	newroot->parent = rroot->parent;
	if (!(rroot->parent))
		this->root = newroot;
	else if (rroot == rroot->parent->right)
		rroot->parent->right = newroot;
	else
		rroot->parent->left = newroot;
	newroot->right = rroot;
	rroot->parent = newroot;
}

void	Tree::insert(int d)
{
	Node	next = this->root;
	Node	cur = NULL;
	Node	node = new TypeNode;
	int		bs;

	node->data = d;
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
	if (cur)
		cur->height = std::max(height(cur->left), height(cur->right)) + 1;
	//balance?????
	bs = balance(cur);
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
//	printf("%d\n", tree.getRoot()->data);
	tree.postOrderMap([](Node node){ std::cout << node->data << ' '; });
	return (0);
}
