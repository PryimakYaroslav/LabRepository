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

Van myVan(5, "Ford Transit", 7, "Kyiv", "Hotun", 45000, 2.8, true, true);
Vehicle* ptr = &myVan;

ptr->PrintVehicleInfo();

    return 0;
}