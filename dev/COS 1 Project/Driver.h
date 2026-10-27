#pragma once
#include <string>
#include "Car.h"

class Driver
{
private:
	std::string mName;
	Car mCar;

public:
	Driver(const std::string& name, const Car& car);
	std::string GetName() const;
	const Car& GetCar() const;
};

