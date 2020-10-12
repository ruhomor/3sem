/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bintree.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Ruslan <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/02 22:00:28 by Ruslan            #+#    #+#             */
/*   Updated: 2020/10/12 14:52:39 by Ruslan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BINTREE_H

# define BINTREE_H

# include <iostream>
# include <stdlib.h>
# include <functional>
# include "exception.h"
//# include <variant>
//# include <any>

//# define NODE_DATA std::variant<void*, char, int, float, double>
/*
union	node_data //я не знаю как это сделать нормально
{
	void	*ptr;
	int		i;
	double	d;
	char	c;
};
*/
class	Node
{
	public:
//		void											*data;
//		node_data										data;
		//NODE_DATA	data;
	//	std::any	data;
		int			data;
	//	char		type;
		int			height;
		int			depth;
		Node		*left;
		Node		*right;

	Node();
	Node(Node *tree, int value)
	//Node(Node *tree, std::any value);
	//Node(int = 0, char type, std::any data); //очень бесполезный конструктор

	~Node(); //рекуррентный деструктор для дерева

	//void	PostOrderMap(Node *tree, void (*f)(...));
	void	PostOrderMap(Node *tree, void (*f)(Node *node));
	//void	DaddyMap(void (*f)(...));
	//void	DaddyMap(std::function<void(...)> f);
	//setheights();
	friend std::ostream& operator <<(std::ostream& os, const Node *tree);
	friend std::istream& operator >>(std::istream& is, Node *tree);
	//friend void* operator new(size_t size, Node& tree, std::any data);
	friend void* operator new(size_t size, Node *tree, int value);
	friend void* operator new(size_t size, char type);
};

#endif
