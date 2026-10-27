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
}

