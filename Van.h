#pragma once
#include "Vehicle.h"

#include <string>

class Van final: public Vehicle{
    double cargoCapacity;
    bool hasUSBports;
    bool hasConditioner;

    public:

    Van();
    Van(int id, std::string model, int countOfSeats, double cargoCapacity, bool hasUSBports, bool hasConditioner);
    Van(int id, std::string model, int countOfSeats, std::string routStart, std::string destination, long run,
    double cargoCapacity, bool hasUSBports, bool hasConditioner);
    virtual ~Van();

    void PrintVehicleInfo() const;
};