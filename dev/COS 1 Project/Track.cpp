#include "Track.h"

Track::Track(
    const std::string& name,int minimumLapHundredths,int maximumLapHundredths,double fuelUsagePerLap,double tireWearPerLap): mName(name),mMinimumLapHundredths(minimumLapHundredths),mMaximumLapHundredths(maximumLapHundredths),mFuelUsagePerLap(fuelUsagePerLap),mTireWearPerLap(tireWearPerLap)
{
}

const std::string& Track::GetName() const
{
    return mName;
}

int Track::GetMinimumLapHundredths() const
{
    return mMinimumLapHundredths;
}

int Track::GetMaximumLapHundredths() const
{
    return mMaximumLapHundredths;
}

double Track::GetFuelUsagePerLap() const
{
    return mFuelUsagePerLap;
}

double Track::GetTireWearPerLap() const
{
    return mTireWearPerLap;
}