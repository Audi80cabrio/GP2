#include <vector>
#include <utility>
#include <functional>

class Route {
private:
    std::vector<std::pair<float, float>>* destinations;
    float height;
    std::function<float(const float, const float, const float, const float, const float)> dist;

public:
    Route(float pHeight, std::function<float(const float, const float, const float, const float, const float)> pDist);
    Route(const Route& route);
    ~Route();

    const std::vector<std::pair<float, float>>& getDestinations() const;
    float getHeight() const;

    void setHeight(const float pHeight);
    void setDist(const std::function<float(const float, const float, const float, const float, const float)> pDist);

    void add(const float destX, const float destY);
    float distance() const;
    Route shortestRoute() const;
};