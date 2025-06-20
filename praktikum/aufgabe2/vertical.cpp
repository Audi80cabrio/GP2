#include "vertical.h"
#include <cmath>

#ifndef M_PI
#define M_PI 3.14159265358979323846
#endif

Vertical::Vertical(const std::string& pId) : Ufo(pId) {
    Ufosim::setSpeedup(4);
}

Vertical::~Vertical() {}

void Vertical::flyToDest(const float x, const float y, const float height, const int speed) const{
    sim->flyTo(sim->getX(), sim->getY(), height, speed, 0);
    sim->flyTo(x, y, height, speed, 0);
    sim->flyTo(x, y, 0.0f, speed, 0);
}