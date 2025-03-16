#include <iostream>
using namespace std;


// ----------------------------------------------
// -----------------  Example - 01 --------------
// ----------------------------------------------

#include <iostream>
using namespace std;

// Base class
class Animal {
public:
    void eat() {
        cout << "Animal is eating." << endl;
    }
};

// Intermediate class derived from Animal
class Dog : public Animal {
public:
    void bark() {
        cout << "Dog is barking." << endl;
    }
};

// Derived class derived from Dog
class Puppy : public Dog {
public:
    void weep() {
        cout << "Puppy is weeping." << endl;
    }
};

int main() {
    Puppy p;
    p.eat();   // Inherited from Animal
    p.bark();  // Inherited from Dog
    p.weep();  // Defined in Puppy
    return 0;
}

// ----------------------------------------------
// -----------------  Example - 02 --------------
// ----------------------------------------------


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

// Intermediate class derived from Person
class Employee : public Person {
protected:
    int salary;
public:
    void setSalary(int s) {
        salary = s;
    }
    void displaySalary() {
        cout << "Salary: " << salary << endl;
    }
};

// Derived class derived from Employee
class Manager : public Employee {
public:
    void displayDetails() {
        displayName();   // Inherited from Person
        displaySalary(); // Inherited from Employee
        cout << "Role: Manager" << endl;
    }
};

int main() {
    Manager m;
    m.setName("John Doe");
    m.setSalary(50000);
    m.displayDetails();
    return 0;
}

// ----------------------------------------------
// -----------------  Example - 03 --------------
// ----------------------------------------------


class Student
{
protected:
    int roll_number;

public:
    void set_roll_number(int);
    void get_roll_number(void);
};

void Student::set_roll_number(int r)
{
    roll_number = r;
}

void Student::get_roll_number()
{
    cout << "The roll number is " << roll_number << endl;
}


class Exam : public Student
{
protected:
    float maths;
    float physics;

public:
    void set_marks(float, float);
    void get_marks(void);
};

void Exam::set_marks(float m1, float m2)
{
    maths = m1;
    physics = m2;
}

void Exam::get_marks()
{
    cout << "The marks obtained in maths are: " << maths << endl;
    cout << "The marks obtained in physics are: " << physics << endl;
}


class Result : public Exam
{
    float percentage;

public:
    void display_results()
    {
        get_roll_number();
        get_marks();
        cout << "Your result is " << (maths + physics) / 2 << "%" << endl;
    }
};

int main()
{
    Result harry;
    harry.set_roll_number(420);
    harry.set_marks(94.0, 90.0);
    harry.display_results();
    return 0;
}



// ----------------------------------------------
// -------- Example - Game Context 01 -----------
// ----------------------------------------------


#include <iostream>
using namespace std;

// Base class: General character
class Character {
public:
    void move() {
        cout << "Character is moving." << endl;
    }
};

// Intermediate class: Player character
class Player : public Character {
public:
    void attack() {
        cout << "Player is attacking." << endl;
    }
};

// Derived class: Hero character
class Hero : public Player {
public:
    void specialAbility() {
        cout << "Hero uses a special ability!" << endl;
    }
};

int main() {
    Hero hero;
    hero.move();          // Inherited from Character
    hero.attack();        // Inherited from Player
    hero.specialAbility(); // Unique to Hero
    return 0;
}


// ----------------------------------------------
// ------- Example - Game Context 02 ------------
// ----------------------------------------------

#include <iostream>
using namespace std;

// Base class: General enemy
class Enemy {
public:
    void spawn() {
        cout << "Enemy has spawned." << endl;
    }
};

// Intermediate class: Flying enemy
class FlyingEnemy : public Enemy {
public:
    void fly() {
        cout << "Enemy is flying." << endl;
    }
};

// Derived class: Dragon
class Dragon : public FlyingEnemy {
public:
    void breatheFire() {
        cout << "Dragon breathes fire!" << endl;
    }
};

int main() {
    Dragon dragon;
    dragon.spawn();      // Inherited from Enemy
    dragon.fly();        // Inherited from FlyingEnemy
    dragon.breatheFire(); // Unique to Dragon
    return 0;
}