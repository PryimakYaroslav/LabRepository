#pragma once
#include "Vehicle.h"

#include <string>

class Microbus final: public Vehicle{
    bool climateControl;
    bool hasAdjustableSeats;
    std::string interiorType;

    public:
    Microbus();
    Microbus(int id, std::string model, int countOfSeats, bool climateControl, bool hasAdjustableSeats, std::string interiorType);
    Microbus(int id, std::string model, int countOfSeats, std::string routStart, std::string destination, long run,
    bool climateControl, bool hasAdjustableSeats, std::string interiorType);
    virtual ~Microbus();

    void PrintVehicleInfo() const override;
    void IncreasRun() override;
    void SwapStops() override;

};