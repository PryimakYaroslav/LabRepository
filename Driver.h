#ifndef DRIVER_H
#define DRIVER_H

#include <string>

class Driver{

    std::string name;
    int age;
    int seniority;
    int fineCount;

    public:
    Driver(std::string DName, int DAge, int Dseniority, int DfineCount);

    void UpdateDriverData();
    void PrintDriverInfo();

};

#endif