#include <iostream>
using namespace std;

//----------------------------------------------------------------
// -------------- Example 01 ======================================
//----------------------------------------------------------------
class Base
{
    int data1; // private by default and is not inheritable
public:
    int data2;
    void setData();
    int getData1();
    int getData2();
};

void Base::setData()
{
    data1 = 10;
    data2 = 20;
}

int Base::getData1()
{
    return data1;
}

int Base::getData2()
{
    return data2;
}



class Derived : public Base
{ // Class is being derived publically
    int data3;

public:
    void process();
    void display();
};

void Derived::process()
{
    data3 = data2 * getData1();
}

void Derived::display()
{
    cout << "Value of data 1 is " << getData1() << endl;
    cout << "Value of data 2 is " << data2 << endl;
    cout << "Value of data 3 is " << data3 << endl;
}


int main()
{
    Derived der;
    der.setData();
    der.process();
    der.display();

    der.data2 = 100;

    return 0;
}



//----------------------------------------------------------------
// -------------- Example 02 ======================================
//----------------------------------------------------------------

#include <iostream>
using namespace std;

// Base class
class Person {
protected:
    string name;
public:
    void setName(string n) {
        name = n;
    }
    void displayName() {
        cout << "Name: " << name << endl;
    }
};

// Derived class
class Student : public Person {
private:
    int rollNumber;
public:
    void setRollNumber(int r) {
        rollNumber = r;
    }
    void displayDetails() {
        displayName(); // Inherited from Person
        cout << "Roll Number: " << rollNumber << endl;
    }
};

int main() {
    Student student;
    student.setName("John Doe");
    student.setRollNumber(101);
    student.displayDetails();
    return 0;
}



//----------------------------------------------------------------
// -------------- Example 03 ======================================
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

// Derived class
class Car : public Vehicle {
public:
    void drive() {
        cout << "Car is driving." << endl;
    }
};

int main() {
    Car myCar;
    myCar.start(); // Inherited from Vehicle
    myCar.drive(); // Defined in Car
    return 0;
}



//----------------------------------------------------------------
// -------------- Game Context ======================================
//----------------------------------------------------------------


#include <iostream>
#include <string>
using namespace std;

// Base class: Character
class Character {
protected:
    string name;
    int health;

public:
    Character(string name, int health) : name(name), health(health) {}

    void display() {
        cout << "Name: " << name << ", Health: " << health << endl;
    }

    void takeDamage(int damage) {
        health -= damage;
        if (health < 0) health = 0;
        cout << name << " took " << damage << " damage! Health is now " << health << endl;
    }
};

// Derived class: Warrior (inherits from Character)
class Warrior : public Character {
private:
    int armor;

public:
    Warrior(string name, int health, int armor) : Character(name, health), armor(armor) {}

    void useShield() {
        cout << name << " used a shield! Armor increased by 10." << endl;
        armor += 10;
    }

    void display() {
        Character::display(); // Call base class display
        cout << "Armor: " << armor << endl;
    }
};

int main() {
    // Create a Warrior object
    Warrior warrior("Conan", 100, 20);

    // Display warrior details
    warrior.display();

    // Warrior takes damage
    warrior.takeDamage(30);

    // Warrior uses a shield
    warrior.useShield();

    // Display updated warrior details
    warrior.display();

    return 0;
}