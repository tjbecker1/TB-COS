#include "Input.h"
#include <iostream>
#include <stdexcept>

int Input::GetNumber(const std::string& prompt, int minimum, int maximum)
{
    while (true)
    {
        std::cout << prompt;

        std::string input;

        if (!std::getline(std::cin, input))
        {
            return -1;
        }

        try
        {
            std::size_t charactersUsed = 0;
            const int number = std::stoi(input, &charactersUsed);

            if (charactersUsed != input.length())
            {
                std::cout << "Enter a whole number without extra characters.\n";
                continue;
            }

            if (number >= minimum && number <= maximum)
            {
                return number;
            }

            std::cout << "Enter a number from "
                << minimum << " to " << maximum << ".\n";
        }
        catch (const std::invalid_argument&)
        {
            std::cout << "Invalid input. Please enter a whole number.\n";
        }
        catch (const std::out_of_range&)
        {
            std::cout << "That number is too large or too small.\n";
        }
    }
}