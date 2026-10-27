#pragma once
#include <string>
#include "Car.h"

class Driver
{
private:
	std::string mName;
	Car mCar;
	double mTotalRaceTime = 0.0;

public:
	Driver(const std::string& name, const Car& car);
	std::string GetName() const;
	const Car& GetCar() const;
	double GetTotalRaceTime() const;
		void AddLapTime(double lapTime);
};

