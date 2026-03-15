#include "Driver.h"
#include <iostream>
#include <string>

std::string Driver::DriverCategory = "D";
int Driver::AvarageSalary = 1100;

Driver::Driver() : Driver("Unknown", 0, 0, 0) {}

Driver::Driver(std::string DName, int DAge) : Driver(DName, DAge, 0, 0) {}

Driver::Driver(std::string DName, int DAge, int Dseniority, int DfineCount) :
    name(DName),
    age(DAge),
    seniority(Dseniority),
    fineCount(DfineCount) {}

Driver::~Driver() {
        std::cout << "Info about driver " << name << " destroyed" << std::endl;
}

void Driver::PrintDriverInfo(){
    std::cout << "===================================" << std::endl;
        std::cout << "Driver Name: " << name << std::endl;
        std::cout << "Driver age: " << age << " years"<<std::endl;
        std::cout << "Driver seniority: " << seniority << " years" << std::endl;
        std::cout << "Fine Count: " << fineCount << std::endl;
        std::cout << "===================================" << std::endl;
}

void Driver::UpdateDriverData(){
    age = age + 5;
    seniority = seniority - 7;
    fineCount = fineCount +1;

    if (seniority < 0)
    seniority = 0;
}

std::string Driver::GetDriverCategory(){
    return "All drivers have license category " + DriverCategory;
}

int Driver::GetAvarageSalary(){
    return AvarageSalary;
}