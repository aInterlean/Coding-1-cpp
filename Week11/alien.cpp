// Diego Limon Fall 2026 Coding 1
// Classes

#include <iostream>
#include <string>
#include <chrono>
#include <thread>
#include <cstdlib>
#include <ctime>
#include <vector>
using namespace std;


class Alien {
private:
    int limbCount;
    bool canFly;
    int threatLevel;
    string homePlanet;

public:

    // Constructor (randomizes all data members)
    Alien() {
        limbCount = rand() % 8 + 2;
        canFly = rand() % 2;
        threatLevel = rand() % 10 + 1;

        string planets[] = {"Mars", "Venus", "Jupiter", "Saturn", "Neptune"};
        homePlanet = planets[rand() % 5];
    }

    // Constructor (accepts custom values)
    Alien(int limbs, bool flying, int threat, string planet) {
        limbCount = limbs;
        canFly = flying;
        threatLevel = threat;
        homePlanet = planet;
    }

    // Contact()
    void Contact() {
        cout << "An alien from " << homePlanet << " has arrived!" << endl;

        if (threatLevel <= 3) {
            cout << "They come in peace!" << endl;
        }
        else {
            cout << "They may be hostile!" << endl;
        }

        cout << "They have " << limbCount << " limbs." << endl;
    }

    // Depart()
    void Depart() {
        if (canFly) {
            cout << "The alien flies away!" << endl;
        }
        else {
            cout << "The alien walks away!" << endl;
        }
    }
};

int main() {
    srand(static_cast<unsigned int>(time(0)));

    // Create a randomly generated alien
    Alien alien1;

    // Create an alien with custom values
    Alien alien2(6, true, 2, "Zorgon");

    cout << "Alien 1:" << endl;
    alien1.Contact();
    alien1.Depart();

    cout << "\nAlien 2:" << endl;
    alien2.Contact();
    alien2.Depart();

    return 0;
}
