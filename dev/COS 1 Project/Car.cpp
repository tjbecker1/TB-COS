#include "Car.h"

std::string Car::GetName() const
{
	return mName;
}

double Car::GetFuel() const
{
	return mFuel;
}

double Car::GetTireCondition() const
{
	return mTireCondition;
}

int Car::GetNumber() const
{
	return mNumber;
}

Car::Car(const std::string& name, int number): mName(name), mNumber(number)
{

}

void Car::ConsumeFuel(double amount)
{
	if (amount > 0.0)
	{
		mFuel -= amount;

		if (mFuel < 0.0)
		{
			mFuel = 0.0;
		}
	}
}