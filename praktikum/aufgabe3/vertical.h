#pragma once

#include "ufosim.h"
#include "ufo.h"
#include <string>
#include <vector>

class Vertical : public Ufo {
public:
    Vertical(const std::string& pId);
    virtual ~Vertical();
    void flyToDest(const float x, const float y, const float height, const int speed) const override;
    static float distance(const float x1, const float y1, const float x2, const float y2, const float h);
};
