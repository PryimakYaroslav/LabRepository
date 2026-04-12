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

Touristbus Touristbus1(1, "Touristbus", 50, "Kyiv", "Berlin", 47500, 3, true, false);
Vehicle* ptr = &Touristbus1;

ptr->PrintVehicleInfo();
ptr->IncreasRun();
ptr->SwapStops();

    return 0;
}