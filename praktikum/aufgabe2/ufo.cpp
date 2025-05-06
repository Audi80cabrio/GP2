#include "ufo.h"
#include <cmath>

#ifndef M_PI
#define M_PI 3.14159265358979323846
#endif

Ufo::Ufo(const std::string& pId) : id(pId) {
    Ufosim::setSpeedup(4);
    sim = new Ufosim();
}

Ufo::~Ufo() {
    delete sim;
}

const std::string& Ufo::getId() const {
    return id;
}

std::vector<float> Ufo::getPosition() const {
    return {sim->getX(), sim->getY(), sim->getZ()};
}

float Ufo::getFtime() const {
    return sim->getFtime();
}

std::vector<float> Ufo::wayPoint(const float x1, const float y1, const float x2, const float y2, const float h, const float phi){
    const float dx = x2 - x1;                               //richtung start ziel
    const float dy = y2 - y1;                               //richtung start ziel
    const float len = std::sqrt(dx * dx + dy * dy);         //pythagoras
    const float tan_phi = std::tan(phi * M_PI / 180.0f);    //von grad in radiants, weil std:: tan braucht radians
    const float d = h / tan_phi;                            //horizontaler abstand  
    const float factor = d / len;                           //normierungsfaktor 
    const float x = x1 + factor * dx;                       //neuer punkt
    const float y = y1 + factor * dy;                       //neuer punkt
    return {x, y};                                          //rückgabe von neuem punkt
}