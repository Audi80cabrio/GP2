#include <vector>
#include <algorithm>
#include <utility>
#include <functional>
#include <cmath>
#include "ufo.h"

class Route{

private:
    std::vector<std::pair<float,float>>* destinations;
    float height;
    std::function <float(const float, const float, const float, const float, const float)> dist;

public:
    Route(const float pHeight, const std::function<float(float, float, float, float, float)>& pDist);

    Route(const Route& route);
    Route(Route&& other) noexcept; //Move-Konstruktor
    Route& operator=(Route&& other) noexcept; //Move-Zuweisungsoperator
    ~Route();

    float getHeight() const;
    float distance() const;
    
    void setHeight(const float pHeight);
    void setDist(const std::function<float(float, float, float, float, float)>& pDist); //Rückgabewert + werte die er nimmt
    void add(const float destX,const float destY);

    Route shortestRoute() const ;
    const std::vector<std::pair<float, float>>& getDestinations() const;
;

};
