// Veld.h

#ifndef VELD_H
#define VELD_H

#include <vector>
#include <string>
#include <iostream>
namespace justice
{
    class Game;

    class Veld {
    private:
        Veld();
        ~Veld();

        // Functie om periodieke updates te starten
        void StartPeriodiekeUpdate();

        // Functie om periodieke updates te stoppen
        void StopPeriodiekeUpdate();

        // Functie om veld te maken en te vullen met de opgegeven grootte
        void MaakEnVulVeldMetGrootte(int x, int y);

        // Functie om het veld te tonen
        void ToonVeld();

        // Functie voor periodieke veldupdates
        void UpdateVeldPeriodiek(int speed);

        // Getter voor de veldarray
        const std::vector<std::vector<std::string>>& GetVeldArray() const {
            return veldArray;
        }

        // Getter voor de laatste willekeurige I-index
        int GetLastRandomI() const {
            return lastRandomI;
        }

        // Getter voor de laatste willekeurige J-index
        int GetLastRandomJ() const {
            return lastRandomJ;
        }

        // Functie om een positie tijdelijk te markeren
        void MarkeerPositie(int x, int y);

        // Functie om een gemarkeerde positie te herstellen
        void HerstelGemarkeerdePositie();


        int xGrootte;
        int yGrootte;
        std::vector<std::vector<std::string>> veldArray;
        bool isUpdateGestart; // Houdt bij of periodieke updates zijn gestart
        bool isGemarkeerd; // Variabele om bij te houden of een positie is gemarkeerd
        int gemarkeerdeX;  // Variabele om de gemarkeerde x-positie bij te houden
        int gemarkeerdeY;  // Variabele om de gemarkeerde y-positie bij te houden
        int lastRandomI;
        int lastRandomJ;
        friend class Game;
    };
}
#endif // VELD_H
