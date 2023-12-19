// Veld.cpp

#include "Veld.h"
#include <iostream>
#include <cstdlib>
#include <thread>
#include <chrono>:
#include <iomanip>// voor de spatie bij het printen
using namespace justice;
Veld::Veld() : isUpdateGestart(false), isGemarkeerd(false) {
    // Default constructor, kan leeg blijven of andere initialisatielogica bevatten
}

Veld::~Veld() {
    StopPeriodiekeUpdate(); // Stop periodieke updates bij het vernietigen van het object
}

void Veld::StartPeriodiekeUpdate() {
    if (!isUpdateGestart) {
        isUpdateGestart = true;

        // Start periodieke updates
        while (isUpdateGestart) {
            UpdateVeldPeriodiek(1000); // Update elke seconde (1000 milliseconden)
            std::this_thread::sleep_for(std::chrono::seconds(1));
        }
    }
}

void Veld::StopPeriodiekeUpdate() {
    isUpdateGestart = false; // Stop de periodieke updates
}

void Veld::MaakEnVulVeldMetGrootte(int x, int y) {
    xGrootte = x;
    yGrootte = y;

    // Maak de 2D-array van strings
    veldArray.resize(x, std::vector<std::string>(y, "|"));
}

void Veld::ToonVeld() {
    system("cls");

    // Print de x-as boven het veld
    std::cout << "    ";
    for (int j = 0; j < yGrootte; ++j) {
        std::cout << std::setw(8) << j;
    }
    std::cout << "\n";

    for (int i = 0; i < xGrootte; ++i) {
        // Print de y-as aan de linkerkant van het veld
        std::cout << std::setw(2) << i << " | ";

        for (int j = 0; j < yGrootte; ++j) {
            if (isGemarkeerd && i == gemarkeerdeX && j == gemarkeerdeY) {
                // Toon een andere weergave voor de gemarkeerde positie (bijv. "x")
                std::cout << std::setw(8) << "x";
            }
            else {
                std::cout << std::setw(8) << veldArray[i][j];
            }
        }
        std::cout << "\n";
    }
}


void Veld::UpdateVeldPeriodiek(int speed) {
    lastRandomI = rand() % xGrootte;
    lastRandomJ = rand() % yGrootte;

    MarkeerPositie(lastRandomI, lastRandomJ);  // Markeer een willekeurige positie
    ToonVeld();
    std::this_thread::sleep_for(std::chrono::milliseconds(speed));  // Wacht 1 seconde
    HerstelGemarkeerdePositie();  // Herstel de gemarkeerde positie naar de oorspronkelijke staat
    ToonVeld();
}

void Veld::MarkeerPositie(int x, int y) {
    isGemarkeerd = true;
    gemarkeerdeX = x;
    gemarkeerdeY = y;
}

void Veld::HerstelGemarkeerdePositie() {
    isGemarkeerd = false;
}
