#pragma once

#include <string>
#include <iostream>

class Company{

    std::string CompanyName;
    int VehicleCount;
    int DriverCount;
    double CompanyRating;

    static std::string OfficeLocation;
    static std::string ParentCorporation;

    public:

    Company();
    Company(std::string CName);
    Company(std::string CName, int VCount, int DCount, double Rating);
    ~Company();

    friend std::ostream& operator<<(std::ostream& os, const Company& c);
    friend std::istream& operator>>(std::istream& is, Company& c);
    
    void PrintCompanyInfo();
    void SetRating(double Rating);
    void IncreasRating();
    void UptadeTransport();

    static std::string GetOfficeLocation();
    static std::string GetParentCorporation();

};