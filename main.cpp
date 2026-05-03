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

int main() {
    std::vector<std::shared_ptr<Vehicle>> fleet;
    std::vector<std::shared_ptr<Vehicle>> myTickets;

    fleet.push_back(std::make_shared<Touristbus>(1, "Tourist Bus", 56, "Chernivtsi", "Varna", 360000, 3, false, false));
    fleet.push_back(std::make_shared<Microbus>(2, "Microbus", 32, "Lviv", "Drezden", 175000, true, true, "Classic"));
    fleet.push_back(std::make_shared<Van>(3, "Van", 8, "Vinnytsia", "Odesa", 55000, 2.8, true, true));
    fleet.push_back(std::make_shared<Touristbus>(4, "Tourist Bus", 50, "Kyiv", "Viena", 300000, 2, true, false));

int choice = -1;
    while (choice != 0) {
        // КРОК 1: Очищення консолі перед виводом меню
        system("cls"); 

        showMenu();
        
        // КРОК 2: Безпечне введення вибору
        if (!(std::cin >> choice)) {
            std::cout << "\n[!] Error: Please enter a valid number.\n";
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            system("pause");
            continue;
        }

        // Очищення буфера після cin >> choice, щоб getline працював коректно
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

        // КРОК 3: Обробка логіки
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
                std::cin >> type;
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
                std::cout << "\n--- Results for \"" << start << "\" ---\n";
                for (const auto& v : fleet) {
                    if (v->GetRoutStart() == start) v->PrintVehicleInfo();
                }
                break;
            }

            case 4: {
                std::string dest;
                std::cout << "\nEnter destination: ";
                std::getline(std::cin, dest);
                std::cout << "\n--- Results for \"" << dest << "\" ---\n";
                for (const auto& v : fleet) {
                    if (v->GetDestination() == dest) v->PrintVehicleInfo();
                }
                break;
            }

            case 5: {
                int id;
                std::cout << "\nEnter ID for booking: ";
                std::cin >> id;
                bool found = false;
                for (const auto& v : fleet) {
                    if (v->GetID() == id) {
                        myTickets.push_back(v);
                        std::cout << "\n[OK] Ticket for " << v->GetDestination() << " added!\n";
                        found = true;
                        break;
                    }
                }
                if (!found) std::cout << "\n[!] Error: ID not found.\n";
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

            case 0:
                std::cout << "\nExiting... Have a nice day!\n";
                break;

            default:
                std::cout << "\n[!] Invalid option. Try again.\n";
        }

        // КРОК 4: Пауза перед наступною ітерацією, щоб користувач встиг побачити результат
        if (choice != 0) {
            std::cout << "\nPress any key to return to menu...";
            // Використовуємо system("pause"), щоб консоль чекала на дію користувача
            system("pause > nul"); 
        }
    }

    return 0;
}