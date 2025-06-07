#include "route.h"
#include <algorithm>
#include <limits>

Route::Route(const float pHeight, const std::function<float(float, float, float, float, float)>& pDist): height(pHeight), dist(pDist) {
    // Erzeuge einen neuen, leeren Vektor für Zielkoordinaten (x,y)
    destinations = new std::vector<std::pair<float, float>>();
}

Route::Route(const Route& other): height(other.height), dist(other.dist) {
    // Erzeuge eine tiefe Kopie der Zielkoordinatenliste (deep copy)
    destinations = new std::vector<std::pair<float, float>>(*other.destinations);
}

//bewegender konstruktor - pa5
Route::Route(Route&& other) noexcept
    : destinations(other.destinations),
    height(other.height),
    dist(std::move(other.dist))
{
    other.destinations = nullptr; // Quelle entkoppeln, damit kein doppeltes delete
}


Route::~Route() {
    delete destinations;
}

void Route::add(const float destX, const float destY) {
    destinations->push_back(std::make_pair(destX, destY));
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

void Route::setDist(const std::function<float(float, float, float, float, float)>& pDist) {
    dist = pDist;
}

float Route::distance() const {
    if (destinations->empty()) return 0.0f; // wenn keine ziele vorhanden sind, ist die Gesamtdistanz 0.0

    float gesamtdistanz = 0.0f; // Initialisrung der gesamtdistanz
    float x_start = 0.0f; 
    float y_start = 0.0f; // Startkordinat Beginn der Route bei (0,0)

    for (auto& [x, y] : *destinations) {
        gesamtdistanz += dist(x_start, y_start, x, y, height); // Berechne Entfernung von der aktuellen Position zum nächsten Ziel
        x_start = x; // Neue Startposition für den nechsten Schritt aktualisieren
        y_start = y; // nue Startposition für den nechsten Schritt aktualisie
    }

    gesamtdistanz += dist(x_start, y_start, 0.0f, 0.0f, height); // Rückflug vom letzten Ziel zurück zum Startpunkt
    return gesamtdistanz; // Rückgabe der gesamten Flugstrecke
}

Route Route::shortestRoute() const {
    if (destinations->empty()) return *this; // Wenn keine Ziele vorhanden sind, gibt es keine Optimierung

    std::vector<std::pair<float, float>> sorted = *destinations; // Erstelle eine Kopie der Ziele für die Permutationen
    std::sort(sorted.begin(), sorted.end()); // Sortiere für std::next_permutation (Startbedingung)

    float mingesamtdistanz = std::numeric_limits<float>::infinity(); // Initialisiere minimale Distanz mit unendlich
    std::vector<std::pair<float, float>> optimaler_weg; // ier wird die beste Permutation gespechert

    do {
        float weg = 0.0f;
        float x = 0.0f;
        float  y = 0.0f; // Aktuelle Gesamtdistanz der Permution, Start bei (0,0)
        for (const auto& [neues_x, neues_y] : sorted) {
            weg += dist(x, y, neues_x, neues_y, height); // Berechne Strecke zum näcsten ziel
            x = neues_x; // Neue Position setzen
            y = neues_y; // Neue Position setzen
        }
        weg += dist(x, y, 0.0f, 0.0f, height); // ruückweg zum Startpunkt hinzufügen

        if (weg < mingesamtdistanz) { // Falls aktuelle Permutation kurzer ist als bisher beste
            mingesamtdistanz = weg; // Neue minimale Distanz speichern
            optimaler_weg = sorted; // Optimale Permutation sichern
        }
    } while (std::next_permutation(sorted.begin(), sorted.end())); // Ale Permutationen durchgehen

    Route kurzeste_weg(height, dist); // Neue Route mit gleicher Höhe und Distanzfunktion erzeugen
    kurzeste_weg.destinations = new std::vector<std::pair<float, float>>(optimaler_weg);

    return kurzeste_weg; // Optimierte route zrrückgeben
}
