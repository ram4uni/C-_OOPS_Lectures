#include<iostream>
using namespace std;


// Copy Constructor
//class Number {
//    int a;
//public:
//    Number() {
//        a = 0;
//    }
//
//    Number(int num) {
//        a = num;
//    }
//    // When no copy constructor is found, compiler supplies its own copy constructor
//    Number(Number& obj) {
//        cout << "Copy constructor called!!!" << endl;
//        a = obj.a;
//    }
//
//    void display() {
//        cout << "The number for this object is " << a << endl;
//    }
//};
//
//int main() {
//    Number x, y, z(45), z2;
//    x.display();
//    y.display();
//    z.display();
//
//    Number z1(z); // Copy constructor invoked
//    z1.display();
//
//    z2 = z; // Copy constructor not called
//    z2.display();
//
//    Number z3 = z; // Copy constructor invoked
//    z3.display();
//
//    // z1 should exactly resemble z  or x or y
//
//    return 0;
//}




class Player {
    private:
        string name;
        int health;
        int level;
    
    public:
        // Parameterised constructor
        Player(string playerName, int playerHealth, int playerLevel)
            : name(playerName), health(playerHealth), level(playerLevel) {
            cout << "Parameterised constructor called for " << name << endl;
        }
    
        // Copy constructor
        Player(const Player& other)
            : name(other.name), health(other.health), level(other.level) {
            cout << "Copy constructor called for " << name << endl;
        }
    
        // Display player details
        void display() const {
            cout << "Name: " << name << ", Health: " << health << ", Level: " << level << endl;
        }
    
        // Setter for health 
        void setName(string newName) {
            name = newName;
        }
    
        // Setter for health 
        void setHealth(int newHealth) {
            health = newHealth;
        }
    
        ~Player() {
            cout << "Destructed" << endl;
        }
    
    
    
    };
    
    int main() {
        // Create a player object
        Player player1("Hero", 100, 10);
        player1.display();
    
        // copy constructor used to create a copy of player1
        Player player2(player1);
        player2.display();
    
        // health of player2 modified to demonstrate independence
        player2.setHealth(80);
        player2.setName("Jack");
        cout << "After modifying player2's health and name :" << endl;
        player1.display();
        player2.display();
    
        return 0;
    }