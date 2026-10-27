#include <iostream>
#include "Car.h"
#include <iomanip>
#include "Driver.h"

int main()
{
    Car testCar("Stock Car", 414);
    Driver testDriver("Tyler Becker", testCar);

    std::cout << std::fixed << std::setprecision(0);

    std::cout << "Driver: " << testDriver.GetName() << '\n';
    std::cout << "Car name: " << testDriver.GetCar().GetName() << '\n';
    std::cout << "Car number: #" << testDriver.GetCar().GetNumber() << '\n';
    std::cout << "Fuel: " << testDriver.GetCar().GetFuel() << "%\n";
    std::cout << "Tire condition: "
        << testDriver.GetCar().GetTireCondition() << "%\n";

    testDriver.AddLapTime(32.5);
    testDriver.AddLapTime(31.8);

    // Show race times with two decimal places.
    std::cout << std::fixed << std::setprecision(2);

    std::cout << "Total race time: "
        << testDriver.GetTotalRaceTime()
        << " seconds\n";

    testDriver.ResetRaceTime();

    std::cout << "After reset: "
        << testDriver.GetTotalRaceTime()
        << " seconds\n";

    testDriver.AddLapTime(30.5);

    std::cout << "New race total: "
        << testDriver.GetTotalRaceTime()
        << " seconds\n";
}

