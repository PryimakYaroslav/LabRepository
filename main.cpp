#include <iostream>
#include <string>
#include "Company.h"
#include "Driver.h"
#include "Vehicle.h"

using namespace std;

int main(){
    Company C1("TourUa", 30, 35, 4.2);
    C1.IncreasRating();
    C1.UptadeTransport();
    C1.PrintCompanyInfo();

    Driver D1("Vadim", 45, 20, 5);
    D1.UpdateDriverData();
    D1.PrintDriverInfo();

    Vehicle V1(11, "minivan", "Citroen", "Kyiv", "Krakiv", 200000);
    V1.IncreasRun();
    V1.SwapStops();
    V1.PrintVehicleInfo();

    return 0;
}