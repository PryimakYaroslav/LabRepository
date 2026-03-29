#include <iostream>
#include <string>
#include <utility>
#include "Company.h"
#include "Driver.h"
#include "Vehicle.h"
#include "Van.h"
#include "Microbus.h"
#include "Touristbus.h"

using namespace std;

int main(){

    Vehicle Vehicle1(11, "minivan", 7, "Kyiv", "Krakiv", 200000);
    Vehicle1.IncreasRun();
    Vehicle1.SwapStops();
    Vehicle1.PrintVehicleInfo();

    Van vanFull(1, "Van", 15, "Chernivtsi", "Kyiv", 30000, 2.5, true, true);

    Microbus microFull(2, "Microbus", 22, "Kyiv", "Lviv", 12500, true, true, "Lux");

    Touristbus touristFull(3, "Touristbus", 50, "Dnipro", "Sofia", 100000, 4, true, false);

    Touristbus Touristbus = touristFull;
    
    std::cout << "Vehicle created (with copies): " << Vehicle::GetTotalVehicles() << std::endl;

    return 0;
}