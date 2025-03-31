#include <iostream>
using namespace std;

// Function template to add two values of any type
template <typename T>
T add(T a, T b) {
    return a + b;
}

int main() {
    cout << "Sum of integers: " << add(3, 5) << endl; // Output: 8
    cout << "Sum of doubles: " << add(3.5, 2.5) << endl; // Output: 6.0

    return 0;
}