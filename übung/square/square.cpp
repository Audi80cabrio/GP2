#include "square.h"

#include <iostream>

Square::Square(const float px, const float py) {
    if (px <= 0){x = 1;} 
    else{x = px;}

    if (py <= 0){y = 1;}
    else{y = py;}
    return;
}

Square:: Square(Square& other){
    Square(other.x, other.y);
}

float Square::getX() const{
    return x;
}

float Square::getY() const{
    return y;
}

float Square::getLength() const{
    return length;
}

const std::string Square::getName() const {
    return name;
}

void Square::setName(const std::string pname){
    name = pname;
}

void Square::printSquare() const{
    std::cout << "x: " << getX() << '\n';
    std::cout << "y: " << getY() << '\n';
    std::cout << "length: " << getLength() << '\n';
    std::cout << "name: " << getName() << '\n';
}

int main(){
    Square* s1 = new Square(0, 0);
    std::cout << "Square s1 created. data following:" << '\n';
    s1->printSquare();
    
    delete s1;
    return;
}