#pragma once
#include<string>

class Track
{
private:
    std::string mName;
    int mMinimumLapHundredths;
    int mMaximumLapHundredths;
    double mFuelUsagePerLap;
    double mTireWearPerLap;

public:
    Track(
        const std::string& name,
        int minimumLapHundredths,
        int maximumLapHundredths,
        double fuelUsagePerLap,
        double tireWearPerLap);

    const std::string& GetName() const;
    int GetMinimumLapHundredths() const;
    int GetMaximumLapHundredths() const;
    double GetFuelUsagePerLap() const;
    double GetTireWearPerLap() const;
};

