#pragma once 
#include "ufo.h"
#include "ufosim.h"
#include <string>

class Ballistic : public Ufo {

private:

    float takeOffAngle;
    float landingAngle;


public:

    std::vector<float> firstWaypoint(const float x, const float y,const float height) const;
    std::vector<float> secondWaypoint(const float x, const float y,const float height) const;
    
    void flyToDest(const float x, const float y,const float height,const int speed) const override;

    float getTakeOffAngle() const;
    float getLandingAngle() const;

    Ballistic(const std::string& pId,const float pTakeOffAngle,const float pLandingAngle);
    ~Ballistic();

};