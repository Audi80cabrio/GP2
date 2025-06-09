#include <string>

class Square{
    private:
        float x;
        float y;
        float length = 0;
        std::string name = "no name";
    public:
        Square(const float x, const float y);
        Square(Square& other);
        float getX() const;
        float getY() const;
        float getLength() const;
        const std::string getName() const;
        void setName(const std::string pname);
        void printSquare() const;
};