#pragma once

#include <string>
#include "ufosim.h"
#include "ufo.h"

class Ballistic : public Ufo {
private:
    float takeOffAngle;
    float landingAngle;
public:
    Ballistic(const std::string& pId, const float pTakeOffAngle, const float pLandingAngle);
    ~Ballistic();

    float getTakeOffAngle() const;
    float getLandingAngle() const;

    std::vector<float> firstWaypoint(const float x, const float y, const float height) const;
    std::vector<float> secondWaypoint(const float x, const float y, const float height) const;
    void flyToDest(const float x, const float y, const float height, const int speed) override;
};
