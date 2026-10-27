#include <iostream>
#include "Car.h"
#include <iomanip>

int main()
{

    Car testCar("Stock Car", 414);
    std::cout << std::fixed << std::setprecision(0);

    std::cout << "Car name:" << testCar.GetName()<<'\n';
    std::cout << "Car Number: #" << testCar.GetNumber() << '\n';
    std::cout << "Fuel:" << testCar.GetFuel() << "%\n";
    std::cout << "Tire Wear:" << testCar.GetTireCondtion() << "%\n";
}

