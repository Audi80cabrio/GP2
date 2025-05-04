#include <vector>
#include <utility>
#include <functional>

class Route {
    private:
        std::vector<std::pair<float, float>>* destinations; // Zielkoordinaten
        float height;                                       // Flughöhe
        std::function<float(float, float, float, float, float)> dist; // Distanzfunktion

    public:
        Route(float pHeight, std::function<float(const float, const float, const float, const float, const float)> pDist);
        Route(const Route& route);
        ~Route();


        //---Getters---
        std::vector<std::pair<float, float>>& getDestinations();    // Zielkoordinaten getterrrr
        float getHeight() const;        // Flughöhe getter

        //---Setters---
        void setHeight(float pHeight);        // Flughöhe setttterrrr
        void setDist(std::function<float(float, float, float, float, float)> pDist);// Distanzfunktion setterr

        void add(float destX, float destY);     // Zielkoordinaten hinzufügen
        float distance() const;
        Route shortestRoute() const; // Kürzeste Route (alle Permutationen prüfen)
};