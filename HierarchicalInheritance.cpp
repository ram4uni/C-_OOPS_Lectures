#include <iostream>
using namespace std;

//----------------------------------------------------------------
// -------------- Example 01 ======================================
//----------------------------------------------------------------

#include <iostream>
using namespace std;

// Base class
class Shape {
public:
    void display() {
        cout << "This is a shape." << endl;
    }
};

// Derived class 1
class Circle : public Shape {
public:
    void drawCircle() {
        cout << "Drawing a circle." << endl;
    }
};

// Derived class 2
class Rectangle : public Shape {
public:
    void drawRectangle() {
        cout << "Drawing a rectangle." << endl;
    }
};

// Derived class 3
class Triangle : public Shape {
public:
    void drawTriangle() {
        cout << "Drawing a triangle." << endl;
    }
};

int main() {
    Circle c;
    Rectangle r;
    Triangle t;

    c.display(); // Inherited from Shape
    c.drawCircle();

    r.display(); // Inherited from Shape
    r.drawRectangle();

    t.display(); // Inherited from Shape
    t.drawTriangle();

    return 0;
}



//----------------------------------------------------------------
// -------------- Example 02 ======================================
//----------------------------------------------------------------

#include <iostream>
using namespace std;

// Base class
class Vehicle {
public:
    void start() {
        cout << "Vehicle started." << endl;
    }
};

// Derived class 1
class Car : public Vehicle {
public:
    void drive() {
        cout << "Car is driving." << endl;
    }
};

// Derived class 2
class Bike : public Vehicle {
public:
    void ride() {
        cout << "Bike is riding." << endl;
    }
};

// Derived class 3
class Truck : public Vehicle {
public:
    void haul() {
        cout << "Truck is hauling." << endl;
    }
};

int main() {
    Car c;
    Bike b;
    Truck t;

    c.start(); // Inherited from Vehicle
    c.drive();

    b.start(); // Inherited from Vehicle
    b.ride();

    t.start(); // Inherited from Vehicle
    t.haul();

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

// Derived class 1
class Dog : public Animal {
public:
    void bark() {
        cout << "Dog is barking." << endl;
    }
};

// Derived class 2
class Cat : public Animal {
public:
    void meow() {
        cout << "Cat is meowing." << endl;
    }
};

// Derived class 3
class Cow : public Animal {
public:
    void moo() {
        cout << "Cow is mooing." << endl;
    }
};

int main() {
    Dog d;
    Cat c;
    Cow w;

    d.eat(); // Inherited from Animal
    d.bark();

    c.eat(); // Inherited from Animal
    c.meow();

    w.eat(); // Inherited from Animal
    w.moo();

    return 0;
}




//----------------------------------------------------------------
// -------------- Game Context - 01 ==============================
//----------------------------------------------------------------


#include <iostream>
using namespace std;

// Base class
class Weapon {
protected:
    string name;
    int damage;
public:
    Weapon(string n, int d) : name(n), damage(d) {}
    void attack() {
        cout << name << " deals " << damage << " damage!" << endl;
    }
};

// Derived class 1: Sword
class Sword : public Weapon {
public:
    Sword(string n, int d) : Weapon(n, d) {}
    void swing() {
        cout << name << " is swung fiercely!" << endl;
    }
};

// Derived class 2: Bow
class Bow : public Weapon {
public:
    Bow(string n, int d) : Weapon(n, d) {}
    void shoot() {
        cout << name << " shoots an arrow!" << endl;
    }
};

// Derived class 3: Staff
class Staff : public Weapon {
public:
    Staff(string n, int d) : Weapon(n, d) {}
    void castSpell() {
        cout << name << " casts a powerful spell!" << endl;
    }
};

int main() {
    Sword sword("Excalibur", 30);
    Bow bow("Longbow", 20);
    Staff staff("Arcane Staff", 25);

    sword.swing();
    sword.attack();

    bow.shoot();
    bow.attack();

    staff.castSpell();
    staff.attack();

    return 0;
}



//----------------------------------------------------------------
// -------------- Game Context - 02 ==============================
//----------------------------------------------------------------


#include <iostream>
using namespace std;

// Base class
class Character {
protected:
    string name;
    int health;
public:
    Character(string n, int h) : name(n), health(h) {}
    void display() {
        cout << "Name: " << name << ", Health: " << health << endl;
    }
};

// Derived class 1: Player
class Player : public Character {
private:
    int level;
public:
    Player(string n, int h, int l) : Character(n, h), level(l) {}
    void levelUp() {
        level++;
        cout << name << " leveled up to level " << level << "!" << endl;
    }
};

// Derived class 2: Enemy
class Enemy : public Character {
private:
    int damage;
public:
    Enemy(string n, int h, int d) : Character(n, h), damage(d) {}
    void attack() {
        cout << name << " attacked for " << damage << " damage!" << endl;
    }
};

// Derived class 3: NPC (Non-Player Character)
class NPC : public Character {
private:
    string dialogue;
public:
    NPC(string n, int h, string d) : Character(n, h), dialogue(d) {}
    void speak() {
        cout << name << " says: " << dialogue << endl;
    }
};

int main() {
    Player player("Hero", 100, 1);
    Enemy enemy("Goblin", 50, 10);
    NPC npc("Merchant", 200, "Welcome to my shop!");

    player.display();
    player.levelUp();

    enemy.display();
    enemy.attack();

    npc.display();
    npc.speak();

    return 0;
}