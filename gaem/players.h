/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   players.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Ruslan <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/04 15:52:12 by Ruslan            #+#    #+#             */
/*   Updated: 2020/11/06 04:53:01 by Ruslan           ###   ########.fr       */
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
# include <cstdio> //for file deletion
# define EXTENSION ".player" //algo extension
# define EXTLEN 7 //it's len
namespace fs = std::experimental::filesystem;

class	Player
{
private:
	std::string		algoName;
	int				id, hp, x, y, action;
	bool			isAlive, died;
public:
	Player(std::string aName, int iid, int hhp);
	int				getId();
	int				getHP();
	void			getNewAction(std::string algoFolder,
			int alivePlayers, int maxX, int maxY);
	bool			getAlive();
	bool			getDied();
	int				getAction();
//	int				getX();
//	int				getY();
	std::string		getName();
	void			decreaseHealth();
	void			updatePos(std::pair<int, int> coords);
};

class	PlayerVec : public std::vector<Player>
{
public:
	PlayerVec(std::string algofolder);
	void	writeToFile(std::string algoFolder);
	void	decreaseHealth(int id);
	int		getAlivePlayersNum();
};

#endif
