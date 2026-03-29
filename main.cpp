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

    Vehicle Vehicle1(4, "Mercedes", 60, "Hotun", "Sataniv", 250000);

    Driver Driver1("Vadim", 43, 17, 2, Vehicle1);
    
    Driver1.PrintDriverInfo();
    
    std::cout << "Vehicle created (with copies): " << Vehicle::GetTotalVehicles() << std::endl;

    return 0;
}