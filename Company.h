#ifndef COMPANY_H
#define COMPANY_H

#include <string>

class Company{

    std::string CompanyName;
    int VehicleCount;
    int DriverCount;
    double CompanyRating;

    public:

    Company();
    Company(std::string CName);
    Company(std::string CName, int VCount, int DCount, double Rating);
    ~Company();
    
    void PrintCompanyInfo();
    void SetRating(double Rating);
    void IncreasRating();
    void UptadeTransport();

};

#endif