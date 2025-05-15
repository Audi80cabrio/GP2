#include "shape.h"

class Rectangle : public Shape {
    private:
        float width;
        float height;
    
    public:
        Rectangle(float pwidth, float pheight);
        float area() const override;
};