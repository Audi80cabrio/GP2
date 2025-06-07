#include "vertical.h"
#include <cmath>

#ifndef M_PI
#define M_PI 3.14159265358979323846
#endif

Vertical::Vertical(const std::string& pId) : Ufo(pId)
{

}

// destrk. nix zi tun
Vertical::~Vertical()
{

}

#include "vertical.h"
#include <cmath>

float Vertical::distance(const float x1, const float y1, const float x2, const float y2, const float h) {
    float dx = x2 - x1;
    float dy = y2 - y1;
    float ground = std::sqrt(dx * dx + dy * dy);
    return h + ground + h;
}



// Führt einen Flug in drei Schritten aus: 
// 1. Vertikaler Aufstieg auf Zielhöhe
// 2. Horizontaler Flug zur Zielpsoiton auf konstater Höhe
// 3. Vertikaler Abstieg auf Bodenhöhe
void Vertical::flyToDest(const float x,const float y, const float height,const int speed) const
{
    sim->flyTo(sim->getX(), sim->getY(), height, speed, 0);
    sim->flyTo(x, y, height, speed, 0);
    sim->flyTo(x, y, 0.0f, speed, 0);

}
