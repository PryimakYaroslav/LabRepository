#pragma once

#include <string>
#include <iostream>
#include "Vehicle.h"

class Driver{

    std::string name;
    int age;
    int seniority;
    int fineCount;

    static std::string DriverCategory;
    static int AvarageSalary;

    Vehicle myVehicle;

    public:
    Driver();
    Driver(std::string DName, int DAge);
    Driver(std::string DName, int DAge, int Dseniority, int DfineCount, Vehicle transport);
    Driver(Driver&& other) noexcept;
    ~Driver();

    friend std::ostream& operator<<(std::ostream& os, const Driver& d);
    friend std::istream& operator>>(std::istream& is, Driver& d);

    void UpdateDriverData();
    void PrintDriverInfo() const;

    static std::string GetDriverCategory();
    static int GetAvarageSalary();
};