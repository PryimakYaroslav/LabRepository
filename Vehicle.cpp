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

std::ostream& operator<<(std::ostream& os, const Vehicle& v){
    os << "===================================" << std::endl;
    os << "Vehicle ID: " << v.id << std::endl;
    os << "Model: " << v.model << std::endl;
    os << "Brand: " << v.brand << std::endl;
    os << "First Stop: " << v.FirstStop << std::endl;
    os << "Last Stop: " << v.LastStop << std::endl;
    os << "Run: " << v.run << std::endl;
    os << "Location: " << v.location << std::endl; 
    os << "===================================" << std::endl; 

    return os;
}

std::istream& operator>>(std::istream& is, Vehicle& v) {
    std::cout << "Enter ID: "; is >> v.id;
    std::cout << "Enter Model: "; is >> v.model;
    std::cout << "Enter Brand: "; is >> v.brand;
    std::cout << "Enter Run: "; is >> v.run;
    
    return is;
}

void Vehicle::PrintVehicleInfo() const{
        std::cout << *this << std::endl;
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
    std::cout << "Vehicle copy created. ID: " << id <<". Total count of vehicles: " << totalVehicles << std::endl;
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