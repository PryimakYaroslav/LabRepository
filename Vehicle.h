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

    public:
    Vehicle();
    Vehicle(int id, std::string model, std::string brand);
    Vehicle(int id, std::string model, std::string brand, std::string FirstStop, std::string LastStop, long run);
    ~Vehicle();

    void IncreasRun();
    void SwapStops();
    void PrintVehicleInfo();

};
