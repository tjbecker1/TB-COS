#include "Driver.h"

Driver::Driver(const std::string& name, const Car& car) : mName(name), mCar(car)
{

}

std::string Driver::GetName() const
{
	return mName;
}

const Car& Driver::GetCar() const
{
	return mCar;
}