/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bintree.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Ruslan <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/03 01:53:50 by Ruslan            #+#    #+#             */
/*   Updated: 2020/10/17 01:01:41 by Ruslan           ###   ########.fr       */
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

Node	rotateRight(Node root)
{
    Node newroot = root->left;
    Node tmp = newroot->right;

    newroot->right = root;
    root->left = tmp;
	root->height = std::max(height(root->left), height(root->right)) + 1;
	newroot->height = std::max(height(newroot->left), height(newroot->right)) + 1;
	return(newroot);
}

Node	rotateLeft(Node root)
{
    Node newroot = root->right;
    Node tmp = newroot->left;

    newroot->left = root;
    root->right = tmp;
    root->height = std::max(height(root->left), height(root->right)) + 1;
    newroot->height = std::max(height(newroot->left), height(newroot->right)) + 1;
    return(newroot);
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
	cur->height = std::max(height(cur->left), height(cur->right)) + 1;
	//balance?????
	bs = balance(cur);
	if (bs > 1 && d < cur->left->data)
		rotateRight(cur);
	if (bs < -1 && d > cur->right->data)
		rotateLeft(cur);
	if (bs > 1 && d > cur->left->data)
	{
		cur->left = rotateLeft(cur->left);
		rotateRight(cur);
	}
	if (bs < -1 && d < cur->right->data)
	{
		cur->right = rotateRight(cur->right);
		rotateLeft(cur);
	}
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
