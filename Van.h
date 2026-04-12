#pragma once
#include "Vehicle.h"

#include <string>

class Van : public Vehicle{
    double cargoCapacity;
    bool hasUSBports;
    bool hasConditioner;

    public:

    Van();
    Van(int id, std::string model, int countOfSeats, double cargoCapacity, bool hasUSBports, bool hasConditioner);
    Van(int id, std::string model, int countOfSeats, std::string routStart, std::string destination, long run,
    double cargoCapacity, bool hasUSBports, bool hasConditioner);
    ~Van();

    void PrintVehicleInfo() const;
};