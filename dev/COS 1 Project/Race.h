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

public:
	void Run(Driver& player);
};

