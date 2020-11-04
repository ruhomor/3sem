/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Ruslan <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/04 00:54:59 by Ruslan            #+#    #+#             */
/*   Updated: 2020/11/04 13:48:46 by Ruslan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GAME_H

# define GAME_H
# include <iostream>
# include <fstream>
# include <stdlib.h>
# include <time.h>
# include <vector>
# include <map>
# define PLAYERS "players.txt"
# define GAMEMAP "map.txt"

class	PlayersState : public std::map<int, int>
{
private:
	int				playersnum;

public:
	PlayersState();
	void			init(int pnum);
};

class	GameState : public std::vector< std::vector<int> >
{
private:
	int				x, y, action;
	PlayersState	lifes;

public:
	GameState(int n);
	GameState(char **argv);
	int				GetMyHP();
	int				GetMyY();
	int				GetMyX();
	void			MoveUp();
	void			MoveDown();
	void			MoveLeft();
	void			MoveRight();
	void			ShootUp();
	void			ShootDown();
	void			ShootLeft();
	void			ShootRight();
};

#endif