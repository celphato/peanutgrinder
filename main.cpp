#include <iostream>
#include "gamestate.hpp"
#include "bruteforce.hpp"

int main()
{
	us moves = 0;
	while (moves < 2)
	{
		system("cls");
		std::cout << "set of possible moves size: ";
		std::cin >> moves;
	}
	us length = 0;
	while (length < 1)
	{
		system("cls");
		std::cout << "length of substrings: ";
		std::cin >> length;
	}
	gamestate gs0(moves, length);
	std::string userstartstr;
	us userno;
	while (true)
	{
		system("cls");
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
	system("cls");
	while (gamerunning)
	{
		std::cout << gs0.getstring() << std::endl;
		std::cout << join(gs0.alllegal()) << std::endl;
		std::cin >> move;
		while (!gs0.legal(move))
		{
			system("cls");
			std::cout << "Illegal move" << std::endl;
			std::cout << gs0.getstring() << std::endl;
			std::cout << join(gs0.alllegal()) << std::endl;
			std::cin >> move;
		}
		gs0.advance(move);
		system("cls");
		if (gs0.alllegal().size()!=0)
		{
			move = bruteforce(gs0);
			gs0.advance(move);
		}
		gamerunning = gs0.alllegal().size()!=0;
	}
	system("cls");
	std::cout << gs0.getstring() << std::endl;
	std::cout << "player " << 3-gs0.getplayer() << ((userno==gs0.getplayer())?" (computer)":" (human)") << " wins" << std::endl;
}