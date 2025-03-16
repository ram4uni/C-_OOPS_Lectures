#include <iostream>
using namespace std;


//inheritance allows a class (derived class) to inherit properties and behaviours (methods and attributes) 
//from another class (base class). 
//The syntax and visibility modes determine how the members of the base class are accessed in the derived class.

//----------------------------------------------------------------
// -------------- Public Inheritance  ============================
//----------------------------------------------------------------

class Base {
    public:
        int publicVar;
    protected:
        int protectedVar;
    private:
        int privateVar;
    };
    
    class Derived : public Base {
        // publicVar is public in Derived
        // protectedVar is protected in Derived
        // privateVar is not accessible in Derived
    };
    
//----------------------------------------------------------------
// -------------- Public Inheritance  ============================
// ---------------------- Example ============================
//----------------------------------------------------------------


    #include <iostream>
    using namespace std;
    
    class Base {
    public:
        int publicVar = 10;
    protected:
        int protectedVar = 20;
    private:
        int privateVar = 30;
    };
    
    class Derived : public Base {
    public:
        void display() {
            cout << "Public Var: " << publicVar << endl;      // Accessible
            cout << "Protected Var: " << protectedVar << endl; // Accessible
            // cout << "Private Var: " << privateVar << endl; // Error: Not accessible
        }
    };
    
    int main() {
        Derived obj;
        obj.display();
        cout << "Public Var from main: " << obj.publicVar << endl; // Accessible
        // cout << "Protected Var from main: " << obj.protectedVar << endl; // Error: Not accessible
        return 0;
    }




//----------------------------------------------------------------
// -------------- Protected Inheritance ==========================
//----------------------------------------------------------------

class Base {
    public:
        int publicVar;
    protected:
        int protectedVar;
    private:
        int privateVar;
    };
    
class Derived : protected Base {
    // publicVar is protected in Derived
    // protectedVar is protected in Derived
    // privateVar is not accessible in Derived
};


//----------------------------------------------------------------
// -------------- Protected Inheritance  =========================
// ---------------------- Example ============================
//----------------------------------------------------------------


#include <iostream>
using namespace std;

class Base {
public:
    int publicVar = 10;
protected:
    int protectedVar = 20;
private:
    int privateVar = 30;
};

class Derived : protected Base {
public:
    void display() {
        cout << "Public Var: " << publicVar << endl;      // Accessible (protected in Derived)
        cout << "Protected Var: " << protectedVar << endl; // Accessible
        // cout << "Private Var: " << privateVar << endl; // Error: Not accessible
    }
};

int main() {
    Derived obj;
    obj.display();
    // cout << "Public Var from main: " << obj.publicVar << endl; // Error: Not accessible
    return 0;
}

//----------------------------------------------------------------
// -------------- Private Inheritance ============================
//----------------------------------------------------------------

class Base {
public:
    int publicVar;
protected:
    int protectedVar;
private:
    int privateVar;
};

class Derived : private Base {
    // publicVar is private in Derived
    // protectedVar is private in Derived
    // privateVar is not accessible in Derived
};

//----------------------------------------------------------------
// -------------- Private Inheritance  ============================
// ---------------------- Example ============================
//----------------------------------------------------------------

#include <iostream>
using namespace std;

class Base {
public:
    int publicVar = 10;
protected:
    int protectedVar = 20;
private:
    int privateVar = 30;
};

class Derived : private Base {
public:
    void display() {
        cout << "Public Var: " << publicVar << endl;      // Accessible (private in Derived)
        cout << "Protected Var: " << protectedVar << endl; // Accessible (private in Derived)
        // cout << "Private Var: " << privateVar << endl; // Error: Not accessible
    }
};

int main() {
    Derived obj;
    obj.display();
    // cout << "Public Var from main: " << obj.publicVar << endl; // Error: Not accessible
    return 0;
}

//----------------------------------------------------------------
// -------------- Game Context - 01 ==============================
//----------------------------------------------------------------


#include <iostream>
using namespace std;

// Base class: Character
class Character {
public:
    int health;

    // Constructor
    Character(int h) : health(h) {}

    // Public method to display health
    void displayHealth() {
        cout << "Health: " << health << endl;
    }

protected:
    // Protected method to take damage
    void takeDamage(int damage) {
        health -= damage;
        if (health < 0) health = 0;
        cout << "Took " << damage << " damage! Health is now " << health << endl;
    }

private:
    // Private method to heal (only accessible within Character)
    void heal(int amount) {
        health += amount;
        cout << "Healed " << amount << " points! Health is now " << health << endl;
    }
};

// Derived class: Warrior (public inheritance)
class Warrior : public Character {
public:
    // Constructor
    Warrior(int h) : Character(h) {}

    // Public method to attack
    void attack() {
        cout << "Warrior attacks with a sword!" << endl;
        takeDamage(10); // Accessing protected method from base class
    }
};

// Derived class: Mage (public inheritance)
class Mage : public Character {
public:
    // Constructor
    Mage(int h) : Character(h) {}

    // Public method to cast a spell
    void castSpell() {
        cout << "Mage casts a fireball!" << endl;
        takeDamage(5); // Accessing protected method from base class
    }
};

int main() {
    // Create a Warrior object
    Warrior warrior(100);
    warrior.displayHealth(); // Accessing public method from base class
    warrior.attack();       // Accessing public method from derived class
    warrior.displayHealth();

    // Create a Mage object
    Mage mage(80);
    mage.displayHealth();   // Accessing public method from base class
    mage.castSpell();       // Accessing public method from derived class
    mage.displayHealth();

    // Attempting to access protected/private members (will cause errors)
    // warrior.takeDamage(10); // Error: 'takeDamage' is protected
    // warrior.heal(20);       // Error: 'heal' is private

    return 0;
}


