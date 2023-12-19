// greenzombie.cpp
#include "redzombie.h"
#include <iostream>
using namespace justice;
// Constructor
redzombie::redzombie() : monsters(2, true, 500,"red zombie") {}

// Destructor
redzombie::~redzombie() {}

// Implementation of the talk method
void redzombie::talk() {
    std::cout << "Green Zombie says: Braaains!" << std::endl;
}

// Aangepaste getShot-functie om schade van een toren toe te passen
void redzombie::getShot(int damage) {
 
}
