/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   players.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Ruslan <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/04 15:52:12 by Ruslan            #+#    #+#             */
/*   Updated: 2020/11/05 05:41:33 by Ruslan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PLAYERS_H

# define PLAYERS_H
# include <string>
/* for reading filenames */
# include <fstream>
# include <iostream>
# include <experimental/filesystem>
# include <vector>
# define EXTENSION ".player" //algo extension
# define EXTLEN 7 //it's len
namespace fs = std::experimental::filesystem;

class	Player
{
private:
	std::string		algoName;
	int				id, hp, x, y, action;
	bool			isAlive;
public:
	Player(std::string aName, int iid, int hhp);
	int				getId();
	int				getHP();
	int				getAction(std::string algoFolder);
//	int				getX();
//	int				getY();
//	std::string		getName();
};

class	PlayerVec : public std::vector<Player>
{
public:
	PlayerVec(std::string algofolder);
	void	writeToFile(std::string algoFolder);
};

#endif
