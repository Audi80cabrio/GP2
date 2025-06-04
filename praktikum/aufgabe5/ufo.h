#pragma once

#include "ufosim.h"
#include <string>
#include <vector>

class Ufo {
protected:
    Ufosim* sim;

private:
    std::string id;

public:
    Ufo(const std::string& pId);
    virtual ~Ufo();

    const std::string& getId() const;
    std::vector<float> getPosition() const;
    float getFtime() const;
    virtual void flyToDest(const float x, const float y, const float height, const int speed) const = 0;
    static std::vector<float> wayPoint(const float x1, const float y1, const float x2, const float y2, const float h, const float phi);
};
