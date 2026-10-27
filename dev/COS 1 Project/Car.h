#pragma once
#include <string>

class Car
{
private:
	std::string mName = "Race Car";
	double mFuel = 100.0;
	double mTireCondition = 100.0;
	int mNumber = 0;

public:
	std::string GetName() const;
	double GetFuel() const;
	double GetTireCondition() const;
	int GetNumber() const;
	Car() = default;
	Car(const std::string& name, int number);
};

