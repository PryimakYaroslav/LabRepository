#pragma once

#include <string>
#include <iostream>

class Vehicle{

    int id;
    std::string model;
    std::string brand;
    std::string FirstStop;
    std::string LastStop;
    long run;
    static std::string location;
    static int totalVehicles;

    public:
    Vehicle();
    Vehicle(int id, std::string model, std::string brand);
    Vehicle(int id, std::string model, std::string brand, std::string FirstStop, std::string LastStop, long run);
    Vehicle(const Vehicle& other);
    ~Vehicle();

    friend std::ostream& operator<<(std::ostream& os, const Vehicle& v);
    friend std::istream& operator>>(std::istream& is, Vehicle& v);

    void IncreasRun();
    void SwapStops();
    void PrintVehicleInfo() const;
    static std::string GetLocation();
    static int GetTotalVehicles();
};
