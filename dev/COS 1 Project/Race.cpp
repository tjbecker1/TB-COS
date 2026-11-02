#include "Race.h"
#include <iostream>
#include <iomanip>
#include <string>


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
	const double lapTime = 32.5;

	std::cout << "Race Starting!\n";
	std::cout << std::fixed << std::setprecision(2);

	for (int lap = 1; lap <= totalLaps; ++lap)
	{
		std::cout << "\nLap " << lap << "/" << totalLaps << '\n';

		for (Driver& driver : mDrivers)
		{
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
