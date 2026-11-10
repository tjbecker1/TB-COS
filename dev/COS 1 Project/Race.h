#pragma once
#include "Driver.h"
#include <vector>


class Race
{
private:
	std::vector<Driver>mDrivers;
	Driver* FindDriverByNumber(int carNumber);
	void DisplayResults();

public:
	void Run(Driver& player);
};

