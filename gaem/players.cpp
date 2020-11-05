#include "rules.h"
#include "players.h"

Player::Player(std::string aName, int iid, int hhp)
{
	algoName = aName;
	id = iid;
	hp = hhp;
	if (hp > 0)
		isAlive = true;
	else
		isAlive = false;
	std::cout << "newPlayer! id: " << id << " name: " << algoName << " hp: " << hp <<'\n';
}

int				Player::getId()
{
	return (id);
}

int				Player::getHP()
{
	return (hp);
}
int				Player::getAlive()
{
	return (isAlive);
}

std::string		Player::getName()
{
	return (algoName);
}

int				Player::getAction(std::string algoFolder,
		int alivePlayers, int maxX, int maxY)
{
	std::string		cmd = algoFolder + '/' + algoName + EXTENSION
		+ ' ' + std::to_string(maxX) + ' ' + std::to_string(maxY) + ' '
		+ std::to_string(id) + ' ' + std::to_string(alivePlayers); //max_x max_y id num_of_players
	std::cout << cmd << '\n'; //debug
	std::system(cmd.c_str());

	std::cout << std::ifstream("tmp.txt").rdbuf() << '\n'; //debug
	return (hp);
}

void			PlayerVec::writeToFile(std::string algoFolder)
{
	std::ofstream	fael(PLAYERS);

	std::cout << "HELLLLLOOOOO\n";
	if (fael.is_open())
	{
		for (int i = 1; i < (*this).size(); i++)
			fael << (*this)[i].getId() << ' ' << (*this)[i].getHP() << ' ';
		fael.close();
	}
	else
		std::cout << "Unable to open file\n";
}

int				PlayerVec::getAlivePlayersNum()
{
	int		count = 0;

	for (int i = 0; i < (*this).size(); i++)
		if ((*this)[i].getAlive())
			count++;
	return (count);
}

PlayerVec::PlayerVec(std::string algoFolder)
{
	int				id = 1;
	Player			zeroplayer("no_algo", 0, 0); //trashcoding

	this->push_back(zeroplayer); //we dont need this but whatever
	for(auto &p: fs::directory_iterator(algoFolder))
	{
		std::string		algoName = p.path();
		std::size_t		pos;

		if (algoName.find(EXTENSION) != std::string::npos)
		{
			pos = algoName.find(algoFolder) + 1 + algoFolder.length();
			algoName = algoName.substr(pos);
			algoName.resize(algoName.size() - EXTLEN); //TODO depends
			std::cout << algoName << '\n'; //debug
			Player	newplayer(algoName, id, HP);
			id++;
			this->push_back(newplayer);
		}
		std::cout << p.path() << '\n';
	}
    //fs::remove_all();
}
