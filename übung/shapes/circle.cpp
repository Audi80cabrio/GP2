#include "circle.h"
#include <cmath>

#ifndef M_PI
#define M_PI 3.14159
#endif

Circle::Circle(float pradius){
    radius = pradius;
}

float Circle::area() const{
    float res = radius * radius * M_PI; 
    return res;
}