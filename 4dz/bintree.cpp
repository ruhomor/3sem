/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bintree.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Ruslan <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/03 01:53:50 by Ruslan            #+#    #+#             */
/*   Updated: 2020/10/10 04:30:18 by Ruslan           ###   ########.fr       */
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
}

Node::~Node() //рекуррентный деструктор для дерева
{
	delete left;
	delete right;
}

void	Node::PostOrderMap(Node *tree, void (*f)(Node *node))
{

}

std::ostream& operator<<(std::ostream& os, const Node *tree)
{
	if (tree)
	{
		switch(tree->type)
		{
			case 'c':
				os << std::any_cast<char>(tree->data) << ' ';
				break;
			case 'd':
				os << std::any_cast<double>(tree->data) << ' ';
				break;
			case 'i':
				os << std::any_cast<int>(tree->data) << ' ';
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
			{
				char	c;
				is >> c;
				tree->data = c;
				break;
			}
		case 'i':
			{
				int		i;
				is >> i;
				tree->data = i;
				break;
			}
		case 'd':
			{
				double	d;
				is >> d;
				tree->data = d;
				break;
			}
		default:
			std::cout << "whats tree type? input\n'c' for char\n'd' for double\n 'i' for integer\n";
			std::cin >> tree->type;
			std::cin >> tree; //recursively asks fpr type lol
			break;
	}
	return (is);
}
/*
void* operator new(size_t size, Node& tree, std::any data)
{
	Node	*node;

	if ((node = (Node*)malloc(size)))
	{
		node->type = tree.type;
		node->height = tree.height + 1;
		switch(tree.type)
		{
			case 'c':
				node->data = std::any_cast<char>(data);
				break;
			case 'i':
				node->data = std::any_cast<int>(data);
				break;
			case 'd':
				node->data = std::any_cast<double>(data);
				break;
		}
	}
	return (node);
}
*/
void	heightplusplus(Node *node)
{
	node->height++;
}

void* operator new(size_t size, Node *tree, std::any value)
{
	Node	*newnode;

	if ((newnode = (Node*)malloc(size)))
	{
		newnode->type = tree->type;
		newnode->data = value;
		if (!((tree->left) || (tree->right)))
			tree->DaddyMap([](Node *node){ node->height++; });
		newnode->height = tree->height - 1;
		newnode->depth = tree->depth + 1;
		newnode->dad = tree;
		//newnode->DaddyMap(&heightplusplus);
	}
	switch(tree->type)
	{
		case 'c':
			if (std::any_cast<char>newnode->data
					>= std::any_cast<char>tree->data)
				tree->right = newnode;
			else
				tree->left = newnode;
			break;
		case 'd':
			if (std::any_cast<double>newnode->data
					>= std::any_cast<double>tree->data)
				tree->right = newnode;
			else
				tree->left = newnode;
			break;
		case 'i':
			if (std::any_cast<int>newnode->data
					>= std::any_cast<int>tree->data)
				tree->right = newnode;
			else
				tree->left = newnode;
			break;
	}
	return (newnode); //no need for that which is silly asf
}

void* operator new(size_t size, char type)
{
	Node	*newnode;

	if ((newnode = (Node*)malloc(size)))
	{
		std::cin >> newnode;
		newnode->type = type;
		newnode->dad = NULL;
		newnode->height = 0;
		newnode->depth = 0;
	}
	return (newnode);
}

/*
[](Node *node){ node->height++; }
*/
void	Node::DaddyMap(void (*f)(Node *node))
{
	Node	*tmp;

	tmp = dad;
	while (tmp)
	{
		(*f)(tmp);
		tmp = tmp->dad;
	}
}

int		main()
{
	Node	tree;

	tree.dad = NULL; //fix dis pls
	std::cin >> &tree;
	new(&tree) Node;
	new(&tree) Node;
	std::cin >> tree.left >> tree.right;
/*
	tree.left = new(tree, 2) Node;
	tree.right = new(tree, 2) Node;
	std::cin >> &tree;
*/
	std::cout << &tree << "height: " << tree.height;
	return (0);
}
