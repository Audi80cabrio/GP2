#include "ballistic.h"
#include "vertical.h"
#include <iostream>

int main(){
    Vertical *vert = new Vertical("Bernd");
    Ballistic *ball = new Ballistic("Ruediger", 30.0, 60.0);
    std::vector<Ufo*> ufos = {vert, ball};
    std::cout << "0 für vertical 1 für balistic: " << '\n';
    std::string input;
    std::cin >> input;

    if (input == "0"){
        ufos[0]->flyToDest(5.0, 6.0, 8.0, 5);
    } else if(input == "1"){
        ufos[1]->flyToDest(-15.0, 1.5, 8.0, 5);
    } else {
        std::cout << "Da stimmt was ned" << '\n';
    }
}