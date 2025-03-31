#include <iostream>
using namespace std;

// Class template for a Box that can hold any type of value
template <typename T>
class Box {
private:
    T value;

public:
    Box(T v) : value(v) {}

    void display() {
        cout << "Value: " << value << endl;
    }
};

int main() {
    Box<int> intBox(10); // Box for integers
    Box<double> doubleBox(3.14); // Box for doubles
    Box<string> stringBox("Hello, Templates!"); // Box for strings

    intBox.display(); // Output: Value: 10
    doubleBox.display(); // Output: Value: 3.14
    stringBox.display(); // Output: Value: Hello, Templates!

    return 0;
}