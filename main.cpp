#include <iostream>
#include <string>
#include "Company.h"
#include "Driver.h"
#include "Vehicle.h"

using namespace std;

int main(){
    Company C1("TourUa", 30, 35, 3.7);
    C1.PrintCompanyInfo();

    Driver D1("Vadim", 45, 20, 5);
    D1.PrintDriverInfo();

    Vehicle V1(11, "minivan", "Citroen", "Kyiv", "Krakiv", 200000);
    V1.PrintVehicleInfo();
    return 0;
}