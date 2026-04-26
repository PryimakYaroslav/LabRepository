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

Microbus Microbus1(2, "Microbus", 20, "Kyiv", "Lviv", 35000, true, true, "Classic");
Vehicle& vRef = Microbus1;
vRef.PrintVehicleInfo();

Van Van1(4, "Van", 7, "Hotun", "Kozyatun", 25000, 4, false, true);
Van* ptr1 = &Van1;
ptr1->PrintVehicleInfo();

return 0;
}