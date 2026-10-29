// Diego Limon Coding 1 Week 11
// Classes - Getters and Setters

#include <iostream>
#include <string>
using namespace std;

// enumerators
// enums are custom variable types 
//      with limited possible values
enum elementalType {FIRE, ICE, CANDY, SLIME};

class minMax {
public:
    int x = 0;
    int y = 10;

    minMax(int min = 0, int max = 10){
        x = min;
        y = max;
    }
};


class enemy  {
private:
    string name;
    int health;
    elementalType element;
    minMax healthMinMax;

public:
    // constructor
    enemy(string n = "Tom", int h = 10, elementalType e = FIRE) {
        name = n;
        health = h;
        element = e;

        minMax temp(0 , 20);
        healthMinMax = temp;

        cout << name << " has arrived!\n";
    }

    void status() {
        cout << "\n[" << name << "; " << health << "]\n";
    }

    // passing the enemy by reference....
    // "target" is now a nickname for the enemy that 
    // was sent to the attack function.
    void Attack(enemy& target) {
        cout << name << " is attacking " << target.name << "!\n";
        target.changeHealth(-(health/2));

        
    }

    // getters return variables, don't have parameters
    int getHealth() {
        return health;
    }

    string getName() {
        return name;
    }

    // setters
    void setName(string givenName) {
        if(givenName.size() > 10) {
            cout << "Name is too long.\n";
    } else {
       name = givenName;

    }
    }

    void setHealth(int givenHealth) {
        health = givenHealth;

        // clamp health to the ceiling of 20
        if(health > healthMinMax.y) {
            health = 20;
        }

        // clamp health to the floor of 0
        if(health <= healthMinMax.x) {
            cout << name << " is dead!\n";
        } else {
            cout << name << " now has " << health << " health.\n";
        }
    }

    void changeHealth(int byAmount = 5) {
        setHealth(health + byAmount);
    }
};

int main() {
    cout << "Getters and setters!\n";

    enemy bob("Bob");
    enemy tom;

    cout << "Let's give tom more health.\n";
    // tom.setHealth(tom.getHealth() + 20);
    tom.changeHealth(20);

    // cout << "Tom has " << tom.getHealth() << " health.\n";

    bob.Attack(tom);
    tom.status();
    tom.Attack(bob);
    bob.status();

    // what am i even doing here...
    // we are trying to change the name of enemy tom
    cout << "Lets crown " << tom.getName() << " as the champion!\n";     // getter
    // toms name changes to champion tom
    // but i cant do that because tom.name is private.
    tom.setName("Champion " + tom.getName());                            // setter
    cout << "All hail " << tom.getName() << "!!!\n";                     // getter

    return 0;
}