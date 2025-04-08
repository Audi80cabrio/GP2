#include "pa1_vertical.h"
#include <cmath>

#ifndef M_PI
#define M_PI 3.14159265358979323846
#endif

Vertical::Vertical(const std::string& pId) : id(pId) {
    Ufosim::setSpeedup(4);
    sim = new Ufosim();
}

Vertical::~Vertical() {
    delete sim;
}

const std::string& Vertical::getId() const {
    return id;
}

std::vector<float> Vertical::getPosition() const {
    return {sim->getX(), sim->getY(), sim->getZ()};
}

float Vertical::getFtime() const {
    return sim->getFtime();
}

std::vector<float> Vertical::wayPoint(const float x1, const float y1, const float x2, const float y2, const float h, const float phi) {
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
