#include <iostream>
using namespace std;

// Base class
class Animal {
public:
    // Virtual function
    virtual void speak() {
        cout << "Animal speaks" << endl;
    }
};

// Derived class
class Dog : public Animal {
public:
    // Override the virtual function
    void speak() override {
        cout << "Dog barks" << endl;
    }
};

// Derived class
class Cat : public Animal {
public:
    // Override the virtual function
    void speak() override {
        cout << "Cat meows" << endl;
    }
};

int main() {
    // Base class pointer pointing to derived class objects
    Animal* animal1 = new Dog();
    Animal* animal2 = new Cat();

    // Calls the overridden function based on the actual object type
    animal1->speak(); // Output: Dog barks
    animal2->speak(); // Output: Cat meows

    delete animal1;
    delete animal2;

    return 0;
}