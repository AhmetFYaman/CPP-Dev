#include "Starship.h"
#include <iostream>
#include <iomanip>

// Constructor initializes the starship
Starship::Starship(int id, const std::string& name, float rate, float capacity)
    : shipID(id), shipName(name), dailyRate(rate), fuelCapacity(capacity) {
}

// Start a new mission
void Starship::startMission() {
    if (!missionLog.empty() && missionLog.back().getMissionEnd() == 0) {
        std::cout << "Error: Starship " << shipName << " is already on an ongoing mission.\n";
        return;
    }

    missionLog.emplace_back(); // Start a new mission
    std::cout << "New mission started for Starship " << shipName << ".\n";
}

// End the ongoing mission
void Starship::endMission() {
    if (missionLog.empty() || missionLog.back().getMissionEnd() != 0) {
        std::cout << "Error: No ongoing mission to end for Starship " << shipName << ".\n";
        return;
    }

    missionLog.back().endMission();
    std::cout << "Mission ended for Starship " << shipName << ".\n";
}

// Refuel during a mission
void Starship::refuel() {
    if (missionLog.empty() || missionLog.back().getMissionEnd() != 0) {
        std::cout << "No ongoing mission to refuel.\n";
        return;
    }
    missionLog.back().refuel();
}

// Calculate the cost of a specific mission
double Starship::calculateMissionCost(int missionIndex) const {
    if (missionIndex < 0 || missionIndex >= missionLog.size()) {
        throw std::out_of_range("Invalid mission index.");
    }
    const Mission& mission = missionLog[missionIndex];
    int duration = mission.getMissionEnd() - mission.getMissionStart();
    return (duration / 86400.0) * dailyRate + mission.getNumRefuelings() * fuelCapacity;
}

// Calculate the total cost of all completed missions
double Starship::calculateTotalCost() const {
    double total = 0.0;
    for (size_t i = 0; i < missionLog.size(); ++i) {
        total += calculateMissionCost(i);
    }
    return total;
}

// Print the mission log
void Starship::printMissionLog() const {
    if (missionLog.empty()) {
        std::cout << "No missions logged for " << shipName << ".\n";
        return;
    }

    for (size_t i = 0; i < missionLog.size(); ++i) {
        const auto& mission = missionLog[i];
        double cost = calculateMissionCost(i);

        std::cout << "Mission " << i + 1 << ": Start=" << mission.getMissionStart()
            << ", End=" << mission.getMissionEnd()
            << ", Refuelings=" << mission.getNumRefuelings()
            << ", Cost= " << cost << " \n";
    }
}

// Accessor functions for starship details
int Starship::getShipID() const {
    return shipID;
}

std::string Starship::getShipName() const {
    return shipName;
}

float Starship::getDailyRate() const {
    return dailyRate;
}

float Starship::getFuelCapacity() const {
    return fuelCapacity;
}

//wut?
int Starship::getMissionCount() const {
    return missionLog.size();
}
const std::vector<Mission>& Starship::getMissionLog() const {
    return missionLog;
}

// Adds a mission to the mission log
void Starship::addMission(const Mission& mission) {
    missionLog.push_back(mission);
}
