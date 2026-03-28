#pragma once

#include <string>
#include <iostream>

class Vehicle{

    int id;
    std::string model;
    int countOfSeats;
    std::string routStart;
    std::string destination;
    long run;
    static std::string location;
    static int totalVehicles;

    public:
    Vehicle();
    Vehicle(int id, std::string model, int countOfSeats);
    Vehicle(int id, std::string model, int countOfSeats, std::string routStart, std::string destination, long run);
    Vehicle(const Vehicle& other);
    ~Vehicle();

    friend std::ostream& operator<<(std::ostream& os, const Vehicle& v);
    friend std::istream& operator>>(std::istream& is, Vehicle& v);

    void IncreasRun();
    void SwapStops();
    void PrintVehicleInfo() const;
    static std::string GetLocation();
    static int GetTotalVehicles();
};
