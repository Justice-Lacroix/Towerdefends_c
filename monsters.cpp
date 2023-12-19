// monsters.cpp
#include "monsters.h"
using namespace justice;
monsters::monsters(int scoretype, bool leven, int speed,std::string naam) : scoretype(scoretype), leven(leven), speed(speed),naam(naam) {}

monsters::~monsters() {}

void monsters::talk() {
    std::cout << "Zombie spreekt." << std::endl;
}
int monsters::getSpeed() const {
    return speed;
}

int monsters::getScoreType() const {
    return scoretype;
}

void monsters::getShot(int damage) {
   
}
