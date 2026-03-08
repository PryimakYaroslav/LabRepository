#include "Driver.h"
#include <iostream>
#include <string>

void Driver::PrintDriverInfo(){
    std::cout << "===================================" << std::endl;
        std::cout << "Driver Name: " << name << std::endl;
        std::cout << "Driver age: " << age << " years"<<std::endl;
        std::cout << "Driver seniority: " << seniority << " ages" << std::endl;
        std::cout << "Fine Count: " << fineCount << std::endl;
        std::cout << "===================================" << std::endl;
}

void Driver::UpdateDriverData(){
    age = age + 5;
    seniority = seniority - 7;
    fineCount = fineCount +1;
}

Driver::Driver(std::string DName, int DAge, int Dseniority, int DfineCount) {
    name = DName;
    age = DAge;
    seniority = Dseniority;
    fineCount = DfineCount;
}