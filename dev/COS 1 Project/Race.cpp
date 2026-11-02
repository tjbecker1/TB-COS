#include "Race.h"
#include <iostream>
#include <iomanip>

void Race::Run(Driver& player)
{
	player.ResetRaceTime();

	const int totalLaps = 5;
	const double lapTime = 32.5;

	std::cout << "Race Starting!\n";
	std::cout << std::fixed << std::setprecision(2);

	for (int lap = 1; lap <= totalLaps;++lap)
	{
		player.AddLapTime(lapTime);

		std::cout << "Lap " << lap << "/" << totalLaps<< " - Time:" << lapTime << " seconds\n";
	}
	
	std::cout << "Race Finished\n";
	std::cout << "Driver: " << player.GetName() << '\n';
	std::cout << "Total Time: " << player.GetTotalRaceTime() << "seconds\n";
}
