// ----------------- Topic 01 --------------

#include<iostream>
using namespace std;

// Forward declaration
class Complex;

class Calculator
{
public:
    int add(int a, int b)
    {
        return (a + b);
    }

    int sumRealComplex(Complex, Complex);
    int sumCompComplex(Complex, Complex);
};


class Complex
{
    int a, b;
    // Individually declaring functions as friends
    friend int Calculator::sumRealComplex(Complex, Complex);
    friend int Calculator::sumCompComplex(Complex, Complex);

public:
    void setNumber(int n1, int n2)
    {
        a = n1;
        b = n2;
    }

    void printNumber()
    {
        cout << "Your number is " << a << " + " << b << "i" << endl;
    }
};


int Calculator::sumRealComplex(Complex o1, Complex o2)
{
    return (o1.a + o2.a);
}

int Calculator::sumCompComplex(Complex o1, Complex o2)
{
    return (o1.b + o2.b);
}

int main()
{
    Complex o1, o2;
    o1.setNumber(1, 4);
    o2.setNumber(5, 7);
    Calculator calc;
    int res = calc.sumRealComplex(o1, o2);
    cout << "The sum of real part of o1 and o2 is " << res << endl;
    int resc = calc.sumCompComplex(o1, o2);
    cout << "The sum of complex part of o1 and o2 is " << resc << endl;
    return 0;
}



// -------------------- Topic 02 ---------------------

#include<iostream>
using namespace std;

class Y;

class X {
    int data;
public:
    void setValue(int value) {
        data = value;
    }
    friend void add(X, Y);
};

class Y {
    int num;
public:
    void setValue(int value) {
        num = value;
    }
    friend void add(X, Y);

};

void add(X o1, Y o2) {
    cout << "Summing data of X and Y objects gives me " << o1.data + o2.num;
}

int main() {
    X a1;
    a1.setValue(3);

    Y b1;
    b1.setValue(15);

    add(a1, b1);
    return 0;
}

// ----------- Game Context ----------------------

#include <iostream>
#include <string>
using namespace std;

// Forward declaration of GameManager class
class GameManager;

// Player class
class Player {
private:
    string name;
    int health;
    int score;

public:
    Player(string n, int h, int s) : name(n), health(h), score(s) {}

    // Declare GameManager as a friend class
    friend class GameManager;

    // Public function to display player status
    void displayStatus() const {
        cout << "Player Name: " << name << endl;
        cout << "Health: " << health << endl;
        cout << "Score: " << score << endl;
        cout << "-------------------------" << endl;
    }
};

// GameManager class
class GameManager {
public:
    // Function to reset player's health and score
    void resetPlayer(Player& p) {
        p.health = 100; // Access private member of Player
        p.score = 0;    // Access private member of Player
        cout << "Player has been reset!" << endl;
    }

    // Function to increase player's score
    void increaseScore(Player& p, int points) {
        p.score += points; // Access private member of Player
        cout << points << " points added to player's score!" << endl;
    }
};

int main() {
    // Create a player object
    Player player("Hero", 50, 200);

    // Display initial player status
    cout << "Initial Player Status:" << endl;
    player.displayStatus();

    // Create a GameManager object
    GameManager gameManager;

    // Use GameManager to reset the player
    gameManager.resetPlayer(player);

    // Display player status after reset
    cout << "Player Status After Reset:" << endl;
    player.displayStatus();

    // Use GameManager to increase the player's score
    gameManager.increaseScore(player, 100);

    // Display player status after increasing score
    cout << "Player Status After Increasing Score:" << endl;
    player.displayStatus();

    return 0;
}


// ----------------- Game Context -02 --------------

#include <iostream>
#include <string>
using namespace std;

// Forward declaration of Enemy class
class Enemy;

// Player class
class Player {
private:
    string name;
    int health;

public:
    Player(string n, int h) : name(n), health(h) {}

    // Declare Enemy as a friend class
    friend class Enemy;

    // Public function to display player status
    void displayStatus() const {
        cout << "Player Name: " << name << endl;
        cout << "Health: " << health << endl;
        cout << "-------------------------" << endl;
    }
};

// Enemy class
class Enemy {
public:
    // Function to attack the player
    void attackPlayer(Player& p, int damage) {
        p.health -= damage; // Access private member of Player
        cout << "Player attacked! Health reduced by " << damage << endl;
    }
};

int main() {
    // Create a player object
    Player player("Hero", 100);

    // Display initial player status
    cout << "Initial Player Status:" << endl;
    player.displayStatus();

    // Create an enemy object
    Enemy enemy;

    // Enemy attacks the player
    enemy.attackPlayer(player, 20);

    // Display player status after attack
    cout << "Player Status After Attack:" << endl;
    player.displayStatus();

    return 0;
}

//////// ------ END --------------- //////