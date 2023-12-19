// Game.cpp
#include "Game.h"
#include <iostream>
#include <thread>
#include <chrono>
using namespace justice;

Game::Game() : isGestart(false) {
    // Constructorcode hier

}

Game::~Game() {
    // Destructorcode hier
}
bool Game::getIsGestart() const {
    return isGestart;
}
bool GetValidInput(int& value, const std::string& prompt) {
    while (true) {
        try {
            std::cout << prompt;
            std::cin >> value;

            // Check if the input is a valid number
            if (std::cin.fail()) {
                throw std::invalid_argument("Invalid input. Please enter a number.");
            }

            // If we reach here, the input is valid, so break out of the loop
            return true;
        }
        catch (const std::invalid_argument& e) {
            std::cout << e.what() << std::endl;
            std::cin.clear();  // Clear the error flag
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');  // Ignore the rest of the input
        }
    }
}
void Game::Start() {
    if (!isGestart) {
        printtext();

        int x, y;

        // Get valid input for x and y
        if (GetValidInput(x, "Enter the size of x: ") &&
            GetValidInput(y, "Enter the size of y: ")) {

            veld.MaakEnVulVeldMetGrootte(x, y);

            // Wait until the user chooses a tower
            int monsterkeuze;
            int torenKeuze;
            while (true) {
                std::cout << "Choose a tower:\n";
                std::cout << "1. Pijlenboogtoren\n";
                std::cout << "2. Kanontoren\n";
                std::cin >> torenKeuze;

                if (torenKeuze == 1 || torenKeuze == 2) {
                    break;
                }
                else {
                    std::cout << "Invalid choice. Try again.\n";
                }
            }

            while (true) {
                std::cout << "Choose a monster:\n";
                std::cout << "1. greenzombie, slower but fewer points\n";
                std::cout << "2. redzombie, faster but more points\n";
                std::cin >> monsterkeuze;

                if (monsterkeuze == 1 || monsterkeuze == 2) {
                    break;
                }
                else {
                    std::cout << "Invalid choice. Try again.\n";
                }
            }

            // Place the tower after a valid choice is made
            KiesMonster(monsterkeuze);
            PlaatsToren(torenKeuze);
            isGestart = true;
        }
    }
    // The rest of the code...
}


void Game::Update() {
    while (!isGestart) {
        // Wacht totdat de game is gestart
        std::this_thread::sleep_for(std::chrono::milliseconds(100));
    }

    // De rest van je Update-logica hier

    // Toon het veld
    std::cout << "Het gevulde veld in de game:\n";
    veld.ToonVeld();

    // Laat de gekozen toren schieten

    // Roep de UpdateVeldPeriodiek-functie van Veld aan om het veld periodiek bij te werken
    veld.UpdateVeldPeriodiek(gekozenmonster->getSpeed());
    // veld.ToonVeld(); // Comment deze lijn uit om het veld niet tweemaal te tonen

    // Vraag de gebruiker om x en y
    int x, y;

    // Voer een lus uit totdat de gebruiker geldige getallen invoert
    while (true) {
        std::cout << "Voer de waarde van x in (een cijfer): ";
        std::cin >> x;

        // Controleer of de invoer een geldig getal is
        if (std::cin.fail()) {
            std::cin.clear();  // Clear de foutenstatus
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');  // Negeer de rest van de invoer
            std::cout << "Ongeldige invoer. Voer een cijfer in.\n";
        }
        else {
            break;  // Verlaat de lus als een geldige waarde is ingevoerd
        }
    }

    // Voer een vergelijkbare lus uit voor de waarde van y
    while (true) {
        std::cout << "Voer de waarde van y in (een cijfer): ";
        std::cin >> y;

        // Controleer of de invoer een geldig getal is
        if (std::cin.fail()) {
            std::cin.clear();  // Clear de foutenstatus
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');  // Negeer de rest van de invoer
            std::cout << "Ongeldige invoer. Voer een cijfer in.\n";
        }
        else {
            break;  // Verlaat de lus als een geldige waarde is ingevoerd
        }
    }

    // Voer verdere logica uit met de ingevoerde x en y
    if (gekozenToren) {
        gekozenToren->schiet(x, y, veld.GetLastRandomJ(), veld.GetLastRandomI(), gekozenmonster->getScoreType());
        if (gekozenToren->Getaantalpijlen() == 0) {
            Stop();
            isGestart = false;
        }
    }

    // Toon het veld na het invoeren van x en y
    veld.ToonVeld();
}

void Game::Stop() {
    std::cout << "score is geupdate!\n";
    std::thread sendtext(&Game::sendthreat, this); // Aangepast: gebruik "this" in plaats van een nieuw Game-object
    sendtext.join();

}

void Game::PlaatsToren(int torenKeuze) {
    switch (torenKeuze) {
    case 1:
        std::cout << "Pijlenboogtoren geplaatst!\n";
        gekozenToren = std::make_shared<pijlenboogtoren>();
        // Voeg de logica toe om een pijlenboogtoren te plaatsen op het veld

        break;
    case 2:
        std::cout << "Kanontoren geplaatst!\n";
        gekozenToren = std::make_shared<kanontoren>();
        // Voeg de logica toe om een kanontoren te plaatsen op het veld

    }

}
void Game::KiesMonster(int monsterkeuze) {
    switch (monsterkeuze) {
    case 1:
        std::cout << "greenzombie geplaatst!\n";
        gekozenmonster = std::make_shared<greenzombie>();
        // Voeg de logica toe om een pijlenboogtoren te plaatsen op het veld

        break;
    case 2:
        std::cout << "Kanontoren geplaatst!\n";
        gekozenmonster = std::make_shared<redzombie>();
        // Voeg de logica toe om een kanontoren te plaatsen op het veld

    }
}

inline void Game::SchrijfScoresNaarBestand() {
    // Voeg de gewenste tekst samen
    //gebruik van this 
    std::string threatText = this->playerName + " HEEFT DEZE TOREN GEKOZEN " + gekozenToren->gettekst() +
        " en is voor de " + gekozenmonster->getnaam() + " gegaan, en heeft een score van " +
        std::to_string(gekozenToren->getScore()) + "\n";

    // Open het bestand in append-modus
    std::ofstream scoreBestand("scores.txt", std::ios::app);

    if (scoreBestand.is_open()) {
        scoreBestand << threatText;
        std::cout << "Score is toegevoegd aan scores.txt\n";
    }
    else {
        std::cerr << "Kon scores.txt niet openen voor schrijven.\n";
    }
}
inline void Game::sendthreat() {
    SchrijfScoresNaarBestand();
}

inline void Game::printtext()
{
    std::cout << "hallo,welkom bij het spel , ik zal even de regeld uitleggen.\n je begint met de grote van je veld te kiezen ,\n als je de x en de y van je veld hebt gekozen.\n dan ga je een toren kiezen , hier zit een klein versvhilletje , bij de pijlenboogtoren krijg je 10 pijlen bij de kanontoren 15 ballen.\n als volgt ga je een monster kiezen , deze zijn wel verschillend,\n als je het groene monster kiest gaat er telkens een seconden een x  laten zien worden op het veld.\n aan jou om hierna de coordinaten van de x op te geven heb je het juist krijg je 10 punten bij als je mist krijg je deze niet.\n bij groen is het verschil dat deze maar een halve second getoond word en als e het juist hebt krijg je 20 punten";
    std::cout << "Voer je naam in: ";

    // Lees de naam in vanuit de console
    std::string playerName;
    std::getline(std::cin, playerName);

    // Doe iets met de ingevoerde naam, bijvoorbeeld opslaan in een klassevariabele
    this->playerName = playerName;

    // Print een begroeting met de ingevoerde naam
    std::cout << "Hallo, " << playerName << "!\n";
}