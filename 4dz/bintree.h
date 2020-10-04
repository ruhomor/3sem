/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bintree.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Ruslan <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/02 22:00:28 by Ruslan            #+#    #+#             */
/*   Updated: 2020/10/04 04:40:33 by Ruslan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BINTREE_H

# define BINTREE_H

# include <iostream>
# include <stdlib.h>
//# include <variant>
# include <any>

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
		std::any	data;
		char		type;
		int			height;
		Node		*left;
		Node		*right;

	Node();
	Node(std::any = 0, int = 0, char = 0);

	~Node(); //рекуррентный деструктор для дерева

	//setheights();
	friend std::ostream& operator <<(std::ostream& os, const Node *tree);
	friend std::istream& operator >>(std::istream& is, Node *tree);
	friend void* operator new(size_t size, Node& tree, std::any data);
};

#endif
