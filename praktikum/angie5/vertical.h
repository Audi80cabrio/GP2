#pragma once //Der Compiler sieht die Datei beim zweiten Mal und ignoriert sie einfach 
#include <string>
#include <vector>
#include "ufosim.h"
#include "ufo.h"

class Vertical : public Ufo {

public:
    void flyToDest(const float x, const float y,const float height,const int speed) const override;     //vererbt von ufo
    static float distance(const float x1, const float y1, const float x2, const float y2, const float h);


    // Konstruktor und Destruktor
    Vertical(const std::string& pId);
    virtual ~Vertical(); // destruktor, sorgt für richtiges löschen bei vererbung


};