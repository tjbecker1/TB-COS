#include "Race.h"
#include "Car.h"
#include "Driver.h"
#include "Input.h"
#include <algorithm>
#include <iomanip>
#include <iostream>
#include <random>
#include <string>
#include <map>



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

void Race::DisplayResults()
{
    std::stable_sort(
        mDrivers.begin(),
        mDrivers.end(),
        CompareRaceTimes);

    std::cout << "\n========== FINAL RESULTS ==========\n";
    std::cout << std::fixed << std::setprecision(2);

    int position = 1;

    for (const Driver& driver : mDrivers)
    {
        std::cout << position << ". "
            << driver.GetName()
            << " - #" << driver.GetCar().GetNumber()
            << " - Total time: "
            << driver.GetTotalRaceTime()
            << " seconds\n";

        ++position;
    }
}

void Race::PerformPitStop(Driver& driver, double pitStopTime)
{
    driver.GetCar().ServiceCar();
    driver.AddLapTime(pitStopTime);
}

void Race::DisplayStartingLineup() const
{
    std::cout << "\n========== STARTING LINEUP ==========\n";

    for (const Driver& driver : mDrivers)
    {
        std::cout << driver.GetName()
            << " - #" << driver.GetCar().GetNumber()
            << '\n';
    }
}

void Race::DisplayStandings() const
{
    if (mDrivers.empty())
    {
        return;
    }

    std::vector<Driver> standings = mDrivers;

    std::stable_sort(
        standings.begin(),
        standings.end(),
        CompareRaceTimes);

    const double leaderTime = standings.front().GetTotalRaceTime();

    std::cout << "\n========== CURRENT STANDINGS ==========\n";
    std::cout << std::fixed << std::setprecision(2);

    int position = 1;

    for (const Driver& driver : standings)
    {
        const double totalTime = driver.GetTotalRaceTime();
        const double gapToLeader = totalTime - leaderTime;

        std::cout << position << ". "
            << driver.GetName()
            << " - #" << driver.GetCar().GetNumber()
            << " - Total: " << totalTime << " seconds";

        if (position == 1)
        {
            std::cout << " - Leader";
        }
        else
        {
            std::cout << " - Gap: +" << gapToLeader << " seconds";
        }

        std::cout << '\n';
        ++position;
    }
}

double Race::CalculateLapTime(const Driver& driver, double baseLapTime)const
{
    constexpr double maximumTireCondition = 100.0;
    constexpr double tirePenaltyPerPercent = 0.10;

    const double tirewear = maximumTireCondition - driver.GetCar().GetTireCondition();
    const double tirePenalty = tirewear * tirePenaltyPerPercent;

    return baseLapTime + tirePenalty;
}

void Race::DisplayLapResult(const Driver& driver,double lapTime) const
{
    std::cout << std::fixed << std::setprecision(2)
        << driver.GetName()
        << " - Time: " << lapTime << " seconds"
        << " - Fuel: " << std::setprecision(0)
        << driver.GetCar().GetFuel() << "%"
        << " - Tires: "
        << driver.GetCar().GetTireCondition() << "%\n"
        << std::setprecision(2);
}

void Race::Run(Driver& player, int totalLaps)
{
    constexpr int opponentCount = 3;
    constexpr int minimumLapHundredths = 3000;
    constexpr int maximumLapHundredths = 3500;
    constexpr double hundredthsPerSecond = 100.0;
    constexpr double fuelUsagePerLap = 8.0;
    constexpr double tireWearPerLap = 6.0;
    constexpr double pitStopTime = 15.0;
    constexpr int continueRacingChoice = 1;
    constexpr int pitStopChoice = 2;

    player.ResetRaceTime();

    mDrivers.clear();
    mDrivers.push_back(player);

    const int playerCarNumber = player.GetCar().GetNumber();

    std::random_device seed;
    std::mt19937 generator(seed());
    std::vector<std::string> aiNames =
    {
    "Cole Mercer",
    "Jake Whitmore",
    "Ethan Prescott",
    "Mason Brooks",
    "Dylan Cross",
    "Caleb Lawson",
    "Ryan Steele",
    "Logan West",
    "Blake Turner",
    "Hunter Callahan",
    "Austin Reed",
    "Cody Barrett",
    "Jesse Maddox",
    "Travis Knox",
    "Wyatt Stone",
    "Garrett Shaw",
    "Connor Mitchell",
    "Brent Walker",
    "Tyler Hayes",
    "Chase Dalton",
    "Nate Holloway",
    "Luke Ramsey",
    "Dustin Cole",
    "Owen Briggs",
    "Zack Winslow"
    };

    std::shuffle(aiNames.begin(), aiNames.end(), generator);

    constexpr int earliestPitLap = 2;
    const int latestPitLap = totalLaps - 1;

    std::uniform_int_distribution<int> pitLapDistribution(
        earliestPitLap, latestPitLap);

    std::map<int, int> aiPitLaps;
    constexpr int minimumCarNumber = 1;
    constexpr int maximumCarNumber = 99;

    std::uniform_int_distribution<int> carNumbers(
        minimumCarNumber,
        maximumCarNumber);

    for (int opponent = 0; opponent < opponentCount; ++opponent)
    {
        int aiNumber = 0;

        do
        {
            aiNumber = carNumbers(generator);
        } while (FindDriverByNumber(aiNumber) != nullptr);

        Car aiCar("Stock Car", aiNumber);
        Driver aiDriver(aiNames[opponent], aiCar);

        mDrivers.push_back(aiDriver);

        aiPitLaps[aiNumber] = pitLapDistribution(generator);

    }

    DisplayStartingLineup();

    std::uniform_int_distribution<int> lapHundredths(minimumLapHundredths,maximumLapHundredths);

    std::cout << "\nThe Green Flag Waves... And The Race has begun!\n";
    std::cout << std::fixed << std::setprecision(2);

    for (int lap = 1; lap <= totalLaps; ++lap)
    {
        std::cout << "\nLap " << lap << "/" << totalLaps << '\n';

        double playerLapTime = 0.0;

        for (Driver& driver : mDrivers)
        {
            const double baseLapTime = lapHundredths(generator) / hundredthsPerSecond;

            const double lapTime = CalculateLapTime(driver, baseLapTime);

            driver.AddLapTime(lapTime);
            driver.GetCar().ConsumeFuel(fuelUsagePerLap);
            driver.GetCar().WearTires(tireWearPerLap);

            if (driver.GetCar().GetNumber() == playerCarNumber)
            {
                playerLapTime = lapTime;
            }

            DisplayLapResult(driver, lapTime);

            const int driverCarNumber = driver.GetCar().GetNumber();

            if (driverCarNumber != playerCarNumber &&
                lap == aiPitLaps.at(driverCarNumber))
            {
                PerformPitStop(driver, pitStopTime);

                std::cout << "  " << driver.GetName()
                    << " makes a pit stop! +"
                    << std::fixed << std::setprecision(2)
                    << pitStopTime << " seconds"
                    << " - Fuel: 100% - Tires: 100%\n";
            }
        }

        if (lap < totalLaps)
        {
            Driver* racingPlayer = FindDriverByNumber(playerCarNumber);

            if (racingPlayer == nullptr)
            {
                std::cout << "Unable to find the player in this race.\n";
                return;
            }

            std::cout << "\n" << continueRacingChoice
                << ". Continue racing\n";
            std::cout << pitStopChoice
                << ". Pit stop - refuel and replace tires (+"
                << pitStopTime << " seconds)\n";

            int pitChoice = Input::GetNumber(
                "Choose an option: ",
                continueRacingChoice,
                pitStopChoice);

            if (pitChoice == -1)
            {
                return;
            }

            if (pitChoice == pitStopChoice)
            {
                PerformPitStop(*racingPlayer, pitStopTime);

                std::cout << std::fixed << std::setprecision(2);
                std::cout << "\nLap " << lap << " summary\n";
                std::cout << "Driving time: "
                    << playerLapTime << " seconds\n";
                std::cout << "Pit stop: +"
                    << pitStopTime << " seconds\n";
                std::cout << "Lap time including pit stop: "
                    << playerLapTime + pitStopTime
                    << " seconds\n";
                std::cout << "Total race time so far: "
                    << racingPlayer->GetTotalRaceTime()
                    << " seconds\n";
                std::cout << "Fuel: 100% - Tires: 100%\n";
            }

            DisplayStandings();
        }
    } 

    DisplayResults();

    std::cout << "Press Enter to return to the Main Menu...\n";

    std::string pauseInput;

    if (!std::getline(std::cin, pauseInput))
    {
        return;
    }
} 
