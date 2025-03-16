

// ----------------------------------------------
// -------------------  Example  01 -----------------
// ----------------------------------------------



#include <iostream>
using namespace std;


class Base1 {
protected:
    int base1int;

public:
    void set_base1int(int a)
    {
        base1int = a;
    }
};

class Base2 {
protected:
    int base2int;

public:
    void set_base2int(int a)
    {
        base2int = a;
    }
};

class Base3 {
protected:
    int base3int;

public:
    void set_base3int(int a)
    {
        base3int = a;
    }
};


class Derived : public Base1, public Base2, public Base3
{
public:
    void show() {
        cout << "The value of Base1 is " << base1int << endl;
        cout << "The value of Base2 is " << base2int << endl;
        cout << "The value of Base3 is " << base3int << endl;
        cout << "The sum of these values is " << base1int + base2int + base3int << endl;
    }
};


int main()
{
    Derived harry;
    harry.set_base1int(25);
    harry.set_base2int(5);
    harry.set_base3int(15);
    harry.show();

    return 0;
}


// ----------------------------------------------
// -------------------  Example  02 -----------------
// ----------------------------------------------


#include <iostream>
using namespace std;

// Base class 1
class Animal {
public:
    void eat() {
        cout << "Animal is eating." << endl;
    }
};

// Base class 2
class Bird {
public:
    void fly() {
        cout << "Bird is flying." << endl;
    }
};

// Derived class inheriting from both Animal and Bird
class Bat : public Animal, public Bird {
public:
    void display() {
        cout << "Bat is a flying mammal." << endl;
    }
};

int main() {
    Bat bat;
    bat.eat();    // Inherited from Animal
    bat.fly();    // Inherited from Bird
    bat.display(); // Own method
    return 0;
}

// ----------------------------------------------
// -------------------  Example  03 -----------------
// ----------------------------------------------


#include <iostream>
using namespace std;

// Base class 1
class Vehicle {
public:
    Vehicle() {
        cout << "Vehicle constructor called." << endl;
    }
    void drive() {
        cout << "Vehicle is driving." << endl;
    }
};

// Base class 2
class Boat {
public:
    Boat() {
        cout << "Boat constructor called." << endl;
    }
    void sail() {
        cout << "Boat is sailing." << endl;
    }
};

// Derived class inheriting from both Vehicle and Boat
class AmphibiousVehicle : public Vehicle, public Boat {
public:
    AmphibiousVehicle() {
        cout << "AmphibiousVehicle constructor called." << endl;
    }
    void operate() {
        cout << "AmphibiousVehicle can drive and sail." << endl;
    }
};

int main() {
    AmphibiousVehicle av;
    av.drive();  // Inherited from Vehicle
    av.sail();   // Inherited from Boat
    av.operate(); // Own method
    return 0;
}



// ----------------------------------------------
// --------- Example  - Game Context ------------
// ----------------------------------------------



#include <iostream>
using namespace std;

class FlyingEnemy {
public:
    void fly() {
        cout << "Enemy is flying!" << endl;
    }
};

class FireEnemy {
public:
    void breatheFire() {
        cout << "Enemy breathes fire!" << endl;
    }
};

class Dragon : public FlyingEnemy, public FireEnemy {
public:
    void roar() {
        cout << "Dragon roars loudly!" << endl;
    }
};

int main() {
    Dragon dragon;
    dragon.fly();
    dragon.breatheFire();
    dragon.roar();
    return 0;
}