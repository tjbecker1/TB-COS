#include <iostream>
#include "Car.h"
#include <iomanip>
#include "Driver.h"

int main()
{

    Car testCar("Stock Car", 414);
    Driver testDriver("Tyler Becker", testCar);
    std::cout << "Driver: " << testDriver.GetName() << '\n';
    std::cout << std::fixed << std::setprecision(0);

    std::cout << "Car name:" << testCar.GetName()<<'\n';
    std::cout << "Car Number: #" << testCar.GetNumber() << '\n';
    std::cout << "Fuel:" << testCar.GetFuel() << "%\n";
    std::cout << "Tire Wear:" << testCar.GetTireCondtion() << "%\n";
}

