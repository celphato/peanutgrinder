#include <iostream>
#include "gamestate.hpp"
#include "bruteforce.hpp"

int main()
{
	us moves = 0;
	while (moves < 2)
	{
		system("clear");
		std::cout << "size of set of possible moves (int): ";
		std::cin >> moves;
	}
	us length = 0;
	while (length < 1)
	{
		system("clear");
		std::cout << "length of substrings (int): ";
		std::cin >> length;
	}
	std::string trackcalls;
	while (true)
	{
		system("clear");
		std::cout << "would you like to track number of recursive function calls? (y/n) ";
		std::cin >> trackcalls;
		if (trackcalls == (std::string) "y")
		{
			showcalls = true;
			break;
		}
		else if (trackcalls == (std::string) "n")
		{
			showcalls = false;
			break;
		}
	}
	gamestate gs0(moves, length);
	std::string userstartstr;
	us userno;
	while (true)
	{
		system("clear");
		std::cout << "would you like to start first? (y/n) ";
		std::cin >> userstartstr;
		if (userstartstr == (std::string) "y")
		{
			userno = 1;
			break;
		}
		else if (userstartstr == (std::string) "n")
		{
			userno = 2;
			gs0.advance(0);
			break;
		}
	}
	bool gamerunning = true;
	us move = gs0.maxmove;
	system("clear");
	while (gamerunning)
	{
		std::cout << "current string: " << gs0.getstring() << std::endl;
		std::cout << "available moves: " << join(gs0.alllegal()) << std::endl;
		std::cout << "your move: ";
		std::cin >> move;
		while (!gs0.legal(move))
		{
			system("clear");
			std::cout << "illegal move" << std::endl;
			std::cout << gs0.getstring() << std::endl;
			std::cout << join(gs0.alllegal()) << std::endl;
			std::cout << "your move: ";
			std::cin >> move;
		}
		gs0.advance(move);
		system("clear");
		if (gs0.alllegal().size()!=0)
		{
			move = bruteforce(gs0);
			gs0.advance(move);
		}
		gamerunning = gs0.alllegal().size()!=0;
	}
	system("clear");
	std::cout << gs0.getstring() << std::endl;
	std::cout << "player " << 3-gs0.getplayer() << ((userno==gs0.getplayer())?" (computer)":" (human)") << " wins" << std::endl;
}