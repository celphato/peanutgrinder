#pragma once
#include "mda.hpp"
#include <vector>

typedef unsigned short us;

std::string join(std::vector<us> vint)
{
	std::string outstr;
	for (size_t i=0; i<vint.size(); i++)
	{
		outstr += std::to_string((us) vint[i]);
		outstr += (std::string) " ";
	}
	return outstr;
}

class gamestate // operational
{
	us player;
	bool& lastsubstring();
	mda::mda<bool> occuspace;
	std::vector<us> gamestring;
public:
	const us maxmove;
	const us length;
	us getplayer();
	std::string getstring();
	gamestate(us p_maxmove, us p_length);
	bool legal(us p_move); // check if p_move is a legal move
	std::vector<us> alllegal();
	void n_advance(us p_move); // advance with no legality check; faster but much less safe, very hard to debug illegal move
	bool advance(us p_move); // add p_move to the back of the game string
	void backtrack(); // go back a move
};

us gamestate::getplayer()
{
	return player;
}

std::string gamestate::getstring()
{
	return join(gamestring);
}

bool& gamestate::lastsubstring()
{
	const mda::mda<bool>* ph_ocs = &occuspace;
	for (us i=gamestring.size()-length; i<gamestring.size(); i++)
	{
		ph_ocs = &((*ph_ocs)[gamestring[i]]);
	}
	return (bool&) (*ph_ocs);
}

gamestate::gamestate(us p_maxmove, us p_length)
:maxmove(p_maxmove), length(p_length), player(1)
{
	std::vector<size_t> csrct_ocs;
	for (us i=0; i<length; i++)
	{
		csrct_ocs.push_back(maxmove);
	}
	occuspace = mda::mda<bool>(csrct_ocs);
}

bool gamestate::legal(us p_move)
{
	if (p_move < 0 or p_move >= maxmove)
	{
		return false;
	}
	else if (gamestring.size()>=length)
	{
		gamestring.push_back(p_move);
		bool valid = !lastsubstring();
		gamestring.pop_back();
		return valid;
	}
	else
	{
		return true;
	}
}

std::vector<us> gamestate::alllegal()
{
	std::vector<us> outvus;
	for (us i=0; i<maxmove; i++)
	{
		if (legal(i))
		{
			outvus.push_back(i);
		}
	}
	return outvus;
}

void gamestate::n_advance(us p_move)
{
	gamestring.push_back(p_move);
	if (gamestring.size() >= length)
	{
		lastsubstring() = true;
	}
	player = 3-player;
}

bool gamestate::advance(us p_move)
{
	bool islegal = legal(p_move);
	if (islegal)
	{
		n_advance(p_move);
	}
	return islegal;
}

void gamestate::backtrack()
{
	if (gamestring.size()>=length)
	{
		lastsubstring() = false;
	}
	gamestring.pop_back();
	player = 3-player;
}