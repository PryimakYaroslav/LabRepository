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
    std::cout << "2. Remove vehicle by ID";
    std::cout << "3. List of Drivers\n";
    std::cout << "4. Add new Driver\n";
    std::cout << "5. Remove driver";
    std::cout << "6. Change vehicle owner";
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
    TransportNotFoundException (int id) {
        message = "Error: Vehicle with ID " + std::to_string(id) + " was not found in our fleet";
    }

    const char* what() const noexcept override {
        return message.c_str();
    }
};

int main() {
    std::vector<std::shared_ptr<Vehicle>> fleet;
    std::vector<std::shared_ptr<Vehicle>> myTickets;

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

            if (choice == 0) break;

            if (choice == 228) {
                system("cls");
                int password;
                std::cout << "ADMIN MENU. Enter secret code: ";
                std::cin >> password;

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

                        if (adminChoice == 0) {
                            runningAdminMenu = false;
                        } else {
                            std::cout << "\n[Admin] Option " << adminChoice << " selected (Logic coming soon)\n";
                            system("pause");
                        }
                    }
                } else {
                    throw std::runtime_error("Incorrect secret code!");
                }
            }
            
            std::cin.ignore(10000, '\n');

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
                            std::cout << "- Trip: " << t->GetRoutStart() << " -> " 
                                      << t->GetDestination() << " (ID: " << t->GetID() << ")\n";
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
            std::cerr << "\n [!] GENERAL ERROR: " << e.what() << std::endl;
        }

        std::cout << "\nPress Enter to continue...";
        std::cin.ignore(10000, '\n');
        std::cin.get(); 
    }

    return 0;
}