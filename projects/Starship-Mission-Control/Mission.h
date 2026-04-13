#pragma once

#include <chrono>
#include <optional>
#include <string>

class Mission {
private:
    int numRefuelings;
    int missionStartStardate;
    int missionEndStardate; // 0 indicates an ongoing mission
public:
    Mission();
    Mission(int numRefuelings, int start, int end);

    // Getters
    int getNumRefuelings() const;
    int getMissionStart() const;
    int getMissionEnd() const;

    // Actions
    void endMission();
    void refuel();




    // New setters for deserialization
    void setNumRefuelings(int refuels);
    void setMissionStart(int start);
    void setMissionEnd(int end);
};
