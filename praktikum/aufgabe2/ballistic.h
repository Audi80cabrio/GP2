#include <string>
#include "ufosim.h"
#include "ufo.h"

class Ballistic: public Ufo{
    private:
        float takeOffAngle;
        float landingAngle;
    public:
        Ballistic(const std::string& pId, const float pTakeOffAngle, const float pLandingAngle);        //constructor
        ~Ballistic();       //destructor

        float getTakeOffAngle() const;
        float getLandingAngle() const;
};