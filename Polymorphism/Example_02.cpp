#include <iostream>
using namespace std;

// Function overloading (compile-time polymorphism)
class Math {
public:
    // Function to add two integers
    int add(int a, int b) {
        return a + b;
    }

    // Function to add three integers
    int add(int a, int b, int c) {
        return a + b + c;
    }

    // Function to add two doubles
    double add(double a, double b) {
        return a + b;
    }
};

int main() {
    Math math;

    // Calls the appropriate overloaded function based on the arguments
    cout << "Sum of 2 and 3: " << math.add(2, 3) << endl; // Output: 5
    cout << "Sum of 2, 3, and 4: " << math.add(2, 3, 4) << endl; // Output: 9
    cout << "Sum of 2.5 and 3.5: " << math.add(2.5, 3.5) << endl; // Output: 6.0

    return 0;
}