#ifndef DRIVER_H
#define DRIVER_H

#include <string>

class Driver{

    std::string name;
    int age;
    int seniority;
    int fineCount;

    public:
    Driver();
    Driver(std::string DName, int DAge);
    Driver(std::string DName, int DAge, int Dseniority, int DfineCount);
    ~Driver();

    void UpdateDriverData();
    void PrintDriverInfo();

};

#endif