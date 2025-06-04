#include "route.h"
#include <algorithm>

Route::Route(float pHeight, std::function<float(const float, const float, const float, const float, const float)> pDist) {
    destinations = new std::vector<std::pair<float, float>>();
    setHeight(pHeight);
    setDist(pDist);
}

//Copy-Konstruktor
Route::Route(const Route& route) {
    height = route.height;
    dist = route.dist;
    destinations = new std::vector<std::pair<float, float>>(*route.destinations);
}

// Move-Konstruktor
Route::Route(Route&& other) noexcept {
    height = other.height;
    dist = std::move(other.dist);  // std::function unterstützt move

    destinations = other.destinations;
    other.destinations = nullptr;  // Quellobjekt entwerten
}


Route::~Route() {
    delete destinations;
}

const std::vector<std::pair<float, float>>& Route::getDestinations() const {
    return *destinations;
}

float Route::getHeight() const {
    return height;
}

void Route::setHeight(const float pHeight) {
    height = pHeight;
}

void Route::setDist(const std::function<float(const float, const float, const float, const float, const float)> pDist) {
    dist = pDist;
}

void Route::add(const float destX, const float destY) {
    destinations->emplace_back(destX, destY);           //schneller als push_back
}

float Route::distance() const {
    if (destinations->empty()) return 0.0f;
    float startX = 0.0f;
    float startY = 0.0f;
    float gesamt = 0.0f;

    // von startpunkt zum ersten ziel
    auto first = (*destinations)[0];
    gesamt += dist(startX, startY, first.first, first.second, height);

    // zwischen den zielen
    for (size_t i = 1; i < destinations->size(); ++i) {
        auto from = (*destinations)[i - 1];
        auto to = (*destinations)[i];
        gesamt += dist(from.first, from.second, to.first, to.second, height);
    }

    // von letztem ziel zurück zum startpunkt
    auto last = destinations->back();
    gesamt += dist(last.first, last.second, startX, startY, height);

    return gesamt;
}


Route Route::shortestRoute() const {        //alle permutationen prüfen und kürzesten weg finden: n!
    if (destinations->empty()) return *this;

    std::vector<std::pair<float, float>> bestOrder = *destinations;
    float minDistance = distance();

    std::vector<std::pair<float, float>> currentOrder = *destinations;
    std::sort(currentOrder.begin(), currentOrder.end());        //sort aus <algorithms> 

    while (std::next_permutation(currentOrder.begin(), currentOrder.end())){
        Route temp(height, dist);
        temp.destinations->assign(currentOrder.begin(), currentOrder.end());
        float d = temp.distance();
        if (d < minDistance) {
            minDistance = d;
            bestOrder = currentOrder;
        }
    }

    Route result(height, dist);
    result.destinations->assign(bestOrder.begin(), bestOrder.end());

    return result;
}