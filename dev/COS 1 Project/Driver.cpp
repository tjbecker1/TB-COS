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

double Driver::GetTotalRaceTime() const
{
	return mTotalRaceTime;
}

void Driver::AddLapTime(double lapTime)
{
	if (lapTime > 0.0)
	{
		mTotalRaceTime += lapTime;
	}
}