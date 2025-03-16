#include <iostream>
using namespace std;


//ambiguity in inheritance occurs when a derived class inherits from multiple base classes that have members
// with the same name, or when a class inherits from a base class through multiple paths (e.g., in diamond inheritance). 
// This can lead to confusion for the compiler about which member to access. To resolve such ambiguities, 
// C++ provides mechanisms like scope resolution operator (::) and virtual inheritance.

    
//----------------------------------------------------------------
// -------- Ambiguity in Multiple Inheritance ===================
// ---------------------- Example ============================
//----------------------------------------------------------------

#include <iostream>
using namespace std;

class Base1 {
public:
    void display() {
        cout << "Base1 display" << endl;
    }
};

class Base2 {
public:
    void display() {
        cout << "Base2 display" << endl;
    }
};

class Derived : public Base1, public Base2 {
public:
    void show() {
        cout << "Derived show" << endl;
    }
};

int main() {
    Derived obj;
    // obj.display(); // Error: Ambiguity - which display() to call?
    obj.Base1::display(); // Resolve ambiguity using scope resolution
    obj.Base2::display(); // Resolve ambiguity using scope resolution
    obj.show();
    return 0;
}



//----------------------------------------------------------------
// --- Resolving Diamond Ambiguity with Virtual Inheritance ======
// ---------------------- Example ============================
//----------------------------------------------------------------

#include <iostream>
using namespace std;

class Base {
public:
    int value = 10;
};

class Derived1 : virtual public Base {
public:
    void show() {
        cout << "Derived1: " << value << endl;
    }
};

class Derived2 : virtual public Base {
public:
    void show() {
        cout << "Derived2: " << value << endl;
    }
};

class Final : public Derived1, public Derived2 {
public:
    void display() {
        cout << "Final: " << value << endl; // No ambiguity - only one copy of Base
    }
};

int main() {
    Final obj;
    obj.Derived1::show(); // Access Derived1's show()
    obj.Derived2::show(); // Access Derived2's show()
    obj.display();        // Access Final's display()
    return 0;
}


//----------------------------------------------------------------
// -------------- Game Context - 01 ==============================
//----------------------------------------------------------------


#include <iostream>
using namespace std;

// Base class: Warrior
class Warrior {
public:
    void attack() {
        cout << "Warrior attacks with a sword!" << endl;
    }
};

// Base class: Mage
class Mage {
public:
    void attack() {
        cout << "Mage casts a fireball!" << endl;
    }
};

// Derived class: Player (inherits from Warrior and Mage)
class Player : public Warrior, public Mage {
public:
    void useWarriorAttack() {
        // Resolve ambiguity by specifying the base class
        Warrior::attack();
    }

    void useMageAttack() {
        // Resolve ambiguity by specifying the base class
        Mage::attack();
    }
};

int main() {
    Player player;

    // Call specific attack methods
    player.useWarriorAttack(); // Calls Warrior's attack
    player.useMageAttack();    // Calls Mage's attack

    // Directly calling attack() would cause ambiguity
    // player.attack(); // Error: Ambiguous call to 'attack'

    // Resolve ambiguity using scope resolution operator
    player.Warrior::attack(); // Calls Warrior's attack
    player.Mage::attack();    // Calls Mage's attack

    return 0;
}