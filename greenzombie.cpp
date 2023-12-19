// greenzombie.cpp
#include "greenzombie.h"
#include <iostream>
using namespace justice;
// Constructor
greenzombie::greenzombie() : monsters(1, true, 1000,"groenezombie") {}

// Destructor
greenzombie::~greenzombie() {}

// Implementation of the talk method
void greenzombie::talk() {
    std::cout << "Green Zombie says: Braaains!" << std::endl;
}

// Aangepaste getShot-functie om schade van een toren toe te passen
void greenzombie::getShot(int damage) {
  
}
