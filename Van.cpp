#include "Van.h"
#include <iostream>

Van::Van() : Vehicle(), 
    cargoCapacity(0.0), 
    hasUSBports(false), 
    hasConditioner(false) {}

Van::Van(int id, std::string model, int countOfSeats, double cargoCapacity, bool hasUSBports, bool hasConditioner) : 
    Vehicle (id, model, countOfSeats),
    cargoCapacity(cargoCapacity),
    hasUSBports(hasUSBports),
    hasConditioner(hasConditioner) {}

Van::Van(int id, std::string model, int countOfSeats, std::string routStart, std::string destination, long run,
    double cargoCapacity, bool hasUSBports, bool hasConditioner) :
    Vehicle(id, model, countOfSeats, routStart, destination, run),
    cargoCapacity(cargoCapacity),
    hasUSBports(hasUSBports),
    hasConditioner(hasConditioner) {}


void Van::PrintVehicleInfo() const {
    std::cout << "============ Van Info =============";
    Vehicle::PrintVehicleInfo();
    std::cout << "Cargo Capacity: " << cargoCapacity << " kg"  << std::endl;
    std::cout << "USB Ports: " << hasUSBports << std::endl;
    std::cout << "Air Conditioner: " << hasConditioner << std::endl;
    std::cout << "===================================" << std::endl;
}

Van::~Van(){
    std::cout << "Van destroyed" << std::endl;
}