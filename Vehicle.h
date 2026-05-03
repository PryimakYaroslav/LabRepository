#pragma once

#include <string>
#include <iostream>

class Vehicle{

    protected:
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
    Vehicle(Vehicle&& other) noexcept;
    virtual ~Vehicle();

    friend std::ostream& operator<<(std::ostream& os, const Vehicle& v);
    friend std::istream& operator>>(std::istream& is, Vehicle& v);

    virtual void IncreasRun();
    virtual void SwapStops();
    std::string GetRoutStart();
    std::string GetDestination();
    virtual int GetID();
    virtual void PrintVehicleInfo() const = 0;
    static std::string GetLocation();
    static int GetTotalVehicles();
};
