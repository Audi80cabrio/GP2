#include "shape.h"

class Circle : public Shape{
    private:
        float radius;
    public:
        Circle(float pradius);
        float area() const override;
};