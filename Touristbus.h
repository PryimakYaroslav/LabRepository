#pragma once
#include "Vehicle.h"

#include <string>

class Touristbus final: public Vehicle{
    int numberOfScreens;
    bool hasToilet;
    bool isDoubleDeckered;

    public:
    Touristbus();
    Touristbus(int id, std::string model, int countOfSeats, int numberOfScreens, bool hasToilets, bool isDoubleDeckered);
    Touristbus(int id, std::string model, int countOfSeats, std::string routStart, std::string destination, long run, 
    int numberOfScreens, bool hasToilets, bool isDoubleDeckered);
    ~Touristbus() override;

    Touristbus(const Touristbus& other);
    Touristbus(Touristbus&& other) noexcept;

    void PrintVehicleInfo() const override final;
    void IncreasRun() override final;
    void SwapStops() override final;

};