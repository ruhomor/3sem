/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bintree.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Ruslan <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/02 22:00:28 by Ruslan            #+#    #+#             */
/*   Updated: 2020/10/16 22:27:39 by Ruslan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BINTREE_H

# define BINTREE_H

# include <iostream>
# include <stdlib.h>
# include <functional>
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

typedef struct	StructNode
{
	int			data;
	StructNode	*parent;
	StructNode	*left;
	StructNode	*right;
	int			height;
	StructNode()
	{
		printf("im working!\n");
		parent = NULL;
		left = NULL;
		right = NULL;
		height = 1;
		data = -1;
	}
}				TypeNode;

typedef TypeNode *Node; //Node is in fact pointer to node here ok?

class	Tree
{
	private:
		Node	root;
		void	initNode(Node, int);
	public:
		Tree();
		friend std::ostream& operator <<(std::ostream& os, Tree tree);
		friend std::istream& operator >>(std::istream& is, Tree tree);
		//friend void* operator new(size_t size, char type);
		Node	getRoot();
		int		getData(Node node);
		void	preOrderMap(std::function<void(Node node)> f);
		void	inOrderMap(std::function<void(Node node)> f);
		void	postOrderMap(std::function<void(Node node)> f);

		void	preOrderMap(Node node, std::function<void(Node node)> f);
		void	inOrderMap(Node node, std::function<void(Node node)> f);
		void	postOrderMap(Node node, std::function<void(Node node)> f);

		void	insert(int k);
};

#endif
