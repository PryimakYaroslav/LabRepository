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

Driver::Driver(Driver&& other) noexcept 
    : name(std::move(other.name)),
      age(other.age),
      seniority(other.seniority),
      fineCount(other.fineCount) 
{
    other.age = 0;
    other.seniority = 0;
    other.fineCount = 0;
    
    std::cout << "Move constructor called for " << name << std::endl;
}

std::ostream& operator<<(std::ostream& os, const Driver& d) {
    os << "===================================" << std::endl;
    os << "Driver Name: " << d.name << std::endl;
    os << "Driver age: " << d.age << " years" << std::endl;
    os << "Driver seniority: " << d.seniority << " years" << std::endl;
    os << "Fine Count: " << d.fineCount << std::endl;
    os << "Category: " << Driver::DriverCategory << std::endl;
    os << "===================================";

    return os;
}

std::istream& operator>>(std::istream& is, Driver& d) {
    std::cout << "Enter Driver Name: "; is >> d.name;
    std::cout << "Enter Age: "; is >> d.age;
    std::cout << "Enter Seniority: "; is >> d.seniority;
    std::cout << "Enter Fines: "; is >> d.fineCount;

    return is;
}

void Driver::PrintDriverInfo() const{
   std::cout << *this << std::endl;
}

void Driver::UpdateDriverData(){
    this -> age += 5;
    this -> seniority -= 7;
    this -> fineCount += 1;

    if (this -> seniority < 0)
    this -> seniority = 0;
}

std::string Driver::GetDriverCategory(){
    return "All drivers have license category " + DriverCategory;
}

int Driver::GetAvarageSalary(){
    return AvarageSalary;
}