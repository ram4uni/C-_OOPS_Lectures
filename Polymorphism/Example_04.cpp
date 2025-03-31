#include <iostream>
#include <string>
using namespace std;

// Base class: GameCharacter
class GameCharacter {
protected:
    string name;

public:
    GameCharacter(string n) : name(n) {}

    // Virtual function for attack
    virtual void attack() {
        cout << name << " attacks!" << endl;
    }

    // Virtual destructor
    virtual ~GameCharacter() {}
};

// Derived class: Warrior
class Warrior : public GameCharacter {
public:
    Warrior(string n) : GameCharacter(n) {}

    // Override the attack function
    void attack() override {
        cout << name << " slashes with a sword!" << endl;
    }
};

// Derived class: Mage
class Mage : public GameCharacter {
public:
    Mage(string n) : GameCharacter(n) {}

    // Override the attack function
    void attack() override {
        cout << name << " casts a fireball!" << endl;
    }
};

// Derived class: Archer
class Archer : public GameCharacter {
public:
    Archer(string n) : GameCharacter(n) {}

    // Override the attack function
    void attack() override {
        cout << name << " shoots an arrow!" << endl;
    }
};

int main() {
    // Create objects of derived classes
    GameCharacter* character1 = new Warrior("Conan");
    GameCharacter* character2 = new Mage("Gandalf");
    GameCharacter* character3 = new Archer("Legolas");

    // Use base class pointers to demonstrate polymorphism
    character1->attack(); // Output: Conan slashes with a sword!
    character2->attack(); // Output: Gandalf casts a fireball!
    character3->attack(); // Output: Legolas shoots an arrow!

    // Clean up
    delete character1;
    delete character2;
    delete character3;

    return 0;
}