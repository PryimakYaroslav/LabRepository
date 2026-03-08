#include "Vehicle.h"
#include <iostream>
#include <string>
#include <algorithm>

Vehicle::Vehicle(){
    id = 0;
    model = "Unknown";
    brand = "Unknown";
    FirstStop = "None";
    LastStop = "None";
    run = 0;
}

Vehicle::Vehicle(int VId, std::string VModel, std::string VBrand){
    id = VId;
    model = VModel;
    brand = VBrand;
    FirstStop = "None";
    LastStop = "None";
    run = 0;
}

Vehicle::Vehicle(int VId, std::string VModel, std::string VBrand, std::string VFirstStop, std::string VLastStop, int VRun){
    id = VId;
    model = VModel;
    brand = VBrand;
    FirstStop = VFirstStop;
    LastStop = VLastStop;
    run = VRun;
}

Vehicle::~Vehicle(){
        std::cout << "Info about vehicle " << id << " destroyed" << std::endl;
}

void Vehicle::PrintVehicleInfo(){
        std::cout << "===================================" << std::endl;
        std::cout << "Vehicle ID: " << id << std::endl;
        std::cout << "Model: " << model << std::endl;
        std::cout << "Brand: " << brand << std::endl;
        std::cout << "First Stop: " << FirstStop << std::endl;
        std::cout << "Last Stop: " << LastStop << std::endl;
        std::cout << "Run: " << run << std::endl;
        std::cout << "===================================" << std::endl;
    }

void Vehicle::IncreasRun(){
    run = run + 40000;
}

void Vehicle::SwapStops(){
        std::swap(FirstStop, LastStop);
}