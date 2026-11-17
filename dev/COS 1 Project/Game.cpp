#include "Game.h"
#include <iostream>
#include <string>
#include <sstream>
#include "Car.h"
#include "Driver.h"
#include "Race.h"
#include "Input.h"
#include "Track.h"
#include <vector>


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
    constexpr int minimumLaps = 5;
    constexpr int maximumLaps = 10;
    constexpr int minimumOpponents = 1;
    constexpr int maximumOpponents = 25;

    const std::vector<Track> tracks =
    {
        Track("Short Track", 1800, 2300, 6.0, 9.0),
        Track("Speedway", 3000, 3500, 8.0, 6.0),
        Track("Superspeedway", 4500, 5000, 9.0, 4.0)
    };

    bool running = true;

    while (running)
    {
        DisplayMenu();

        const int menuChoice = Input::GetNumber(
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

            const int carNumber = Input::GetNumber(
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

            const int totalLaps = Input::GetNumber(
                "Choose the race length (5-10 laps): ",
                minimumLaps,
                maximumLaps);

            if (totalLaps == -1)
            {
                return;
            }

            const int opponentCount = Input::GetNumber(
                "Choose the number of AI opponents (1-25): ",
                minimumOpponents,
                maximumOpponents);

            if (opponentCount == -1)
            {
                return;
            }

            std::cout << "\n========== TRACK SELECTION ==========\n";

            for (int index = 0;
                index < static_cast<int>(tracks.size());
                ++index)
            {
                const Track& track = tracks[index];

                std::cout << index + 1 << ". " << track.GetName()
                    << " - Fuel per lap: "
                    << track.GetFuelUsagePerLap() << "%"
                    << " - Tire wear per lap: "
                    << track.GetTireWearPerLap() << "%\n";
            }

            const int trackChoice = Input::GetNumber(
                "Select a track: ",
                1,
                static_cast<int>(tracks.size()));

            if (trackChoice == -1)
            {
                return;
            }

            const Track& selectedTrack = tracks.at(trackChoice - 1);

            Race race;
            race.Run(
                playerDriver,
                totalLaps,
                opponentCount,
                selectedTrack);

            break;
        }

        case 2:
        {
            std::cout << "\nConsole Stock Car Racing is a text based racing game.\n";
            std::cout << "Compete against AI drivers for the best finish possible.\n";
            std::cout << "Choose your track, race length, and opponent count.\n";
            std::cout << "Manage tire wear and decide when to make pit stops.\n";
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