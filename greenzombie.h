// greenzombie.h
#ifndef GREENZOMBIE_H
#define GREENZOMBIE_H
#include "monsters.h"
namespace justice
{
    class greenzombie : public monsters
    {
    public://polymorfisme
        greenzombie();
        ~greenzombie();
        void talk();
        void getShot(int damage); // Aangepaste functie om schade van een toren toe te passen
    };
}
#endif // GREENZOMBIE_H
