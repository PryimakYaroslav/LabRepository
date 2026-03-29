#include "Touristbus.h"
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
    std::cout << "Touristbus destroyed" << std::endl;
}

Touristbus::Touristbus(const Touristbus& other) :
    Vehicle(other),
    numberOfScreens(numberOfScreens),
    hasToilet(hasToilet),
    isDoubleDeckered(isDoubleDeckered) {
        std::cout << "Tourist bus copie created" << std::endl;
    }