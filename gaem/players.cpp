#include "players.h"

PlayerDict::PlayerDict(std::string algofolder)
{
    for(auto& p: fs::directory_iterator(algofolder))
	{
		std::cout << p << '\n';
	}
    //fs::remove_all();
}
