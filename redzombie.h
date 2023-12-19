#pragma once
// greenzombie.h
#ifndef redzombie_H
#define redzombie_H
#include "monsters.h"
#include "thread"
namespace justice
{
    class Game;
    class redzombie : public monsters
    {
    public://polymorfisme
        void getShot(int damage); // Aangepaste functie om schade van een toren toe te passen
        redzombie();
        ~redzombie();
    protected:
        void talk();

        friend class Game;
    };
}
#endif // GREENZOMBIE_H
