#include "rules.h"
#include "players.h"

Player::Player(std::string aName, int iid, int hhp)
{
	algoName = aName;
	id = iid;
	hp = hhp;
	died = false;
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
bool			Player::getAlive()
{
	return (isAlive);
}

std::string		Player::getName()
{
	return (algoName);
}

int				Player::getAction()
{
	return (action);
}

void			Player::updatePos(std::pair<int, int> coords)
{
	x = coords.first;
	y = coords.second;
}

void			Player::getNewAction(std::string algoFolder,
		int alivePlayers, int maxX, int maxY)
{
	std::string			cmd = algoFolder + '/' + algoName + EXTENSION
		+ ' ' + std::to_string(maxX) + ' ' + std::to_string(maxY) + ' '
		+ std::to_string(id) + ' ' + std::to_string(alivePlayers); //max_x max_y id num_of_players
	action = 0;

	std::cout << cmd << '\n'; //debug
	std::system(cmd.c_str());
	//std::cout << std::ifstream("tmp.txt").rdbuf() << '\n'; //debug
	std::ifstream		stepfile(STEPFILE);
	if (stepfile.is_open())
	{
		int		tmpId;

		stepfile >> tmpId >> action;
		if (tmpId != id)
		{
			action = 0;
			std::cout << "failed to get action from: " << algoName << '\n';
		}
		std::remove(STEPFILE);
	}
	else
		std::cout << "failed to open STEPFILE for: " << algoName << '\n';
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

void			PlayerVec::decreaseHealth(int id)
{
	(*this)[id].decreaseHealth();
}

bool			Player::getDied()
{
	return (died);
}

void			Player::decreaseHealth()
{
	if (hp > 0)
		hp--;
	if ((hp == 0) && (isAlive == true))
		isAlive = false;
	died = true;
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
