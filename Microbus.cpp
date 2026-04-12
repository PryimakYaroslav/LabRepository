#include "Microbus.h"
#include <iostream>

Microbus::Microbus() : Vehicle(),
    climateControl(false),
    hasAdjustableSeats(false),
    interiorType("Standart") {};

Microbus::Microbus(int id, std::string model, int countOfSeats, bool climateControl, bool hasAdjustableSeats, std::string interiorType) :
    Vehicle(id, model, countOfSeats),
    climateControl(climateControl),
    hasAdjustableSeats(hasAdjustableSeats),
    interiorType(interiorType) {}

Microbus::Microbus(int id, std::string model, int countOfSeats, std::string routStart, std::string destination, long run,
bool climateControl, bool hasAdjustableSeats, std::string interiorType) :
    Vehicle(id, model, countOfSeats, routStart, destination, run),
    climateControl(climateControl),
    hasAdjustableSeats(hasAdjustableSeats),
    interiorType(interiorType) {}

Microbus::~Microbus(){
    std::cout << "Microbus destroyed" << std::endl;
}

void Microbus::PrintVehicleInfo() const {
    std::cout << "========== Microbus Info ===========";
    Vehicle::PrintVehicleInfo();
    std::cout << "Climate control: " << climateControl << std::endl;
    std::cout << "Adjustable seats: " << hasAdjustableSeats << std::endl;
    std::cout << "Interior type: " << interiorType << std::endl;
    std::cout << "===================================" << std::endl;
}

void Microbus::IncreasRun() {
    run += 30000;
}

void Microbus::SwapStops() {
    Vehicle::SwapStops();
}