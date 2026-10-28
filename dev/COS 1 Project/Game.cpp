#include "Game.h"
#include <iostream>
#include <string>

void Game::DisplayMenu() const
{
	std::cout << "================================\n";
	std::cout << "WELCOME TO CONSOLE STOCK CAR RACING\n";
	std::cout << "=================================\n";
	std::cout << "Select one of the following options!\n";
	std::cout << "1. Start Race\n";
	std::cout << "2. About\n";
	std::cout << "3. Exit\n";
}

void Game::Run()
{
	bool running = true;
	std::string choice;

	while (running)
	{
		DisplayMenu();

		if (!std::getline(std::cin, choice))
		{
			return;
		}

		switch (choice.size() == 1 ? choice[0] : '\0')
		{
		case '1':
			break;

		case '2':
			std::cout << "Console Stock Car Racing is a text based racing game.\n";
			std::cout << "Compete against AI drivers for the best Finish possible.\n";
			break;

		case '3':
			std::cout << "Thanks for playing!\n";
			running = false;
			break;

		default:
			std::cout << "Invalid Choice. Please select 1,2 or 3.\n";
			break;
		}
	}
}