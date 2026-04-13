#pragma once

#include <string>
#include <vector>
#include "Mission.h"

class Starship {
public:
    Starship(int id, const std::string& name, float rate, float capacity);

    // Starship operations
    void startMission();
    void endMission();
    void refuel();

    void addMission(const Mission& mission);

    // Mission cost calculation
    double calculateMissionCost(int missionIndex) const;
    double calculateTotalCost() const;

    // Mission logging
    void printMissionLog() const;

    // Getters
    int getShipID() const;
    std::string getShipName() const;
    float getDailyRate() const;
    float getFuelCapacity() const;
    int getMissionCount() const;
    const std::vector<Mission>& getMissionLog() const;


private:
    int shipID;
    std::string shipName;
    float dailyRate;
    float fuelCapacity;
    std::vector<Mission> missionLog;
};
