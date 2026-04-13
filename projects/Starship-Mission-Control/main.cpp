#include <iostream>
#include <vector>
#include <fstream>
#include "Starship.h"
#include "Mission.h"
#include "Validation.h"
#include <iomanip> // For std::get_time
#include <sstream> // For std::istringstream

// Function prototypes
std::vector<Starship> loadFromFile(const std::string& filename);
void saveStarshipsToFile(const std::vector<Starship>& starships);
void loadStarshipsFromFile(std::vector<Starship>& starships);
Starship* findStarship(int id, std::vector<Starship>& starships);

bool isStarshipIDUnique(int id, const std::vector<Starship>& starships) {
    for (const auto& ship : starships) {
        if (ship.getShipID() == id) {
            return false; // ID already exists
        }
    }
    return true; // ID is unique
}

void loadFromFile(const std::string& fileName, std::vector<Starship>& starships) {
    std::ifstream file(fileName);
    if (!file.is_open()) {
        std::cerr << "Error: Could not open file for reading.\n";
        return;
    }

    std::string line;
    Starship* currentStarship = nullptr;

    while (std::getline(file, line)) {
        std::istringstream stream(line);
        std::string tag;
        stream >> tag;

        if (tag == "Starship:") {
            int shipID;
            std::string shipName;
            float dailyRate, fuelCapacity;
            int missionAmount;

            stream >> shipID >> shipName >> dailyRate >> fuelCapacity >> missionAmount;

            starships.emplace_back(shipID, shipName, dailyRate, fuelCapacity);
            currentStarship = &starships.back();
        }
        else if (tag == "Mission:" && currentStarship) {
            int numRefuelings, startStardate, endStardate;
            stream >> numRefuelings >> startStardate >> endStardate;

            currentStarship->addMission(Mission(numRefuelings, startStardate, endStardate));
        }
    }

    file.close();
}
void saveToFile(const std::vector<Starship>& starships, const std::string& fileName) {
    std::ofstream file(fileName);
    if (!file) {
        std::cerr << "Error: Could not open file for writing.\n";
        return;
    }

    for (const auto& starship : starships) {
        file << "Starship: " << starship.getShipID() << " " << starship.getShipName()
            << " " << std::fixed << std::setprecision(1) << starship.getDailyRate()
            << " " << starship.getFuelCapacity() << " " << starship.getMissionLog().size()
            << "\n";

        const auto& missions = starship.getMissionLog(); // Assuming `getMissionLog()` returns missions
        int index = 1;
        for (const auto& mission : missions) {
            file << "Mission: " << index++ << " " << mission.getMissionStart()
                << " " << (mission.getMissionEnd() > 0 ? std::to_string(mission.getMissionEnd()) : "0")
                << "\n";
        }
    }

    file.close();
    std::cout << "Data successfully saved to " << fileName << "\n";
}

int main() {
    std::vector<Starship> starships;
    int choice = 0;

    while (choice != 10) {
        printCharByChar("-----------Welcome To Galactic Starship Management------------\n");
        printCharByChar("\n1. Create New Starship\n2. Start Mission\n3. End Mission\n4. Refuel Starship\n");
        printCharByChar("5. View Mission Logs\n6. Calculate Mission Cost\n7. Clear All Starships\n");
        printCharByChar("8. Load Starships from File\n9. Save Starships to File\n10. Exit\n");
        choice = getValidInteger();

        if (choice == 1) {
            int id;
            std::string name;
            float rate{ 0.0f };
            float capacity{ 0.0f };

            printCharByChar("Enter Starship ID: ");
            id = getValidInteger();

            // Check for ID uniqueness
            if (!isStarshipIDUnique(id, starships)) {
                std::ostringstream message;
                message << "Error: A starship with ID " << id
                    << " already exists. Try again with a unique ID.\n";
                printCharByChar(message.str());
                continue; // Skip creation process
            }

            printCharByChar("Enter Starship Name: ");
            std::cin.ignore();
            std::getline(std::cin, name);

            printCharByChar("Enter Daily Rate: ");
            rate = getValidFloat();

            printCharByChar("Enter Fuel Capacity: ");
            capacity = getValidBiggerFloat(rate);

            starships.emplace_back(id, name, rate, capacity);

            std::ostringstream successMessage;
            successMessage << "Starship " << name << " with ID " << id
                << " successfully created.\n";
            printCharByChar(successMessage.str());
        }
        else if (choice == 2) {
            int id;
            printCharByChar("Enter Starship ID: ");
            id = getValidInteger();

            Starship* ship = findStarship(id, starships);
            if (ship) {
                ship->startMission();
            }
            else {
                std::ostringstream message;
                message << "Error: Starship with ID " << id << " not found.\n";
                printCharByChar(message.str());
            }
        }
        else if (choice == 3) {
            int id;
            printCharByChar("Enter Starship ID: ");
            id = getValidInteger();

            Starship* ship = findStarship(id, starships);
            if (ship) {
                ship->endMission();
            }
            else {
                std::ostringstream message;
                message << "Error: Starship with ID " << id << " not found.\n";
                printCharByChar(message.str());
            }
        }

        else if (choice == 4) {
            int id;
            printCharByChar("Enter Starship ID: ");
            id = getValidInteger();

            Starship* ship = findStarship(id, starships);
            if (ship) {
                ship->refuel();
                std::ostringstream message;
                message << "Starship ID " << id << " refueled successfully.\n";
                printCharByChar(message.str());
            }
            else {
                std::ostringstream message;
                message << "Error: Starship with ID " << id << " not found.\n";
                printCharByChar(message.str());
            }
        }
        else if (choice == 5) {
            int id;
            printCharByChar("Enter Starship ID: ");
            id = getValidInteger();

            Starship* ship = findStarship(id, starships);
            if (ship) {
                ship->printMissionLog();
            }
            else {
                std::ostringstream message;
                message << "Error: Starship with ID " << id << " not found.\n";
                printCharByChar(message.str());
            }
        }
        else if (choice == 6) {
            int id;
            printCharByChar("Enter Starship ID: ");
            id = getValidInteger();

            Starship* ship = findStarship(id, starships);
            if (ship) {
                if (ship->getMissionCount() == 0) {
                    std::ostringstream message;
                    message << "Error: Starship ID " << id
                        << " has no mission logs.\n";
                    printCharByChar(message.str());
                }
                else {

                    int missionIndex;
                    printCharByChar("Enter the mission number to calculate cost for (1-based index): ");
                    missionIndex = getValidInteger() - 1;

                    double missionCost = ship->calculateMissionCost(missionIndex);
                    if (missionCost > 0.0) {
                        std::ostringstream message;
                        message << "Cost of Mission " << missionIndex + 1
                            << " for Starship ID " << id << ": $" << missionCost << '\n';
                        printCharByChar(message.str());
                    }
                }
            }
            else {
                std::ostringstream message;
                message << "Error: Starship with ID " << id << " not found.\n";
                printCharByChar(message.str());
            }
        }
        else if (choice == 7) {
            starships.clear();
            printCharByChar("All starships cleared.\n");
        }
        else if (choice == 8) {
            loadStarshipsFromFile(starships);
        }

        else if (choice == 9) {
            saveStarshipsToFile(starships);
        }

        else if (choice == 10) {
            printCharByChar("Exiting program... Goodbye!\n");
        }
        else {
            printCharByChar("Invalid choice. Please try again.\n");
        }
    }

    return 0;
}
void saveStarshipsToFile(const std::vector<Starship>& starships) {
    std::string fileName;
    std::cout << "Enter filename to save: ";
    fileName = getValidString();

    saveToFile(starships, fileName);
}

void loadStarshipsFromFile(std::vector<Starship>& starships) {
    std::string fileName;
    std::cout << "Enter filename to load: ";
    fileName = getValidString();
    starships.clear();
    loadFromFile(fileName, starships);
    std::cout << "Starships loaded successfully from " << fileName << "\n";
}



Starship* findStarship(int id, std::vector<Starship>& starships) {
    for (auto& ship : starships) {
        if (ship.getShipID() == id) return &ship;
    }
    return nullptr;
}
