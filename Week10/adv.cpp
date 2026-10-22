// Diego Limon Coding 1 Fall 2026
// Adventure 2.0

// can you get it to compile and say hello?

#include <iostream>
#include <string>       
#include <cstdlib>      // c standard library for rand()
#include <ctime>        // c time for srand (time(0))
using namespace std;        // computer science say dont do this because inefficient


// GLOBAL VARIABLES (accessible by any function)
int health = 10;
int totalGold = 0;
bool debug = true;      // set to false when shipping game



// build a function named DieRoll() that returns a random number between 1 and 6

// type name (input parameters) { code }
// part 2 - add a "max" input variable to allow us to get larger numbers than 6

int DieRoll(int max = 6) {
    return rand() % max + 1;
}

void Encounter() {
    int playerRoll = DieRoll();
    int enemyRoll = DieRoll();
    string input = "";

    if(debug) {
        cout << "playeRoll = " << playerRoll; "\n";
        cout << "enemyRoll = " << enemyRoll; "\n";
    }
}        

cin >> input;

    // if(AskYN("do you wanna go adventuring?"))



int main () {
    // setup
    srand(time(0));     // seed the random number generator

    // cout << rand() % 6 + 1;     //1-6
    cout << "Lets go adventuring!\n";
    int luckyNum = DieRoll();
    cout << "Your lucky number is " << luckyNum << ".\n";

    return 0;
}

