#pragma once
#include "Vehicle.h"

#include <string>

class Van : public Vehicle{
    double cargoCapacity;
    bool hasUSBports;
    bool hasConditioner;
};