#ifndef COMPANY_H
#define COMPANY_H

#include <string>

class Company{

    std::string CompanyName;
    int VehicleCount;
    int DriverCount;
    double CompanyRating;

    public:
    Company(std::string CName, int VCount, int DCount, double Rating);

    void PrintCompanyInfo();
    void SetRating(double Rating);
    void IncreasRating();
    void UptadeTransport();

};

#endif