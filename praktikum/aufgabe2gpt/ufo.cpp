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

std::vector<float> Ufo::wayPoint(const float x1, const float y1, const float x2, const float y2, const float h, const float phi) {
    const float dx = x2 - x1;
    const float dy = y2 - y1;
    const float len = std::sqrt(dx * dx + dy * dy);
    const float tan_phi = std::tan(phi * M_PI / 180.0f);
    const float d = h / tan_phi;
    const float factor = d / len;
    const float x = x1 + factor * dx;
    const float y = y1 + factor * dy;
    return {x, y};
}
