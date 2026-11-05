// Brian Foster Coding 1 Fall 2026
// headers

#include "robot.hpp"
#include <iostream>
#include <string>
using namespace std;

int main() {
    setup();
    robot artoo;        // "new robot"
    artoo.status();     // my name is...

    // create a new robot iwth a random charge
    robot baymax("Baymax", dieRoll());
    baymax.status();

    // creating a vector of places
    vector<string> places;
    places.push_back("Rome");
    places.push_back("London");
    places.push_back("Belize");

    cout << "Someday i want to go to ";
    cout << randomElement(places) << ".\n";

    vector<robot> bots;
    for(int i = 0; i < 10; i++) {
        bots.push_back(robot(randomElement(places), dieRoll()));
    }

    cout << "Lets go talk to ...\n";
    randomElement(bots).status();



    return 0;
}