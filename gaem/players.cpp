#include "rules.h"
#include "players.h"

Player::Player(std::string aName, int iid, int hhp)
{
	algoName = aName;
	id = iid;
	hp = hhp;
	isAlive = true;
	std::cout << "newPlayer! id: " << id << " name: " << algoName << " hp: " << hp <<'\n';
}

PlayerVec::PlayerVec(std::string algoFolder)
{
	int				id = 0;

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
