#include "Vehicle.h"
#include <iostream>
#include <string>
#include <algorithm>

std::string Vehicle::location = "Hangar 1";
int Vehicle::totalVehicles = 0;

Vehicle::Vehicle() : Vehicle(0, "Unknown", "Unknown", "None", "None", 0) {}

Vehicle::Vehicle(int id, std::string model, std::string brand) 
    : Vehicle(id, model, brand, "None", "None", 0) {} 

Vehicle::Vehicle(int id, std::string model, std::string brand, std::string FirstStop, std::string LastStop, long run) : 
    id(id), 
    model(model), 
    brand(brand), 
    FirstStop(FirstStop), 
    LastStop(LastStop), 
    run(run) 
    {
        totalVehicles++;
    }

Vehicle::~Vehicle(){
        std::cout << "Info about vehicle " << id << " destroyed" << std::endl;
}

void Vehicle::PrintVehicleInfo() const{
        std::cout << "===================================" << std::endl;
        std::cout << "Vehicle ID: " << id << std::endl;
        std::cout << "Model: " << model << std::endl;
        std::cout << "Brand: " << brand << std::endl;
        std::cout << "First Stop: " << FirstStop << std::endl;
        std::cout << "Last Stop: " << LastStop << std::endl;
        std::cout << "Run: " << run << std::endl;
        std::cout << "Location: " << location << std::endl; 
        std::cout << "===================================" << std::endl;
    }

Vehicle::Vehicle(const Vehicle& other) :
    id(other.id),
    model(other.model),
    brand(other.brand),
    FirstStop(other.FirstStop),
    LastStop(other.LastStop),
    run(other.run)
{
    totalVehicles++;
    std::cout << "Vehicle vopy created. ID: " << id <<". Total count of vehicles: " << totalVehicles << std::endl;
}

void Vehicle::IncreasRun(){
    run = run + 40000;
}

void Vehicle::SwapStops(){
        std::swap(FirstStop, LastStop);
}

std::string Vehicle::GetLocation(){
    return "All vehicle are located in " + location;
}

int Vehicle::GetTotalVehicles(){
    return totalVehicles;
}