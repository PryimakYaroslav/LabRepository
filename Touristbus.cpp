#include "Touristbus.h"
#include <utility>
#include <iostream>

Touristbus::Touristbus() : Vehicle(),
    numberOfScreens(0),
    hasToilet(false),
    isDoubleDeckered(false) {};

Touristbus::Touristbus(int id, std::string model, int countOfSeats, int numberOfScreens, bool hasToilet, bool isDoubleDeckered) :
    Vehicle(id, model, countOfSeats),
    numberOfScreens(numberOfScreens),
    hasToilet(hasToilet),
    isDoubleDeckered(isDoubleDeckered) {};

Touristbus::Touristbus(int id, std::string model, int countOfSeats, std::string routStart, std::string destination, long run, 
    int numberOfScreens, bool hasToilet, bool isDoubleDeckered) :
    Vehicle(id, model, countOfSeats, routStart, destination, run),
    numberOfScreens(numberOfScreens),
    hasToilet(hasToilet),
    isDoubleDeckered(isDoubleDeckered) {};

Touristbus::~Touristbus(){
    //std::cout << "Touristbus destroyed" << std::endl;
}

Touristbus::Touristbus(const Touristbus& other) :
    Vehicle(other),
    numberOfScreens(numberOfScreens),
    hasToilet(hasToilet),
    isDoubleDeckered(isDoubleDeckered) {
    std::cout << "Tourist bus copie created" << std::endl;
    }

Touristbus::Touristbus(Touristbus&& other) noexcept : 
    Vehicle(std::move(other)),
    numberOfScreens(other.numberOfScreens),
    hasToilet(other.hasToilet),
    isDoubleDeckered(other.isDoubleDeckered)
{
    //std::cout << "Touristbus moved." << std::endl;
}

void Touristbus::PrintVehicleInfo() const {
    Vehicle::PrintVehicleInfo();
    std::cout << "Number of screens: " << numberOfScreens << std::endl;
    std::cout << "Toilet: " << (hasToilet ? "Available" : "Not available") << std::endl;
    std::cout << "Bus type: " << (isDoubleDeckered ? "Double-deckered" : "Standard (Single deck)") << std::endl;
}

void Touristbus::IncreasRun() {
    run += 50000;
}

void Touristbus::SwapStops() {
    Vehicle::SwapStops();
}