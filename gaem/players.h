/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   players.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Ruslan <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/04 15:52:12 by Ruslan            #+#    #+#             */
/*   Updated: 2020/11/04 18:14:25 by Ruslan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PLAYERS_H

# define PLAYERS_H
# include <string>
# include <map>
/* for reading filenames */
# include <fstream>
# include <iostream>
# include <experimental/filesystem>
namespace fs = std::experimental::filesystem;

class	Player
{
private:
	std::string		algoname;
	int				hp, x, y, action;
//public:
//	Player(std::string);
//	int				getAction();
//	int				getX();
//	int				getY();
//	std::string		getName();
};

class	PlayerDict : public std::map<int, Player>
{
public:
	PlayerDict(std::string algofolder);
};

#endif
