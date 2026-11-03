// Diego Limon Coding 1 2026
// Adventure 2.0!

#include <iostream>
#include <string>       
#include <cstdlib>      // c standard library for rand()
#include <ctime>        // c time for srand (time(0))
using namespace std;

// GLOBAL VARIABLES (accessible by any function)
int health = 10;
int totalGold = 0;
bool debug = true;      // set to false when shipping game

// this is asking the player if it wants to continue the game
bool AskYN(string question = "Keep Playing?") {

    string input;
    while(true) {
        cout << question << " (y/n)\n";
        getline(cin, input);    
    
   
        if(input == "y") {
            return true;
        }
        else if(input == "n") {
            return false;
        }
        else {
            cout << "Invalid input. Please type 'y' or 'n'.\n";

        }
    }

}

int DieRoll(int max = 6) {
    return rand() % max + 1;
}

void encounter() {

    // roll dice for player 
    int playerRoll = DieRoll();     // lets pretend its 4
    int enemyRoll = DieRoll();      // lets pretend its 5

    // if player roll is equal or higher 
    if(playerRoll >= enemyRoll) {
        // roll for gold amount and give to player
        int gold = DieRoll(25);
        totalGold = totalGold + gold;

        cout << "You have gained " << gold << " gold!\n";
        cout << "You now have " << totalGold << " gold!\n";

  
    } else {
        // subtract enemy roll from player health. 
        health -= enemyRoll;

        cout << "You have been hit for " << enemyRoll << " damage.\n";
        cout << "Your health is " << health << " !\n";
    }
}

void Ending() {
    if(health > 0) {
        cout << "You win!!!!!\n";
        cout << "You made it out with " << totalGold << " gold!!";
    } else {
        cout << "Your greed lost you " << totalGold << " gold.\n";

    }

}

int main() {
    srand(time(0));

    // greet the player
    cout << "Hello Player!\n";

    
    // start the game loop
    while(health > 0) {
        // ask if they want to go adventuring.
        if(AskYN("Do you want to go adventuring?")) {
            cout << "Lets go Adventuring!\n";
            encounter();
        }
        else {
            cout << "Your loss. ";
            break;
        }
       
    }

    Ending();
}