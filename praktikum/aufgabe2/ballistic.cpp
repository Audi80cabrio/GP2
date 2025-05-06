#include "ballistic.h"

Ballistic::Ballistic(const std::string& pId, const float pTakeOffAngle, const float pLandingAngle) : Ufo(pId) {
    if (pTakeOffAngle > 0 && pTakeOffAngle <= 90) {
        takeOffAngle = pTakeOffAngle;
    } else {
        takeOffAngle = 45.0f;
    }

    if (pLandingAngle > 0 && pLandingAngle <= 90) {
        landingAngle = pLandingAngle;
    } else {
        landingAngle = 45.0f;
    }
}   

Ballistic::~Ballistic(){
    
}

float Ballistic::getTakeOffAngle() const {
    return takeOffAngle;
}

float Ballistic::getLandingAngle() const {
    return landingAngle;
}

std::vector<float> Ballistic::firstWaypoint(const float x, const float y, const float height) const {
    const auto pos = getPosition();
    return wayPoint(pos[0], pos[1], x, y, height, takeOffAngle);        //wayPoint in ufo.cpp
}

std::vector<float> Ballistic::secondWaypoint(const float x, const float y, const float height) const {
    const auto pos = getPosition();
    return wayPoint(x, y, pos[0], pos[1], height, landingAngle);        //wayPoint in ufo.cpp
}

void Ballistic::flyToDest(const float x, const float y, const float height, const int speed) const {
    const auto first = firstWaypoint(x, y, height);
    const auto second = secondWaypoint(x, y, height);

    sim->flyTo(first[0], first[1], height, speed, speed);
    sim->flyTo(second[0], second[1], height, speed, speed);
    sim->flyTo(x, y, 0.0f, speed, 0);
}