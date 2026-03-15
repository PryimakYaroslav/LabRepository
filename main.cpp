#include <iostream>
#include <string>
#include "Company.h"
#include "Driver.h"
#include "Vehicle.h"

using namespace std;

int main(){
    Company Company1("TourUa", 30, 35, 4.2);
    Company1.IncreasRating();
    Company1.UptadeTransport();
    Company1.PrintCompanyInfo();

    Company Company2("KyivDrive", 20, 25, 3.7);
    Company2.PrintCompanyInfo();

    Driver Driver1("Vadim", 45, 20, 5);
    Driver1.UpdateDriverData();
    Driver1.PrintDriverInfo();

    Vehicle Vehicle1(11, "minivan", "Citroen", "Kyiv", "Krakiv", 200000);
    Vehicle1.IncreasRun();
    Vehicle1.SwapStops();
    Vehicle1.PrintVehicleInfo();

    std::cout << Vehicle::GetLocation() << std::endl;
    std::cout << "Vehicle created: " << Vehicle::GetTotalVehicles() << std::endl;

    std::cout << Company::GetOfficeLocation() << std::endl;
    std::cout << Company::GetParentCorporation() << std::endl;

    return 0;
}