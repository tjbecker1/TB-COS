#pragma once
#include "Driver.h"
#include <vector>


class Race
{
private:
	std::vector<Driver>mDrivers;

public:
	void Run(Driver& player);
};

