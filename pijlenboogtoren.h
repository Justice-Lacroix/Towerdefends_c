// pijlenboogtoren.h
#ifndef PIJLENBOOGTOREN_H
#define PIJLENBOOGTOREN_H

#include "toren.h"
namespace justice
{
    class Game;

    class pijlenboogtoren : public toren
    {
    public://polymorfisme
        void setSoortVuurwapen(const std::string& nieuweSoort) {
            soort_vuurwapen = nieuweSoort;
        }
        pijlenboogtoren();
        // Destructor
        ~pijlenboogtoren();
    protected:




        // Constructor met standaardwaarden voor attributen

        virtual void schiet(int xgeschoten, int ygeschoten, int xveld, int yveld, int scoretype) override;
        friend class Game;
    };
}
#endif // PIJLENBOOGTOREN_H
