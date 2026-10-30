#include "Game.h"
#include <iostream>
#include <string>
#include <sstream>

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
		{
			std::string driverName;
			std::string numberInput;
			int carNumber = 0;

			do
			{
				std::cout << "Enter your Driver's Name:";

				if (!std::getline(std::cin, driverName))
				{
					return;
				}

				if (driverName.find_first_not_of("\t") == std::string::npos)
				{
					std::cout << "Driver Name cannot be blank.\n";
				}
			} while (driverName.find_first_not_of("\t") == std::string::npos);

			while (true)
			{
				std::cout << "Please select your car number (1-99): ";

				if (!std::getline(std::cin, numberInput))
				{
					return;
				}

				std::istringstream input(numberInput);
				char extraCharacter;

				if ((input >> carNumber) &&
					!(input >> extraCharacter) &&
					carNumber >= 1 &&
					carNumber <= 99)
				{
					break;
				}

				std::cout << "Invalid Number. Enter a Number from 1 to 99.\n";
			}

			std::cout << "\nWelcome, " << driverName
				<< "! You will race as #" << carNumber << ".\n";

			break;
		}

		case '2':
			std::cout << "Console Stock Car Racing is a text based racing game.\n";
			std::cout << "Compete against AI drivers for the best Finish possible.\n";
			std::cout << "Press Enter to return to the Main Menu.\n";
			
			if (!std::getline(std::cin, choice))
			{
				return;
			}
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