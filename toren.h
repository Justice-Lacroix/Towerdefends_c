#ifndef TOREN_H
#define TOREN_H

#include <string>
#include <iostream>
#include "Veld.h"
namespace justice
{
    class Game;
    class toren
    {

    protected:
        toren(std::string soort_vuurwapen, std::string tekst, int damage, int aantal_pijlen, int bereik, int level, int geld, int health);

        virtual ~toren();
        virtual void schiet(int x, int y, int xveld, int yveld, int scoretype) = 0;

        int getDamage();


        // de variabelen die een toren moet hebben
        //deze staan op protected omdat deze een keer worden meegegeven en erna nietmeer veranderbaar moeten zijn.
        std::string soort_vuurwapen;
        std::string tekst;

        const int damage;
         int aantal_pijlen;
        const int bereik;
        const int health;
        const int level;
        const int geld ;
        int score = 0; // Scorevariabele toegevoegd
        void setScore(int nieuweScore); // Set-functie voor de score
        int getScore() {
            return score;
        }
        int Getaantalpijlen() {
            return aantal_pijlen;
        }
        void setaantalpijlen(); // Set-functie voor de score
        std::string gettekst() const {
            return soort_vuurwapen;
        }
        friend class Game;
    };
}
#endif // TOREN_H
