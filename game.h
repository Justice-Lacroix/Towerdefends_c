#ifndef GAME_H
#define GAME_H

#include <vector>
#include <memory>
#include "Veld.h"
#include "pijlenboogtoren.h"
#include "toren.h"
#include "kanontoren.h"
#include "monsters.h"
#include "greenzombie.h"
#include "redzombie.h"
#include <fstream>
#include <thread>
#include <string>

namespace justice {

    class Game {
    public:
        // polymorfisme
        Game();
        ~Game();

        void Start();
        void Update();
        void Stop();
        bool IsTorenGekozen() const {
            return gekozenToren != nullptr;
        }
        bool getIsGestart() const; // Declaratie van de getter-functie

    protected:
        // polymorfisme

        void SchrijfScoresNaarBestand();
        std::string playerName;
        Veld veld;
        bool isGestart = false; // Een vlag om te controleren of de game is gestart
        std::shared_ptr<toren> gekozenToren;
        std::shared_ptr<monsters> gekozenmonster;
        void printtext();
        void PlaatsToren(int torenKeuze);
        void sendthreat();
        void KiesMonster(int monster);
        bool IsQuitKeyPressed() const; // Nieuwe functie om te controleren of 'q' is ingedrukt
    };

} // namespace justice

#endif // GAME_H
