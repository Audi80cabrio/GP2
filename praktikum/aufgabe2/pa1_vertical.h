#ifndef VERTICAL_H
#define VERTICAL_H

#include <string>
#include <vector>
#include "ufosim.h"

class Vertical {
private:
    std::string id;
    Ufosim* sim;

public:
    Vertical(const std::string& pId);
    virtual ~Vertical();

    const std::string& getId() const;
    std::vector<float> getPosition() const;
    float getFtime() const;
    virtual void flyToDest(const float x, const float y, const float height, const int speed) = 0;
    static std::vector<float> wayPoint(const float x1, const float y1, const float x2, const float y2, const float h, const float phi);
};

#endif
