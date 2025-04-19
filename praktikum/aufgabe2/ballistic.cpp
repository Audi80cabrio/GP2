#include "ballistic.h"

Ballistic::Ballistic(const std::string& pId, const float pTakeOffAngle, const float pLandingAngle) : Ufo(pId) {

    if(pTakeOffAngle > 0){          //initialization of the takeOfAngle
        if(pTakeOffAngle <= 90){
            takeOffAngle = pTakeOffAngle;
        }
    } else {
        takeOffAngle = 45;
    }

    if(pLandingAngle > 0){          //initialization of the landingAngle
        if(pLandingAngle <= 90){
            landingAngle = pLandingAngle;
        }
    } else {
        landingAngle = 45;
    }
}

Ballistic::~Ballistic(){
    
}