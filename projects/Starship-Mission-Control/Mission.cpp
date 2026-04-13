#include "Mission.h"
#include <chrono>  // ?
#include <iomanip>  // ?
#include <sstream>  // ?
#include <iostream>  // ? 
#include <ctime>

// Constructor initializes start time
Mission::Mission()
    : numRefuelings(0), missionEndStardate(0) {
    missionStartStardate = static_cast<int>(std::time(nullptr));
}

Mission::Mission(int numRefuelings, int start, int end)
    : numRefuelings(numRefuelings), missionStartStardate(start), missionEndStardate(end) {
}

// Returns number of refuelings
int Mission::getNumRefuelings() const {
    return numRefuelings;
}

// Returns mission start time as string
int Mission::getMissionStart() const {
    return missionStartStardate;
}


int Mission::getMissionEnd() const {
    return missionEndStardate;
}

// Ends mission by recording end time
void Mission::endMission() {
    missionEndStardate = static_cast<int>(std::time(nullptr));
}

// Increments refueling count
void Mission::refuel() {
    ++numRefuelings;
}






// Sets the number of refuelings
void Mission::setNumRefuelings(int refuels) {
    numRefuelings = refuels;
}

void Mission::setMissionStart(int start) {
    missionStartStardate = start;
}

void Mission::setMissionEnd(int end) {
    missionEndStardate = end;
}


