#pragma once
#include "Vehicle.h"

#include <string>

class Touristbus : public Vehicle{
    int numberOfScreens;
    bool hasToilet;
    bool isDoubleDeckered;

    public:
    Touristbus();
    Touristbus(int id, std::string model, int countOfSeats, int numberOfScreens, bool hasToilets, bool isDoubleDeckered);
    Touristbus(int id, std::string model, int countOfSeats, std::string routStart, std::string destination, long run, 
    int numberOfScreens, bool hasToilets, bool isDoubleDeckered);
    ~Touristbus();

    Touristbus(const Touristbus& other);
};