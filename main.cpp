#include <iostream>
#include <string>
#include <utility>
#include <memory>
#include <vector>
#include "Company.h"
#include "Driver.h"
#include "Vehicle.h"
#include "Van.h"
#include "Microbus.h"
#include "Touristbus.h"

using namespace std;

int main(){

std::vector<std::unique_ptr<Vehicle>> fleet;

auto tBus = std::make_unique<Touristbus>(1, "Tourist Bus", 56, "Chernivtsi", "Varna", 360000, 3, false, false);
auto mBus = std::make_unique<Microbus>(2, "Microbus", 32, "Lviv", "Drezden", 175000, true, true, "Classic");
auto vBus = std::make_unique<Van>(3, "Van", 8, "Vinnytsia", "Odesa", 55000, 2.8, true, true);
auto tBus1 = std::make_unique<Touristbus>(4, "Tourist Bus", 50, "Kyiv", "Viena", 300000, 2, true, false);

fleet.push_back(std::move(tBus));
fleet.push_back(std::move(mBus));
fleet.push_back(std::move(vBus));
fleet.push_back(std::move(tBus1));

std::cout << "=== ПОВНИЙ СПИСОК ТРАНСПОРТУ ===" << std::endl;
for (const auto& vehicle : fleet) {
    vehicle->PrintVehicleInfo();
    std::cout << "=================================" << std::endl;
}

return 0;
}