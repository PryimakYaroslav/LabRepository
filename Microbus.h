#pragma once
#include "Vehicle.h"

#include <string>

class Microbus : public Vehicle{
    bool climateControl;
    bool isStandingAllowed;
    std::string interiorType;
};