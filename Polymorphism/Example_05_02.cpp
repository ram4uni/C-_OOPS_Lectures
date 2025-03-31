#include <iostream>
#include <string>
using namespace std;

class Person {
private:
    string name;
    int age;

public:
    Person(string n, int a) : name(n), age(a) {}

    // Overload the == operator
    bool operator==(const Person& other) {
        return (name == other.name && age == other.age);
    }
};

int main() {
    Person p1("Alice", 25), p2("Alice", 25), p3("Bob", 30);

    if (p1 == p2) {
        cout << "p1 and p2 are the same." << endl; // Output
    }
    else {
        cout << "p1 and p2 are different." << endl;
    }

    if (p1 == p3) {
        cout << "p1 and p3 are the same." << endl;
    }
    else {
        cout << "p1 and p3 are different." << endl; // Output
    }

    return 0;
}