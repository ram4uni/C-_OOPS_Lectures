#include <iostream>
using namespace std;

// Hybrid inheritance is a combination of two or more types of inheritance (e.g., single, multiple, hierarchical, etc.).
//----------------------------------------------------------------
// -------------- Example 01 ======================================
//----------------------------------------------------------------

#include <iostream>
using namespace std;

// Base class
class Animal {
public:
    void eat() {
        cout << "Animal is eating." << endl;
    }
};

// Derived class 1 (Single Inheritance)
class Dog : public Animal {
public:
    void bark() {
        cout << "Dog is barking." << endl;
    }
};

// Derived class 2 (Hierarchical Inheritance)
class Cat : public Animal {
public:
    void meow() {
        cout << "Cat is meowing." << endl;
    }
};

// Derived class 3 (Hybrid Inheritance)
class Puppy : public Dog {
public:
    void cry() {
        cout << "Puppy is crying." << endl;
    }
};

int main() {
    Puppy p;
    p.eat();  // From Animal (Single Inheritance)
    p.bark(); // From Dog (Single Inheritance)
    p.cry();  // From Puppy

    Cat c;
    c.eat();  // From Animal (Hierarchical Inheritance)
    c.meow(); // From Cat

    return 0;
}




//----------------------------------------------------------------
// -------------- Example 02 ======================================
//----------------------------------------------------------------

#include <iostream>
using namespace std;

// Base class 1
class A {
public:
    void displayA() {
        cout << "Class A" << endl;
    }
};

// Base class 2
class B {
public:
    void displayB() {
        cout << "Class B" << endl;
    }
};

// Derived class 1 (Multilevel Inheritance)
class C : public A {
public:
    void displayC() {
        cout << "Class C" << endl;
    }
};

// Derived class 2 (Hybrid Inheritance)
class D : public C, public B {
public:
    void displayD() {
        cout << "Class D" << endl;
    }
};

int main() {
    D d;
    d.displayA(); // From A (Multilevel Inheritance)
    d.displayB(); // From B (Multiple Inheritance)
    d.displayC(); // From C (Multilevel Inheritance)
    d.displayD(); // From D

    return 0;
}



//----------------------------------------------------------------
// -------------- Example 03 ======================================
//----------------------------------------------------------------

#include <iostream>
using namespace std;

// Base class
class Animal {
public:
    void eat() {
        cout << "Animal is eating." << endl;
    }
};

// Derived class 1 (Single Inheritance)
class Dog : public Animal {
public:
    void bark() {
        cout << "Dog is barking." << endl;
    }
};

// Derived class 2 (Hierarchical Inheritance)
class Cat : public Animal {
public:
    void meow() {
        cout << "Cat is meowing." << endl;
    }
};

// Derived class 3 (Hybrid Inheritance)
class Puppy : public Dog {
public:
    void cry() {
        cout << "Puppy is crying." << endl;
    }
};

int main() {
    Puppy p;
    p.eat();  // From Animal (Single Inheritance)
    p.bark(); // From Dog (Single Inheritance)
    p.cry();  // From Puppy

    Cat c;
    c.eat();  // From Animal (Hierarchical Inheritance)
    c.meow(); // From Cat

    return 0;
}



//----------------------------------------------------------------
// -------------- Game Context - 01 ==============================
//----------------------------------------------------------------

#include <iostream>
using namespace std;

// Base class for all characters
class Character {
public:
    void move() {
        cout << "Character moves!" << endl;
    }
};

// Base class for weapons
class Weapon {
public:
    void attack() {
        cout << "Weapon attacks!" << endl;
    }
};

// Derived class for a Warrior
class Warrior : public Character {
public:
    void slash() {
        cout << "Warrior slashes!" << endl;
    }
};

// Derived class for a Mage
class Mage : public Character {
public:
    void castSpell() {
        cout << "Mage casts a spell!" << endl;
    }
};

// Derived class for a WarriorMage (inherits from Warrior and Mage)
class WarriorMage : public Warrior, public Mage {
public:
    void specialAbility() {
        cout << "WarriorMage uses a special ability!" << endl;
    }
};

int main() {
    WarriorMage wm;
    wm.move();         // From Character (via Warrior)
    wm.slash();        // From Warrior
    wm.castSpell();    // From Mage
    wm.specialAbility(); // From WarriorMage

    return 0;
}




//----------------------------------------------------------------
// -------------- Game Context - 02 ==============================
//----------------------------------------------------------------


#include <iostream>
using namespace std;

// Base class for all vehicles
class Vehicle {
public:
    void drive() {
        cout << "Vehicle is driving!" << endl;
    }
};

// Base class for power-ups
class PowerUp {
public:
    void activate() {
        cout << "Power-up activated!" << endl;
    }
};

// Derived class for a Car
class Car : public Vehicle {
public:
    void honk() {
        cout << "Car honks!" << endl;
    }
};

// Derived class for a Bike
class Bike : public Vehicle {
public:
    void ringBell() {
        cout << "Bike rings bell!" << endl;
    }
};

// Derived class for a PowerCar (inherits from Car and PowerUp)
class PowerCar : public Car, public PowerUp {
public:
    void turboBoost() {
        cout << "PowerCar uses turbo boost!" << endl;
    }
};

int main() {
    PowerCar pc;
    pc.drive();      // From Vehicle (via Car)
    pc.honk();       // From Car
    pc.activate();   // From PowerUp
    pc.turboBoost(); // From PowerCar

    return 0;
}