// toren.cpp
#include "toren.h"
#include <stdio.h>
using namespace justice;
toren::toren(std::string soort_vuurwapen, std::string tekst, int damage, int aantalpijlen, int bereik, int level, int geld, int health)
    : soort_vuurwapen(soort_vuurwapen), tekst(tekst), damage(damage), aantal_pijlen(aantalpijlen), bereik(bereik), level(level), geld(geld), health(health)
{
   
}

toren::~toren()
{
    // Voeg eventuele logica toe voor de destructor van de torenklasse
}
int toren::getDamage(){
    return damage;
}
void toren::setScore(int scoreType) {
    if (scoreType == 1) {
        score += 10;
    }
    else if (scoreType == 2) {
        score += 20;
    }
    else {
        std::cerr << "Ongeldige scoreType-waarde\n";
    }
}
void toren::setaantalpijlen()
{
    aantal_pijlen = aantal_pijlen - 1;
}
