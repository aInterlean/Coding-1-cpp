// Diego Limon Fall 2026 Coding 1
// Classes

#include <iostream>
#include <string>
using namespace std;

#include <chrono>
#include <thread>

// Classes are custom variables
// They have their own variables and functions
    // named "data members" and "member functions"
    // they also have constructors and destructors
        // which run when the object is created or destroyed

class Robot {
public:
    string name;
    float charge;   // 0 to 1, as a percent

    // creat a constructor
    Robot() {
        cout << "\tA new robot appears!\n";
    }

    // creat a constructor that accepts a name and a charge
    Robot(string givenName, float givenCharge) {
       cout << "\tA new robot appears!\n"; 
       name = givenName;
       charge = givenCharge;
       status();
    }

    void status() {
        cout << "Hello, my name is " << name << ".\n";
        cout << "I have " << charge * 100 << "% battery left.\n";
    }

    void sleep() {
        charge += 0.2f;

        //clamp to ceiling
        if(charge > 1) charge = 1;

        this_thread::sleep_for(2s);

        cout << "After some recharging,\nmy battery level is now ";
        cout << charge * 100 << "%.\n";
    } 

};  // dont forget the semi-colon at the end of the class

    


int main() {
    cout << "Lets learn about Classes!\n";

    Robot rob;  // creating an instance of our class
    // use dot syntax to access the data on the robot
    rob.name = "RB-1";
    rob.charge = .78f;


    // using dot syntac to get the data on the robot.
    cout << "Weve just met " << rob.name << ".\n";
    rob.status();

    cout << "\nLets make another robot!\n";
    Robot baymax("Baymax", 0.2f);

    baymax.sleep();

    // in-class test
    // build while loop that charges up baymax until
    // they are at 100% battery
    while(baymax.charge < 1) {
        baymax.sleep();
    }
}