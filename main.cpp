#include <iostream>
#include <string>
#include <limits>
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

void showMenu() {
    std::cout << "\n============ User Menu =============\n";
    std::cout << "1. List of all transport\n";
    std::cout << "2. List by type (Van/Microbus/Touristbus)\n";
    std::cout << "3. Search by rout start\n";
    std::cout << "4. Search by destination\n";
    std::cout << "5. Book ticket\n";
    std::cout << "6. View booked tickets\n";
    std::cout << "0. Exit\n";
    std::cout << "--------------------------------------\n";
    std::cout << "Your choice: ";
}

void showAdminMenu() {
    std::cout << "\n============ Admin Menu =============\n";
    std::cout << "1. Add new vehicle\n";
    std::cout << "2. Remove vehicle by ID\n";
    std::cout << "3. List of Drivers\n";
    std::cout << "4. Add new Driver\n";
    std::cout << "5. Remove driver\n";
    std::cout << "6. Change vehicle owner\n";
    std::cout << "7. Return to user menu\n";
    std::cout << "--------------------------------------\n";
    std::cout << "Your choice: ";
}

class InvalidInputException : public std::exception {
public:
    const char* what() const noexcept override {
        return "Invalid input! Enter a valid number for the menu.";
    }
};

class TransportNotFoundException : public std::exception {
    std::string message;
public:
    TransportNotFoundException(int id) {
        message = "Error: Vehicle with ID " + std::to_string(id) + " was not found in our fleet";
    }

    const char* what() const noexcept override {
        return message.c_str();
    }
};

int main() {
    std::vector<std::shared_ptr<Vehicle>> fleet;
    std::vector<std::weak_ptr<Vehicle>> myTickets;
    std::vector<Driver> Drivers;

    fleet.push_back(std::make_shared<Touristbus>(1, "Tourist Bus", 56, "Chernivtsi", "Varna", 360000, 3, false, false));
    fleet.push_back(std::make_shared<Microbus>(2, "Microbus", 32, "Lviv", "Drezden", 175000, true, true, "Classic"));
    fleet.push_back(std::make_shared<Van>(3, "Van", 8, "Vinnytsia", "Odesa", 55000, 2.8, true, true));
    fleet.push_back(std::make_shared<Touristbus>(4, "Tourist Bus", 50, "Kyiv", "Viena", 300000, 2, true, false));

    int choice;

    while (true) {
        try {
            system("cls");
            showMenu();

            if (!(std::cin >> choice)) {
                std::cin.clear();
                std::cin.ignore(10000, '\n');
                throw InvalidInputException();
            }
            std::cin.ignore(10000, '\n');

            if (choice == 0) break;

            if (choice == 228) {
                system("cls");
                int password;
                std::cout << "ADMIN MENU. Enter secret code: ";
                if (!(std::cin >> password)) {
                    std::cin.clear();
                    std::cin.ignore(10000, '\n');
                    throw InvalidInputException();
                }
                std::cin.ignore(10000, '\n'); 

                if (password == 688149) {
                    bool runningAdminMenu = true;
                    while (runningAdminMenu) {
                        system("cls");
                        showAdminMenu();

                        int adminChoice;
                        if (!(std::cin >> adminChoice)) {
                            std::cin.clear();
                            std::cin.ignore(10000, '\n');
                            continue;
                        }
                        std::cin.ignore(10000, '\n'); 

                        switch (adminChoice) {
                            case 1: {
                                system("cls");
                                std::cout << "===== ADD NEW VEHICLE =====\n";
                                std::cout << "Choose type to add:\n";
                                std::cout << "1. Van\n";
                                std::cout << "2. Microbus\n";
                                std::cout << "3. Touristbus\n";
                                std::cout << "---------------------------\n";
                                std::cout << "Your choice: ";

                                int typeChoice;
                                if (!(std::cin >> typeChoice)) {
                                    std::cin.clear();
                                    std::cin.ignore(10000, '\n');
                                    throw InvalidInputException();
                                }
                                std::cin.ignore(10000, '\n'); 

                                if (typeChoice < 1 || typeChoice > 3) {
                                    std::cout << "\n[!] Invalid type selected.\n";
                                    system("pause");
                                    break;
                                }

                                int id, seats;
                                long run;
                                std::string model, start, dest;

                                std::cout << "\nEnter ID: "; 
                                if (!(std::cin >> id)) { std::cin.clear(); std::cin.ignore(10000, '\n'); throw InvalidInputException(); }
                                std::cin.ignore(10000, '\n');

                                bool idExists = false;
                                for (const auto& v : fleet) {
                                    if (v->GetID() == id) { idExists = true; break; }
                                }
                                if (idExists) {
                                    std::cout << "\n[!] Error: Vehicle with ID " << id << " already exists!\n";
                                    system("pause");
                                    break;
                                }

                                std::cout << "Enter Model: "; 
                                std::getline(std::cin, model);

                                std::cout << "Enter count of seats: "; 
                                if (!(std::cin >> seats)) { std::cin.clear(); std::cin.ignore(10000, '\n'); throw InvalidInputException(); }
                                std::cin.ignore(10000, '\n');

                                std::cout << "Enter route start: "; 
                                std::getline(std::cin, start);

                                std::cout << "Enter destination: "; 
                                std::getline(std::cin, dest);

                                std::cout << "Enter run (mileage): "; 
                                if (!(std::cin >> run)) { std::cin.clear(); std::cin.ignore(10000, '\n'); throw InvalidInputException(); }
                                std::cin.ignore(10000, '\n');

                                if (typeChoice == 1) {
                                    double cargoCapacity;
                                    bool hasUSB, hasConditioner;

                                    std::cout << "Enter cargo capacity (m^3): ";
                                    if (!(std::cin >> cargoCapacity)) { std::cin.clear(); std::cin.ignore(10000, '\n'); throw InvalidInputException(); }
                                    
                                    std::cout << "Has USB ports? (1 - Yes, 0 - No): ";
                                    if (!(std::cin >> hasUSB)) { std::cin.clear(); std::cin.ignore(10000, '\n'); throw InvalidInputException(); }
                                    
                                    std::cout << "Has air conditioner? (1 - Yes, 0 - No): ";
                                    if (!(std::cin >> hasConditioner)) { std::cin.clear(); std::cin.ignore(10000, '\n'); throw InvalidInputException(); }
                                    std::cin.ignore(10000, '\n');

                                    fleet.push_back(std::make_shared<Van>(id, model, seats, start, dest, run, cargoCapacity, hasUSB, hasConditioner));
                                    std::cout << "\n[OK] Van successfully added to the fleet!\n";

                                } else if (typeChoice == 2) {
                                    bool climate, adjustableSeats;
                                    std::string interior;

                                    std::cout << "Has climate control? (1 - Yes, 0 - No): ";
                                    if (!(std::cin >> climate)) { std::cin.clear(); std::cin.ignore(10000, '\n'); throw InvalidInputException(); }
                                    
                                    std::cout << "Has adjustable seats? (1 - Yes, 0 - No): ";
                                    if (!(std::cin >> adjustableSeats)) { std::cin.clear(); std::cin.ignore(10000, '\n'); throw InvalidInputException(); }
                                    std::cin.ignore(10000, '\n');

                                    std::cout << "Enter interior type (e.g., Luxury, Classic, Standart): ";
                                    std::getline(std::cin, interior);

                                    fleet.push_back(std::make_shared<Microbus>(id, model, seats, start, dest, run, climate, adjustableSeats, interior));
                                    std::cout << "\n[OK] Microbus successfully added to the fleet!\n";

                                } else if (typeChoice == 3) {
                                    int screens;
                                    bool toilet, doubleDeck;

                                    std::cout << "Enter number of screens: ";
                                    if (!(std::cin >> screens)) { std::cin.clear(); std::cin.ignore(10000, '\n'); throw InvalidInputException(); }
                                    
                                    std::cout << "Has toilet? (1 - Yes, 0 - No): ";
                                    if (!(std::cin >> toilet)) { std::cin.clear(); std::cin.ignore(10000, '\n'); throw InvalidInputException(); }
                                    
                                    std::cout << "Is double-deckered? (1 - Yes, 0 - No): ";
                                    if (!(std::cin >> doubleDeck)) { std::cin.clear(); std::cin.ignore(10000, '\n'); throw InvalidInputException(); }
                                    std::cin.ignore(10000, '\n');

                                    fleet.push_back(std::make_shared<Touristbus>(id, model, seats, start, dest, run, screens, toilet, doubleDeck));
                                    std::cout << "\n[OK] Tourist Bus successfully added to the fleet!\n";
                                }

                                system("pause");
                                break;
                            }

                            case 2: {
                                system("cls");
                                std::cout << "===== REMOVE VEHICLE BY ID =====\n";
                                std::cout << "Enter Vehicle ID to remove: ";
                                
                                int idToRemove;
                                if (!(std::cin >> idToRemove)) {
                                    std::cin.clear();
                                    std::cin.ignore(10000, '\n');
                                    throw InvalidInputException();
                                }
                                std::cin.ignore(10000, '\n'); 

                                bool found = false;

                                for (size_t i = 0; i < fleet.size(); i++) {
                                    if (fleet[i]->GetID() == idToRemove) {
                                        fleet.erase(fleet.begin() + i); 
                                        
                                        std::cout << "\n[OK] Vehicle with ID " << idToRemove << " was successfully removed.\n";
                                        found = true;
                                        break; 
                                    }
                                }

                                if (!found) {
                                    throw TransportNotFoundException(idToRemove);
                                }

                                system("pause");
                                break;
                            }

                            case 3: {
                                system("cls");
                                std::cout << "===== LIST OF DRIVERS =====\n";
                                if (Drivers.empty()) {
                                    std::cout << "No drivers registered in the system.\n";
                                } else {
                                    for (size_t i = 0; i < Drivers.size(); i++) {
                                         Drivers[i].PrintDriverInfo();
                                        std::cout << std::endl;
                                    }
                                }
                                system("pause");
                                break;
                            }

                            case 4: {
                                system("cls");
                                std::cout << "===== ADD NEW DRIVER =====\n";
        
                                int id, age, seniority, fines;
                                std::string name;

                                std::cout << "Enter Driver ID: ";
                                if (!(std::cin >> id)) { std::cin.clear(); std::cin.ignore(10000, '\n'); throw InvalidInputException(); }
                                std::cin.ignore(10000, '\n');

                                bool driverExists = false;
                                for (size_t i = 0; i < Drivers.size(); i++) {
                                    if (Drivers[i].GetID() == id) { driverExists = true; break; }
                                }
                                if (driverExists) {
                                    std::cout << "\n[!] Error: Driver with ID " << id << " already exists!\n";
                                    system("pause");
                                    break;
                                }

                                std::cout << "Enter Driver Name: ";
                                std::getline(std::cin, name);

                                std::cout << "Enter Age: ";
                                if (!(std::cin >> age)) { std::cin.clear(); std::cin.ignore(10000, '\n'); throw InvalidInputException(); }
                                std::cout << "Enter Seniority (years): ";
                                if (!(std::cin >> seniority)) { std::cin.clear(); std::cin.ignore(10000, '\n'); throw InvalidInputException(); }
                                std::cout << "Enter Fine Count: ";
                                if (!(std::cin >> fines)) { std::cin.clear(); std::cin.ignore(10000, '\n'); throw InvalidInputException(); }
                                std::cin.ignore(10000, '\n');

                                Driver newDriver(id, name, age, seniority, fines, nullptr);

                                std::cout << "\nDo you want to assign a vehicle to this driver now? (1 - Yes, 0 - No): ";
                                int assignChoice;
                                if (std::cin >> assignChoice && assignChoice == 1) {
                                    std::cout << "Enter Vehicle ID to assign: ";
                                    int vehicleId;
                                    if (std::cin >> vehicleId) {
                                        std::shared_ptr<Vehicle> foundVehicle = nullptr;
                                        for (size_t i = 0; i < fleet.size(); i++) {
                                            if (fleet[i]->GetID() == vehicleId) {
                                            foundVehicle = fleet[i];
                                            break;
                                        }
                                    }
                                    if (foundVehicle != nullptr) {
                                        newDriver.SetVehicle(foundVehicle);
                                        std::cout << "[OK] Vehicle with ID " << vehicleId << " successfully assigned to " << name << "!\n";
                                    } else {
                                        std::cout << "[!] Vehicle with ID " << vehicleId << " not found. Driver created without a vehicle.\n";
                                    }
                                }
                            }
                            std::cin.ignore(10000, '\n');

                            Drivers.push_back(std::move(newDriver));
                            std::cout << "\n[OK] Driver successfully added to the system!\n";
                            system("pause");
                            break;
                            }

                            case 7:
                            case 0:
                                runningAdminMenu = false;
                                break;

                            default:
                                std::cout << "\n[Admin] Option " << adminChoice << " selected (Logic coming soon)\n";
                                system("pause");
                                break;
                        }
                    }
                } else {
                    throw std::runtime_error("Incorrect secret code!");
                }
                continue; 
            }

            switch (choice) {
                case 1:
                    std::cout << "\n--- All Vehicles ---\n";
                    for (const auto& v : fleet) {
                        std::cout << "-----------------------" << std::endl;
                        v->PrintVehicleInfo();
                        std::cout << "-----------------------" << std::endl;
                    }
                    break;

                case 2: {
                    int type;
                    std::cout << "\nChoose type (1-Van, 2-Microbus, 3-Touristbus): ";
                    if (!(std::cin >> type)) throw InvalidInputException();
                    std::cin.ignore(10000, '\n');

                    std::cout << "\n--- Filtered Results ---\n";
                    for (const auto& v : fleet) {
                        bool match = false;
                        if (type == 1 && std::dynamic_pointer_cast<Van>(v)) match = true;
                        else if (type == 2 && std::dynamic_pointer_cast<Microbus>(v)) match = true;
                        else if (type == 3 && std::dynamic_pointer_cast<Touristbus>(v)) match = true;

                        if (match) {
                            std::cout << "-----------------------" << std::endl;
                            v->PrintVehicleInfo();
                            std::cout << "-----------------------" << std::endl;
                        }
                    }
                    break;
                }

                case 3: {
                    std::string start;
                    std::cout << "\nEnter route start: ";
                    std::getline(std::cin, start); 
                    for (const auto& v : fleet) {
                        if (v->GetRoutStart() == start) v->PrintVehicleInfo();
                    }
                    break;
                }

                case 4: {
                    std::string dest;
                    std::cout << "\nEnter destination: ";
                    std::getline(std::cin, dest);
                    for (const auto& v : fleet) {
                        if (v->GetDestination() == dest) v->PrintVehicleInfo();
                    }
                    break;
                }

                case 5: {
                    int id;
                    std::cout << "\nEnter ID for booking: ";
                    if (!(std::cin >> id)) throw InvalidInputException();
                    std::cin.ignore(10000, '\n');
                    
                    bool found = false;
                    for (const auto& v : fleet) {
                        if (v->GetID() == id) {
                            myTickets.push_back(v);
                            std::cout << "\n[OK] Ticket for " << v->GetDestination() << " added!\n";
                            found = true;
                            break;
                        }
                    }
                    if (!found) throw TransportNotFoundException(id);
                    break;
                }

                case 6:
                    std::cout << "\n*** Your Booked Tickets ***\n";
                    if (myTickets.empty()) {
                        std::cout << "No tickets booked yet.\n";
                    } else {
                        for (const auto& t : myTickets) {
                            if (auto sharedTicket = t.lock()) {
                                std::cout << "- Trip: " << sharedTicket->GetRoutStart() << " -> " 
                                          << sharedTicket->GetDestination() << " (ID: " << sharedTicket->GetID() << ")\n";
                            } else {
                                std::cout << "- [Notice] A vehicle from your bookings was removed from the fleet.\n";
                            }
                        }
                    }
                    break;

                default:
                    throw InvalidInputException();
            }
        }
        catch (const TransportNotFoundException& e) {
            std::cerr << "\n [!] NOT FOUND: " << e.what() << std::endl;
        }
        catch (const InvalidInputException& e) {
            std::cerr << "\n [!] INPUT ERROR: " << e.what() << std::endl;
        }
        catch (const std::exception& e) {
            std::cerr << "\n [!] ERROR: " << e.what() << std::endl;
        }

        std::cout << "\nPress Enter to continue...";
        std::cin.get(); 
    }

    return 0;
}