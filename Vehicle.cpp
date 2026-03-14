#include "Vehicle.h"
#include <iostream>
#include <string>
#include <algorithm>

Vehicle::Vehicle() : Vehicle(0, "Unknown", "Unknown", "None", "None", 0) {}

Vehicle::Vehicle(int id, std::string model, std::string brand) 
    : Vehicle(id, model, brand, "None", "None", 0) {} 

Vehicle::Vehicle(int id, std::string model, std::string brand, std::string FirstStop, std::string LastStop, long run) : 
    id(id), 
    model(model), 
    brand(brand), 
    FirstStop(FirstStop), 
    LastStop(LastStop), 
    run(run) {}

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