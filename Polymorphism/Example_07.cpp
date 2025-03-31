#include <iostream>
using namespace std;

// Base class with a virtual function
class Animal {
public:
    virtual void speak() = 0; // Pure virtual function
};

// Derived class: Dog
class Dog : public Animal {
public:
    void speak() override {
        cout << "Dog barks" << endl;
    }
};

// Derived class: Cat
class Cat : public Animal {
public:
    void speak() override {
        cout << "Cat meows" << endl;
    }
};

// Function template to call speak() on any Animal type
template <typename T>
void makeAnimalSpeak(T& animal) {
    animal.speak();
}

int main() {
    Dog dog;
    Cat cat;

    makeAnimalSpeak(dog); // Output: Dog barks
    makeAnimalSpeak(cat); // Output: Cat meows

    return 0;
}