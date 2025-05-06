#include "route.h"
#include <cmath>

//Konstructor Destructor und copy-Constructor
Route::Route(float pHeight, std::function<float(const float, const float, const float, const float, const float)> pDist){
    setHeight(pHeight);
    setDist(pDist);
}

Route::Route(const Route& route) {
    height = route.height;
    dist = route.dist;
    destinations = new std::vector<std::pair<float, float>>(*route.destinations);
}

Route::~Route(){

}

std::function<float(float, float, float, float, float)> dist = 
    [](float x, float y, float z, float x2, float y2) -> float {
        return std::sqrt((x - x2)*(x - x2) + (y - y2)*(y - y2) + z * z);
    };

const std::vector<std::pair<float, float>>& Route::getDestinations() const{
    return *destinations;
}

float Route::getHeight() const{
    return height;
}

void Route::setHeight(const float pHeight){
    height = pHeight;
}

void Route::setDist(const std::function<float(const float, const float, const float, const float, const float)> pDist){
    dist = pDist;
}

void Route::add(const float destX, const float destY){
    std::pair<float, float> newPair = {destX, destY};
    destinations->push_back(newPair);
}

float Route::distance() const {
    if (destinations->empty()) return 0.0f;

    float gesamt = 0.0f;

    float startX = 0.0f;
    float startY = 0.0f;
    float startZ = 0.0f;

    auto first = (*destinations)[0];
    gesamt += dist(first.first, first.second, height, startX, startY);

    for (size_t i = 1; i < destinations->size(); ++i) {
        auto from = (*destinations)[i - 1];
        auto to = (*destinations)[i];
        gesamt += dist(to.first, to.second, height, from.first, from.second);
    }

    auto last = destinations->back();
    gesamt += dist(startX, startY, startZ, last.first, last.second);

    return gesamt;
}

#include <algorithm> // std::next_permutation

Route Route::shortestRoute() const {
    if (destinations->empty()) return *this;

    std::vector<std::pair<float, float>> bestOrder = *destinations;
    float minDistance = distance();

    std::vector<std::pair<float, float>> currentOrder = *destinations;

    // Alle Permutationen durchprobieren
    do {
        Route temp(height, dist);
        for (const auto& p : currentOrder) {
            temp.add(p.first, p.second);
        }

        float d = temp.distance();
        if (d < minDistance) {
            minDistance = d;
            bestOrder = currentOrder;
        }
    } while (std::next_permutation(currentOrder.begin(), currentOrder.end()));

    // Neue Route mit bester Reihenfolge zurückgeben
    Route result(height, dist);
    for (const auto& p : bestOrder) {
        result.add(p.first, p.second);
    }

    return result;
}
