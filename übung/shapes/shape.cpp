#include <vector>
#include <iostream>

#include "shape.h"
#include "circle.h"
#include "rect.h"

std::vector<Shape*> vektor;

int main(){
    Circle circ = Circle(20.00);
    Rectangle rect = Rectangle(10, 20);
    vektor = {&circ, &rect};
    std::cout << "Fläche vom Kreis: " << vektor[0]->area() << "\n";
    std::cout << "Fläche vom Rechteck: " << vektor[1]->area() << "\n";
}