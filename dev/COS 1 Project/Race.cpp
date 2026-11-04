#include "Race.h"
#include <iostream>
#include <iomanip>
#include <string>
#include <random>


void Race::Run(Driver& player)
{
	player.ResetRaceTime();

	mDrivers.clear();
	mDrivers.push_back(player);

	int aiNumber = 1;

	for (int oppenent = 1; oppenent <= 3; ++oppenent)
	{
		//Keep the player's number unique
		if (aiNumber == player.GetCar().GetNumber())
		{
			++aiNumber;
		}

		Car aiCar("Stock Car", aiNumber);
		Driver aiDriver("AI Driver " + std::to_string(oppenent), aiCar);

		mDrivers.push_back(aiDriver);
		++aiNumber;
	}

	std::cout << "Starting Lineup:\n";

	for (const Driver& driver : mDrivers)
	{
		std::cout << driver.GetName() << "- #" << driver.GetCar().GetNumber() << '\n';
	}

	const int totalLaps = 5;
	std::random_device seed;
	std::mt19937 generator(seed());
	std::uniform_int_distribution<int> lapHundreths(3000, 3500);

	std::cout << "Race Starting!\n";
	std::cout << std::fixed << std::setprecision(2);

	for (int lap = 1; lap <= totalLaps; ++lap)
	{
		std::cout << "\nLap " << lap << "/" << totalLaps << '\n';

		for (Driver& driver : mDrivers)
		{
			const double lapTime = lapHundreths(generator) / 100.0;
			driver.AddLapTime(lapTime);

			std::cout << driver.GetName()
				<< " - Time: " << lapTime << " seconds\n";
		}
	}

	std::cout << "\nRace finished!\n";

	for (const Driver& driver : mDrivers)
	{
		std::cout << driver.GetName()
			<< " - #" << driver.GetCar().GetNumber()
			<< " - Total time: " << driver.GetTotalRaceTime()
			<< " seconds\n";
	}
}
