#include <iostream>
using namespace std;


//virtual base classes are used to resolve ambiguity in multiple inheritance 
//when a class inherits from two or more classes that have a common base class. 
//This is known as the "diamond problem". The virtual base class ensures that only 
//one instance of the common base class is shared among the derived classes.

//----------------------------------------------------------------
// -------------- Virtual Base Class =============================
//----------------------------------------------------------------

#include <iostream>
using namespace std;

// Base class
class Base {
public:
    int baseVar;
    Base() {
        baseVar = 100;
        cout << "Base Constructor" << endl;
    }
    void display() {
        cout << "Base Variable: " << baseVar << endl;
    }
};

// Derived1 class (inherits virtually from Base)
class Derived1 : virtual public Base {
public:
    Derived1() {
        cout << "Derived1 Constructor" << endl;
    }
};

// Derived2 class (inherits virtually from Base)
class Derived2 : virtual public Base {
public:
    Derived2() {
        cout << "Derived2 Constructor" << endl;
    }
};

// FinalDerived class (inherits from Derived1 and Derived2)
class FinalDerived : public Derived1, public Derived2 {
public:
    FinalDerived() {
        cout << "FinalDerived Constructor" << endl;
    }
};

int main() {
    FinalDerived obj;

    // Accessing baseVar without ambiguity
    obj.baseVar = 200;
    obj.display(); // Output: Base Variable: 200

    return 0;
}




//----------------------------------------------------------------
// -------------- Game Context - 01 ==============================
//----------------------------------------------------------------
// Without virtual, the Boss class would have two copies of Character (one from Enemy and one from Player),
// leading to ambiguity when accessing Character members.

#include <iostream>
using namespace std;

// Virtual Base Class
class Character {
public:
    int health;
    Character() : health(100) {
        cout << "Character created with health: " << health << endl;
    }
    void takeDamage(int damage) {
        health -= damage;
        cout << "Character took " << damage << " damage. Health: " << health << endl;
    }
};

// Derived class from Character
class Enemy : virtual public Character {
public:
    void attack() {
        cout << "Enemy attacks!" << endl;
    }
};

// Derived class from Character
class Player : virtual public Character {
public:
    void defend() {
        cout << "Player defends!" << endl;
    }
};

// Derived class from both Enemy and Player
class Boss : public Enemy, public Player {
public:
    void specialAttack() {
        cout << "Boss uses a special attack!" << endl;
    }
};

int main() {
    Boss boss;
    boss.attack();       // From Enemy
    boss.defend();       // From Player
    boss.specialAttack(); // From Boss
    boss.takeDamage(20); // From Character (only one instance due to virtual inheritance)

    return 0;
}


//----------------------------------------------------------------
// -------------- Game Context - 02 ==============================
//----------------------------------------------------------------


#include <iostream>
using namespace std;

// Virtual Base Class
class GameObject {
public:
    string name;
    GameObject(string n) : name(n) {
        cout << "GameObject created: " << name << endl;
    }
};

// Derived class from GameObject
class Weapon : virtual public GameObject {
public:
    Weapon(string n) : GameObject(n) {}
    void attack() {
        cout << name << " attacks!" << endl;
    }
};

// Derived class from GameObject
class Character : virtual public GameObject {
public:
    Character(string n) : GameObject(n) {}
    void defend() {
        cout << name << " defends!" << endl;
    }
};

// Derived class from both Weapon and Character
class Player : public Weapon, public Character {
public:
    Player(string n) : GameObject(n), Weapon(n), Character(n) {}
    void specialAbility() {
        cout << name << " uses a special ability!" << endl;
    }
};

int main() {
    Player player("Hero");
    player.attack();       // From Weapon
    player.defend();       // From Character
    player.specialAbility(); // From Player

    return 0;
}