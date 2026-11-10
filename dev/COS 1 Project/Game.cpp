#include "Game.h"
#include <iostream>
#include <string>
#include <sstream>
#include "Car.h"
#include "Driver.h"
#include "Race.h"
#include "Input.h"


void Game::DisplayMenu() const
{
    std::cout << "\n=================================\n";
    std::cout << "WELCOME TO CONSOLE STOCK CAR RACING\n";
    std::cout << "=================================\n";
    std::cout << "Select one of the following options!\n";
    std::cout << "1. Start Race\n";
    std::cout << "2. About\n";
    std::cout << "3. Exit\n";
}

void Game::Run()
{
    constexpr int minimumMenuChoice = 1;
    constexpr int maximumMenuChoice = 3;
    constexpr int minimumCarNumber = 1;
    constexpr int maximumCarNumber = 99;

    bool running = true;

    while (running)
    {
        DisplayMenu();

        int menuChoice = Input::GetNumber(
            "Select an option (1-3): ",
            minimumMenuChoice,
            maximumMenuChoice);

        if (menuChoice == -1)
        {
            return;
        }

        switch (menuChoice)
        {
        case 1:
        {
            std::string driverName;

            do
            {
                std::cout << "\nEnter your Driver's Name: ";

                if (!std::getline(std::cin, driverName))
                {
                    return;
                }

                if (driverName.find_first_not_of(" \t\r")
                    == std::string::npos)
                {
                    std::cout << "Driver Name cannot be blank.\n";
                }

            } while (driverName.find_first_not_of(" \t\r")
                == std::string::npos);

            int carNumber = Input::GetNumber(
                "Please select your car number (1-99): ",
                minimumCarNumber,
                maximumCarNumber);

            if (carNumber == -1)
            {
                return;
            }

            Car playerCar("Stock Car", carNumber);
            Driver playerDriver(driverName, playerCar);

            std::cout << "\nWelcome, " << driverName
                << "! You will race as #" << carNumber << ".\n";

            Race race;
            race.Run(playerDriver);

            break;
        }

        case 2:
        {
            std::cout << "\nConsole Stock Car Racing is a text based racing game.\n";
            std::cout << "Compete against AI drivers for the best Finish possible.\n";
            std::cout << "Press Enter to return to the Main Menu.\n";

            std::string pauseInput;

            if (!std::getline(std::cin, pauseInput))
            {
                return;
            }

            break;
        }

        case 3:
            std::cout << "\nThanks for playing!\n";
            running = false;
            break;
        }
    }
}