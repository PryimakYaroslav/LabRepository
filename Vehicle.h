#ifndef VEHICLE_H
#define VEHICLE_H

#include <string>

class Vehicle{

    int id;
    std::string model;
    std::string brand;
    std::string FirstStop;
    std::string LastStop;
    int run;

    public:

    Vehicle();
    Vehicle(int VId, std::string VModel, std::string VBrand);
    Vehicle(int VId, std::string VModel, std::string VBrand, std::string VFirstStop, std::string VLastStop, int VRun);
    ~Vehicle();

    void IncreasRun();
    void SwapStops();
    void PrintVehicleInfo();

};

#endif