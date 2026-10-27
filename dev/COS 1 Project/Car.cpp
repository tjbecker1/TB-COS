#include "Car.h"

std::string Car::GetName() const
{
	return mName;
}

double Car::GetFuel() const
{
	return mFuel;
}

double Car::GetTireCondtion() const
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