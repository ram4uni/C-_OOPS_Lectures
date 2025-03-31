#include <iostream>
#include <string>
using namespace std;

// Base class
class Student {
protected:
    string name;
    int age;

public:
    Student(string name, int age) : name(name), age(age) {}

    // Virtual function
    virtual void displayDetails() {
        cout << "Name: " << name << ", Age: " << age << endl;
    }
};

// Derived class: Undergraduate
class Undergraduate : public Student {
private:
    string major;

public:
    Undergraduate(string name, int age, string major)
        : Student(name, age), major(major) {
    }

    // Override the virtual function
    void displayDetails() override {
        cout << "Undergraduate Student - Name: " << name << ", Age: " << age << ", Major: " << major << endl;
    }
};

// Derived class: Postgraduate
class Postgraduate : public Student {
private:
    string researchTopic;

public:
    Postgraduate(string name, int age, string researchTopic)
        : Student(name, age), researchTopic(researchTopic) {
    }

    // Override the virtual function
    void displayDetails() override {
        cout << "Postgraduate Student - Name: " << name << ", Age: " << age << ", Research Topic: " << researchTopic << endl;
    }
};

int main() {
    // Create objects of derived classes  

    Undergraduate* undergrad = new Undergraduate("Alice", 20, "Computer Science");
    undergrad->displayDetails();



    Postgraduate postgrad("Bob", 25, "Artificial Intelligence");
    // Use base class pointers to demonstrate polymorphism
    Student* student2 = &postgrad;  
    student2->displayDetails(); 

    delete undergrad;
    delete student2;

    return 0;
}