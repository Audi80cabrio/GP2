#include "rect.h"

Rectangle::Rectangle(float pwidth, float pheight){
    width = pwidth;
    height = pheight;
}

float Rectangle::area() const{
    float res = width * height;
    return res;
}