#include "Vehicle.h"
#include <iostream>
#include <string>
#include <algorithm>

std::string Vehicle::location = "Hangar 1";
int Vehicle::totalVehicles = 0;

Vehicle::Vehicle() : Vehicle(0, "Unknown", 0, "None", "None", 0) {}

Vehicle::Vehicle(int id, std::string model, int countOfSeats) 
    : Vehicle(id, model, countOfSeats, "None", "None", 0) {} 

Vehicle::Vehicle(int id, std::string model, int countOfSeats, std::string routStart, std::string destination, long run) : 
    id(id), 
    model(model), 
    countOfSeats(countOfSeats), 
    routStart(routStart), 
    destination(destination), 
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
    os << "Count of seats: " << v.countOfSeats << std::endl;
    os << "Start of rout: " << v.routStart << std::endl;
    os << "Destination: " << v.destination << std::endl;
    os << "Run: " << v.run << std::endl;
    os << "Location: " << v.location << std::endl; 
    os << "===================================" << std::endl; 

    return os;
}

std::istream& operator>>(std::istream& is, Vehicle& v) {
    std::cout << "Enter ID: "; is >> v.id;
    std::cout << "Enter Model: "; is >> v.model;
    std::cout << "Enter start of rout: ", is >> v.routStart;
    std::cout << "Enter destination: ", is >> v.destination;
    std::cout << "Enter Run: "; is >> v.run;
    
    return is;
}

void Vehicle::PrintVehicleInfo() const{
        std::cout << *this << std::endl;
    }

Vehicle::Vehicle(const Vehicle& other) :
    id(other.id),
    model(other.model),
    countOfSeats(other.countOfSeats),
    routStart(other.routStart),
    destination(other.destination),
    run(other.run)
{
    totalVehicles++;
    std::cout << "Vehicle copy created. ID: " << id <<". Total count of vehicles: " << totalVehicles << std::endl;
}

Vehicle::Vehicle(Vehicle&& other) noexcept :
    id(other.id),
    model(std::move(other.model)),
    countOfSeats(other.countOfSeats),
    routStart(std::move(other.routStart)),
    destination(std::move(other.destination)),
    run(other.run)
{
    other.id = 0; 
    
    totalVehicles++; 

    std::cout << "Vehicle moved. ID: " << id << ". Total: " << totalVehicles << std::endl;
}

void Vehicle::IncreasRun(){
    run = run + 40000;
}

void Vehicle::SwapStops(){
        std::swap(routStart, destination);
}

std::string Vehicle::GetLocation(){
    return "All vehicle are located in " + location;
}

int Vehicle::GetTotalVehicles(){
    return totalVehicles;
}