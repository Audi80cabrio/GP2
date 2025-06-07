#include "ballistic.h"

// konstruktor ballistic → übernimmt id, abhebewinkel und lande-winkel
Ballistic::Ballistic(const std::string& pId,const float ptakeOffAngle,const float plandingAngle) : Ufo(pId) {

    if (ptakeOffAngle <= 0 || ptakeOffAngle > 90) {
        takeOffAngle = 45.0f;      // 45 grad nehmen wenn eingabe nicht gut
    }
    else {
        takeOffAngle = ptakeOffAngle; // sonst eingabe benutzen
    }

    if (plandingAngle <= 0 || plandingAngle > 90) {
        landingAngle = 45.0f;      
    }
    else {
        landingAngle = plandingAngle; 
}
}

Ballistic::~Ballistic() {
}

float Ballistic::getTakeOffAngle() const {
    return takeOffAngle;
}

float Ballistic::getLandingAngle() const {
    return landingAngle;
}

std::vector<float> Ballistic::firstWaypoint(const float x, const float y, const float height) const {
    return wayPoint(getPosition()[0], getPosition()[1], x, y, height, takeOffAngle);
}

std::vector<float> Ballistic::secondWaypoint(const float x, const float y, const float height) const {
    return wayPoint(x, y, getPosition()[0], getPosition()[1], height, landingAngle);
}

// fliegt zum ziel in 3 schritten (start → flug → landen)
void Ballistic::flyToDest(const float x, const float y, const float height, const int speed) const {
    std::vector<float> fwp = firstWaypoint(x, y, height); // 1. sprungpunkt
    std::vector<float> swp = secondWaypoint(x, y, height); // 2. sprungpunkt

    sim->flyTo(fwp[0], fwp[1], height, speed, speed); // flieg zu fwp
    sim->flyTo(swp[0], swp[1], height, speed, speed); // flieg zu swp
    sim->flyTo(x, y, 0.0f, speed, 0); // lande genau auf ziel
}
