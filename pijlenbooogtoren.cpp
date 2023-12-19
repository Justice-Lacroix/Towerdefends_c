// pijlenboogtoren.cpp
#include "pijlenboogtoren.h"
#include <iostream>
#include "Veld.h"
#include <vector.>
#include <thread>
using namespace justice;
pijlenboogtoren::pijlenboogtoren() : toren("pijlenboog toren", "vuur met precisie", 100, 10, 5, 1, 100, 15)
{
   
}

pijlenboogtoren::~pijlenboogtoren()
{
  // Andere constructorlogica, indien van toepassing// Voeg eventuele logica toe voor de destructor van de pijlenboogtorenklasse
}

void pijlenboogtoren::schiet(int xgeschoten, int ygeschoten, int xveld, int yveld, int scoretype)
{
    if (xgeschoten == xveld && ygeschoten == yveld) {
        std::cout << "Pijlenboogtoren heeft geraakt op positie (" << xgeschoten << ", " << ygeschoten << ")!\n";
        setScore(scoretype);
        std::cout << "Score: " << getScore() << std::endl; // Print de score na het raken
        setaantalpijlen();
    }
    else {
        std::cout << "Pijlenboogtoren heeft gemist op positie (" << xgeschoten << ", " << ygeschoten << ")!\n";
        // Voeg hier verdere logica toe voor het geval dat er is gemist
        std::cout << "Score: " << getScore() << std::endl; // Print de score na het raken
        setaantalpijlen();
    }
    std::cout << "aantal pijlen: " << Getaantalpijlen() << std::endl; // Print de score na het raken
    std::this_thread::sleep_for(std::chrono::seconds(5)); // Wacht 5 seconden
}



    // Pas de grootte van de sprite aan op basis van de grootte van het vens

