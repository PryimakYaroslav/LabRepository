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

Van::~Van(){
    std::cout << "Van destroyed" << std::endl;
}