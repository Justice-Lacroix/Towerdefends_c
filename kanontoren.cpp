// kanontoren.cpp
#include "kanontoren.h"
#include <iostream>
#include <chrono>
#include <thread>
using namespace justice;
kanontoren::kanontoren() : toren("kanonToren", "vuur met kracht", 20, 15, 8, 1, 150, 20)
{
    // Constructorlogica voor kanontoren, indien van toepassing
}

kanontoren::~kanontoren()
{
    // Voeg eventuele logica toe voor de destructor van de kanontorenklasse
}

void kanontoren::schiet(int xgeschoten, int ygeschoten, int xveld, int yveld, int scoretype)
{
    if (xgeschoten == xveld && ygeschoten == yveld) {
        std::cout << soort_vuurwapen+" heeft geraakt op positie (" << xgeschoten << ", " << ygeschoten << ")!\n";
        setScore(scoretype );
        setaantalpijlen();
    }
    else {
        std::cout << "Pijlenboogtoren heeft gemist op positie (" << xgeschoten << ", " << ygeschoten << ")!\n";
        // Voeg hier verdere logica toe voor het geval dat er is gemist
        setaantalpijlen();
    }
   
    std::cout << "Aantal ballen " << Getaantalpijlen() << std::endl; // Print de score na het missen
    std::cout << "Score: " << getScore() << std::endl; // Print de score na het missen
 
    std::this_thread::sleep_for(std::chrono::seconds(5)); // Wacht 5 seconden
}
