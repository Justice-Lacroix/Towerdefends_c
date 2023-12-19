// monsters.h
#ifndef MONSTERS_H
#define MONSTERS_H

#include <string>
#include <iostream>
namespace justice
{
    class Game;
    class monsters
    {
    protected://polymorfisme
        monsters(int scoretype, bool leven, int speed, std::string naam);
        void talk();
        void getShot(int damage); // Nieuwe functie voor het toebrengen van schade
        ~monsters();
        int getSpeed() const; // Getter voor speed
        int getScoreType() const; // Getter voor scoretype
        std::string getnaam() const {
            return naam;
        }

        int speed ;
        int scoretype;
        bool leven;
        std::string naam;
        friend class Game;
    };
}
#endif // MONSTERS_H
