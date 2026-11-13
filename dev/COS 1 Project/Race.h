#pragma once
#include "Driver.h"
#include <vector>


class Race
{
private:
	std::vector<Driver>mDrivers;
	Driver* FindDriverByNumber(int carNumber);
	void DisplayResults();
	void PerformPitStop(Driver& driver, double pitStopTime);
	void DisplayStandings() const;
	void DisplayStartingLineup() const;
	double CalculateLapTime(const Driver& driver, double baseLapTime)const;
	void DisplayLapResult(const Driver& driver, double lapTime) const;

public:
	void Run(Driver& player, int totalLaps);
	
};

