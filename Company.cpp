#include "Company.h"
#include <iostream>
#include <string>

void Company::PrintCompanyInfo(){
        std::cout << "===================================" << std::endl;
        std::cout << "Company Name: " << CompanyName << std::endl;
        std::cout << "Vehicle Count: " << VehicleCount << " vehicles"<<std::endl;
        std::cout << "Driver Count: " << DriverCount << " workers" << std::endl;
        std::cout << "CompanyRating: " << CompanyRating << std::endl;
        std::cout << "===================================" << std::endl;
    }

Company::Company(std::string CName, int VCount, int DCount, double Rating) {
    CompanyName = CName;
    VehicleCount = VCount;
    DriverCount = DCount;
    CompanyRating = Rating;
}