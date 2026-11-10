#include "Race.h"
#include <iostream>
#include <iomanip>
#include <string>
#include <random>
#include <algorithm>
#include "Input.h"



bool CompareRaceTimes(const Driver& first, const Driver& second)
{
	return first.GetTotalRaceTime() < second.GetTotalRaceTime();
}

Driver* Race::FindDriverByNumber(int carNumber)
{
	for (Driver& driver : mDrivers)
	{
		if (driver.GetCar().GetNumber() == carNumber)
		{
			return &driver;
		}
	}
	return nullptr;
}

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
	constexpr double pitStopTime = 15.0;
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
			driver.GetCar().ConsumeFuel(8.0);
			driver.GetCar().WearTires(6.0);

			std::cout << driver.GetName()
				<< " - Time: " << std::fixed << std::setprecision(2)
				<< lapTime << " seconds"
				<< " - Fuel: " << std::setprecision(0)
				<< driver.GetCar().GetFuel() << "%"
				<< " - Tires: " << driver.GetCar().GetTireCondition() << "%\n"
				<< std::setprecision(2);
		}

		// All drivers have finished this lap.
		// Offer a pit stop when another lap remains.
		if (lap < totalLaps)
		{
			Driver* racingPlayer =
				FindDriverByNumber(player.GetCar().GetNumber());

			if (racingPlayer == nullptr)
			{
				std::cout << "Unable to find the player in this race.\n";
				return;
			}

			std::cout << "\n1. Continue racing\n";
			std::cout << "2. Pit stop - refuel and replace tires (+"
				<< pitStopTime << " seconds)\n";

			int pitChoice = Input::GetNumber("Choose an option: ", 1, 2);

			if (pitChoice == -1)
			{
				return;
			}

			if (pitChoice == 2)
			{
				racingPlayer->GetCar().ServiceCar();
				racingPlayer->AddLapTime(pitStopTime);

				std::cout << "Pit stop complete! Fuel: 100% - Tires: 100%\n";
			}
		}
	}

	std::stable_sort(mDrivers.begin(), mDrivers.end(), CompareRaceTimes);

	std::cout << "\n========== FINAL RESULTS ==========\n";

	int position = 1;

	for (const Driver& driver : mDrivers)
	{
		std::cout << position << ". "
			<< driver.GetName()
			<< " - #" << driver.GetCar().GetNumber()
			<< " - Total time: " << driver.GetTotalRaceTime()
			<< " seconds\n";

		++position;
	}
}
