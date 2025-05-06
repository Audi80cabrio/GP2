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
        const std::vector<std::pair<float, float>>& getDestinations() const;    // Zielkoordinaten getterrrr
        float getHeight() const;        // Flughöhe getter

        //---Setters---
        void setHeight(const float pHeight);        // Flughöhe setttterrrr
        void setDist(const std::function<float(const float, const float, const float, const float, const float)> pDist);// Distanzfunktion setterr

        void add(float destX, float destY);     // Zielkoordinaten hinzufügen
        float distance() const;
        Route shortestRoute() const; // Kürzeste Route
};