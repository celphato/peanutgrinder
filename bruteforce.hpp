#pragma once
#include <iostream>
#include "gamestate.hpp"

bool winning(gamestate& gs)
{
	for (us i=0; i<gs.maxmove; i++)
	{
		if (gs.advance(i))
		{
			if (!winning(gs))
			{
				gs.backtrack();
				return true;
			}
			gs.backtrack();
		}
	}
	return false;
}

us bruteforce(gamestate gs)
{
	for (us i=0; i<gs.maxmove; i++)
	{
		if (gs.advance(i))
		{
			if (!winning(gs))
			{
				gs.backtrack();
				return i;
			}
			gs.backtrack();
		}
	}
	std::cout << ":(" << std::endl;
	return gs.alllegal()[0];
}