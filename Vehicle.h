#pragma once

#include <string>
#include <iostream>

class Vehicle{

    int id;
    std::string model;
    std::string brand;
    std::string FirstStop;
    std::string LastStop;
    int run;

    public:
    Vehicle();
    Vehicle(int id, std::string model, std::string brand);
    Vehicle(int id, std::string model, std::string brand, std::string FirstStop, std::string LastStop, int run);
    ~Vehicle();

    void IncreasRun();
    void SwapStops();
    void PrintVehicleInfo();

};
