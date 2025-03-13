// ----------- exmaple of Friend Function --------------

#include <iostream>
using namespace std;

class Box {
private:
    int length;

public:
    Box(int l) : length(l) {}

    // Declare friend function
    friend void printLength(Box b);
};

// Define friend function
void printLength(Box b) {
    // Access private member 'length' of Box
    cout << "Length of box: " << b.length << endl;
}

int main() {
    Box box(10);
    printLength(box); // Call friend function
    return 0;
}






// -------------- intro ---------------

#include<iostream>
using namespace std;

class complex {
    int a;
    int b;

public:
    void setData(int v1, int v2) {
        a = v1;
        b = v2;
    }

    void setDataBySum(complex o1, complex o2) {
        a = o1.a + o2.a;
        b = o1.b + o2.b;
    }

    void printNumber() {
        cout << "Your complex number is " << a << " + " << b << "i" << endl;
    }
};

int main() {
    complex c1, c2, c3;
    c1.setData(1, 2);
    c1.printNumber();

    c2.setData(3, 4);
    c2.printNumber();

    c3.setDataBySum(c1, c2);
    c3.printNumber();
    return 0;
}


// ----------- using Friend Functions -----------------------

#include<iostream>
using namespace std;

// 1 + 4i
// 5 + 8i
// -------
// 6 + 12i 
class Complex {
    int a, b;
    friend Complex sumComplex(Complex o1, Complex o2);
public:
    void setNumber(int n1, int n2) {
        a = n1;
        b = n2;
    }

    // Below line means that non member - sumComplex funtion is allowed to do anything with my private parts (members)
    void printNumber() {
        cout << "Your number is " << a << " + " << b << "i" << endl;
    }
};

Complex sumComplex(Complex o1, Complex o2) {
    Complex o3;
    o3.setNumber((o1.a + o2.a), (o1.b + o2.b))        ;
    return o3;
}

int main() {
    Complex c1, c2, sum;
    c1.setNumber(1, 4);
    c1.printNumber();

    c2.setNumber(5, 8);
    c2.printNumber();

    sum = sumComplex(c1, c2);
    sum.printNumber();

    return 0;
}

/* Properties of friend functions
1. Not in the scope of class
2. since it is not in the scope of the class, it cannot be called from the object of that class. c1.sumComplex() == Invalid
3. Can be invoked without the help of any object
4. Usually contans the objects as arguments
5. Can be declared inside public or private section of the class
6. It cannot access the members directly by their names and need object_name.member_name to access any member.

*/

// -------------- based on Gaming example ---------------------

#include <iostream>
#include <string>
using namespace std;

// Player class
class Player {
private:
    string name;
    int health;
    int score;

public:
    Player(string n, int h, int s) : name(n), health(h), score(s) {}

    // Declare standalone function as a friend
    friend void displayPlayerStatus(const Player& p);
};

// Standalone friend function to display player status
void displayPlayerStatus(const Player& p) {
    cout << "Player Name: " << p.name << endl;
    cout << "Health: " << p.health << endl;
    cout << "Score: " << p.score << endl;
    cout << "-------------------------" << endl;
}

int main() {
    // Create a player object
    Player player("Hero", 100, 500);

    // Display player status using the friend function
    cout << "Player Status:" << endl;
    displayPlayerStatus(player);

    // Simulate some game events (e.g., player takes damage and gains score)
    player = Player("Hero", 50, 1200);

    // Display updated player status
    cout << "Updated Player Status:" << endl;
    displayPlayerStatus(player);

    return 0;
}