#include "Vehicle.h"
#include <iostream>
#include <string>

void Vehicle::PrintVehicleInfo(){
        std::cout << "===================================" << std::endl;
        std::cout << "Vehicle ID: " << id << std::endl;
        std::cout << "Model: " << model << std::endl;
        std::cout << "Brand: " << brand << std::endl;
        std::cout << "First Stop: " << FirstStop << std::endl;
        std::cout << "Last Stop: " << LastStop << std::endl;
        std::cout << "===================================" << std::endl;
    }

Vehicle::Vehicle(int VId, std::string VModel, std::string VBrand, std::string VFirstStop, std::string VLastStop){
    id = VId;
    model = VModel;
    brand = VBrand;
    FirstStop = VFirstStop;
    LastStop = VLastStop;
}