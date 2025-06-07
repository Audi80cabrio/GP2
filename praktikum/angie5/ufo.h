#pragma once  // sagen compiler: datei nur 1x einbinden

#include <string>
#include <vector>
#include "ufosim.h"

class Ufo {

protected:      // sichtbar auch in kindklassen die erben
    Ufosim* sim; // zeigt auf simulator objekt

private:
    std::string id; 

public:
    static std::vector<float> wayPoint(const float x1, const float y1, const float x2, const float y2, const float h, const float phi);
    float getFtime() const;
    virtual void flyToDest(const float x, const float y, const float height, const int speed) const = 0;
    const std::string& getId() const;
    std::vector<float> getPosition() const;
    
    Ufo(const std::string& pId);
    virtual ~Ufo();
};
