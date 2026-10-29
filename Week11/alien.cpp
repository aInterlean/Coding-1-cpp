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

vector<string> planets = {"Earth", "Alderaan", "Sol", "Mars"};

// Alien
class Alien {
public:
    // limbCount
    int limbCount;
    // canFly
    // threatLevel
    // homePlanet
    string homePlanet;

    // Constructor (will randomize all data members)
    Alien() {
        limbCount = rand() % 4 + 2;
        homePlanet = planets[rand() % planets.size()];
    }
    // Constructor (will accept custom values)
    // Contact() (do they come in peace? Where do they come from?)
    // Depart() (how do they leave - walking or flying?) 


};

int main() {
    srand(time(0));
    cout << "Lets meet some aliens!\n";

    Alien jimbo;
    cout << "Hello, I am from " << jimbo.homePlanet << ".\n";
    cout << "this weird critter has " << jimbo.limbCount << " limbs!\n";
}