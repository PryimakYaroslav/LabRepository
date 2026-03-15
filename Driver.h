#pragma once

#include <string>
#include <iostream>

class Driver{

    std::string name;
    int age;
    int seniority;
    int fineCount;

    static std::string DriverCategory;
    static int AvarageSalary;

    public:
    Driver();
    Driver(std::string DName, int DAge);
    Driver(std::string DName, int DAge, int Dseniority, int DfineCount);
    ~Driver();

    void UpdateDriverData();
    void PrintDriverInfo() const;

    static std::string GetDriverCategory();
    static int GetAvarageSalary();
};