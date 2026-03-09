#include "Company.h"
#include <iostream>
#include <string>

Company::Company() : Company ("Unknown", 0, 0, 0) {}

Company::Company(std::string CName) : Company (CName, 0, 0, 0) {}

Company::Company(std::string CName, int VCount, int DCount, double Rating) :
     CompanyName(CName),
      VehicleCount(VCount),
      DriverCount(DCount)
{
    SetRating(Rating);
}

Company::~Company() {
        std::cout << "Info about company " << CompanyName << " destroyed" << std::endl;
}

void Company::PrintCompanyInfo(){
        std::cout << "===================================" << std::endl;
        std::cout << "Company Name: " << CompanyName << std::endl;
        std::cout << "Vehicle Count: " << VehicleCount << " vehicles"<<std::endl;
        std::cout << "Driver Count: " << DriverCount << " workers" << std::endl;
        std::cout << "CompanyRating: " << CompanyRating << std::endl;
        std::cout << "===================================" << std::endl;
    }

void Company::SetRating(double Rating){
    if (Rating >= 5) 
    CompanyRating = 4.3;
    else if (Rating < 0)
    CompanyRating = 2.5;
    else
    CompanyRating = Rating;
}

void Company::IncreasRating(){
    SetRating(CompanyRating +0.5);
}

void Company::UptadeTransport(){
    DriverCount = DriverCount + 7;
    VehicleCount = VehicleCount - 4;

    if (VehicleCount < 0)
    VehicleCount = 0;
}