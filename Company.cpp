#include "Company.h"
#include <iostream>
#include <string>

std::string Company::OfficeLocation = "Kyiv";
std::string Company::ParentCorporation = "Global Transport Group";

Company::Company() : Company ("Unknown", 0, 0, 0) {}

Company::Company(std::string CName) : Company (CName, 0, 0, 0) {}

Company::Company(std::string CName, int VCount, int DCount, double Rating) :
    CompanyName(CName),
    VehicleCount(VCount),
    DriverCount(DCount),
    CompanyRating(Rating) {}

Company::~Company() {
        std::cout << "Info about company " << CompanyName << " destroyed" << std::endl;
}

std::ostream& operator<<(std::ostream& os, const Company& c) {
    os << "===================================" << std::endl;
    os << "Company Name: " << c.CompanyName << std::endl;
    os << "Vehicle Count: " << c.VehicleCount << " vehicles" << std::endl;
    os << "Driver Count: " << c.DriverCount << " workers" << std::endl;
    os << "Rating: " << c.CompanyRating << std::endl;
    os << "===================================";
    
    return os; 
}

std::istream& operator>>(std::istream& is, Company& c) {
    std::cout << "Enter Company Name: "; is >> c.CompanyName;
    std::cout << "Enter Vehicle Count: "; is >> c.VehicleCount;
    std::cout << "Enter Driver Count: "; is >> c.DriverCount;
    std::cout << "Enter Rating: "; is >> c.CompanyRating;
    
    return is;
}

void Company::PrintCompanyInfo(){
    std::cout << *this << std::endl;
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
    CompanyRating = CompanyRating + 0.5;
}

void Company::UptadeTransport(){
    this -> DriverCount += 7;
    this -> VehicleCount -= 4;

    if (this -> VehicleCount < 0)
    this -> VehicleCount = 0;
}

std::string Company::GetOfficeLocation(){
    return "All companys are located in " + OfficeLocation + " city";
}

std::string Company::GetParentCorporation(){
    return "Parent corporation for all companies is " + ParentCorporation;
}