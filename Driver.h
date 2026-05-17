#pragma once

#include <string>
#include <iostream>
#include <memory>
#include "Vehicle.h"

class Driver final {
    int id;
    std::string name;
    int age;
    int seniority;
    int fineCount;

    static std::string DriverCategory;
    static int AvarageSalary;

    std::weak_ptr<Vehicle> myVehicle;

public:
    Driver();
    Driver(int id, std::string DName, int DAge);
    Driver(int id, std::string DName, int DAge, int Dseniority, int DfineCount);
    Driver(int id, std::string DName, int DAge, int Dseniority, int DfineCount, std::shared_ptr<Vehicle> transport);
    
    Driver(Driver&& other) noexcept;
    Driver& operator=(Driver&& other) noexcept = default;
    Driver(const Driver& other) = default;
    
    ~Driver();

    friend std::ostream& operator<<(std::ostream& os, const Driver& d);
    friend std::istream& operator>>(std::istream& is, Driver& d);

    void UpdateDriverData();
    void PrintDriverInfo() const;

    int GetID() const { return id; }
    std::string GetName() const { return name; }
    void SetVehicle(std::shared_ptr<Vehicle> v) { myVehicle = v; }
    std::weak_ptr<Vehicle> GetVehicle() const { return myVehicle; }

    static std::string GetDriverCategory();
    static int GetAvarageSalary();
};