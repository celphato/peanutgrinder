#pragma once
#include <iostream>
#include "gamestate.hpp"

bool showcalls;
unsigned long long counter;

bool winning(gamestate& gs)
{
	counter++;
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
	counter = 1;
	for (us i=0; i<gs.maxmove; i++)
	{
		if (gs.advance(i))
		{
			if (!winning(gs))
			{
				gs.backtrack();
				std::cout << counter << std::endl;
				return i;
			}
			gs.backtrack();
		}
	}
	if (showcalls)
	{
		std::cout << "recursive function calls: " << counter << std::endl;
	}
	std::cout << ":(" << std::endl;
	return gs.alllegal()[0];
}