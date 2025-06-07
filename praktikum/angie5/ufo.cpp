#include "ufo.h"
#include <cmath>

#ifndef M_PI
#define M_PI 3.14159265358979323846     //falls pi nicht geht
#endif

Ufo::Ufo(const std::string& pId)
{
    id = pId;
    Ufosim::setSpeedup(4);      // Simulation wird beschleunigt
    sim = new Ufosim();
}

Ufo::~Ufo()
{
    delete sim;
}

const std::string& Ufo::getId() const
{
    return id;
}

std::vector<float> Ufo::getPosition() const
{
    return {sim->getX(), sim->getY(), sim->getZ()};
}

float Ufo::getFtime() const
{
    return sim->getFtime();
}


std::vector<float>Ufo::wayPoint(const float x1,const float y1,const float x2,const float y2,const float h,const float phi)
{
    
    float xx = x2 - x1;
    float yy = y2 - y1;
    float lenge = std::sqrt(xx * xx + yy * yy);

    if (lenge == 0.0) return {x1, y1}; // Sonderfall: AD = 0

    xx /= lenge;
    yy /= lenge;

    float phir = phi * (M_PI / 180.0f);
    float distanz = h / std::tan(phir);

    // Berechne Punkt B entlang der Richtung AD
    float x = x1 + xx * distanz;
    float y = y1 + yy * distanz;

    return {x, y};
}
