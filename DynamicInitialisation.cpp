#include<iostream>
using namespace std;

//----------------------------------------------
// example 01
//----------------------------------------------


class MyClass {
public:
    int value;

    MyClass(int v) {
        value = v;
        cout << "Constructor called! Value: " << value << endl;
    }

    // Destructor
    ~MyClass() {
        cout << "Destructor called! Value: " << value << endl;
    }
};

int main() {
    // Dynamically initialise an object
    MyClass obj(10); // Constructor is called here

    // Access the object's member
    cout << "Value: " << obj.value << endl;

    // Destructor is called automatically when obj goes out of scope
    return 0;
}


//----------------------------------------------
// example 02
//----------------------------------------------


class MyClass {
public:
    int value;

    // Constructor
    MyClass(int v)  {
        value = v;
        cout << "Constructor called! Value: " << value << endl;
    }

    // Destructor
    ~MyClass() {
        cout << "Destructor called! Value: " << value << endl;
    }
};

int main() {
    // Dynamically initialise multiple objects in a loop
    for (int i = 1; i <= 3; ++i) {
        MyClass obj(i); // Constructor is called here for each iteration
        cout << "Value inside loop: " << obj.value << endl;
        // Destructor is called here when obj goes out of scope (end of each iteration)
    }

    return 0;
}

//----------------------------------------------
// example 03 - using Pointers
//----------------------------------------------


class MyClass {
public:
    int value;

    // Constructor
    MyClass(int v)  {
        value = v;
        cout << "Constructor called! Value: " << value << endl;
    }

    // Destructor
    ~MyClass() {
        cout << "Destructor called! Value: " << value << endl;
    }
};

int main() {
    // Dynamically allocate an object using the constructor
    MyClass* obj = new MyClass(10);

    // Access the object's member
    cout << "Value: " << obj->value << endl;

    // Delete the object to free memory
    delete obj;

    return 0;
}

//----------------------------------------------
// example 04 - Mini  Project
//----------------------------------------------


//Dynamic Initialisation of Objects Using Constructors 
class BankDeposit {
    int principal;
    int years;
    float interestRate;
    float returnValue;

public:
    BankDeposit() {}
    BankDeposit(int p, int y, float r); // r can be a value like 0.04
    BankDeposit(int p, int y, int r); // r can be a value like 14
    void show();
};

BankDeposit::BankDeposit(int p, int y, float r)
{
    principal = p;
    years = y;
    interestRate = r;
    returnValue = principal;
    for (int i = 0; i < y; i++)
    {
        returnValue = returnValue * (1 + interestRate);
    }
}

BankDeposit::BankDeposit(int p, int y, int r)
{
    principal = p;
    years = y;
    interestRate = float(r) / 100;
    returnValue = principal;
    for (int i = 0; i < y; i++)
    {
        returnValue = returnValue * (1 + interestRate);
    }
}

void BankDeposit::show() {
    cout << endl << "Principal amount was " << principal
        << ". Return value after " << years
        << " years is " << returnValue << endl;
}


int main() {
    BankDeposit bd1, bd2, bd3;
    int p, y;
    float r;
    int R;


    cout << "Enter the value of p y and r" << endl;
    cin >> p >> y >> r;
    bd1 = BankDeposit(p, y, r);
    bd1.show();

    cout << "Enter the value of p y and R" << endl;
    cin >> p >> y >> R;
    bd2 = BankDeposit(p, y, R);
    bd2.show();
    return 0;
}
