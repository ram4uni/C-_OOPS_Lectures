#include<iostream>
using namespace std;

// ----------------------------------------------
// -------------------  Topic 01 -----------------
// ----------------------------------------------
#include <map>

int main() {
   // Create a dictionary (map) where keys are strings and values are integers
   map<string, int> studentGrades;

   // Adding key-value pairs
   studentGrades["Jack"] = 90;
   studentGrades["James"] = 85;
   studentGrades["Jon"] = 78;

   // Accessing values
   cout << "Jack's Grade: " << studentGrades["Jack"] << endl;

   // Iterating through the map
   cout << "Student Grades:\n";
   for (const auto& sg : studentGrades) {
       cout << sg.first << " -> " << sg.second << endl;
   }

   return 0;
}


// ----------------------------------------------
// -------------------  Topic 02 -----------------
// ----------------------------------------------
#include <unordered_map>

int main() {
    unordered_map<string, int> ages;

    // Adding key-value pairs
    ages["Jack"] = 25;
    ages["James"] = 30;
    ages["Jon"] = 28;

    // Accessing values
    cout << "Jon's Age: " << ages["Jon"] << endl;

    // Iterating through the unordered_map
    cout << "Ages of People:\n";
    for (const auto& people : ages) {
        cout << people.first << " -> " << people.second << endl;
    }

    return 0;
}

// ----------------------------------------------
// -------------------  Topic 02 -----------------
// ----------------------------------------------

#include <iostream>
#include <map>
using namespace std;

int main() {
    map<string, int> studentGrades;    

    // Adding key-value pairs
    studentGrades["Jack"] = 90;
    studentGrades["James"] = 85;
    studentGrades["Jon"] = 78;

    // Accessing elements
    cout << "Jack's Grade: " << studentGrades["Jack"] << endl;
    cout << "Jon's Grade: " << studentGrades["Jon"] << endl;

    map<int, string> studentNames;

    studentNames[1] = "Ram";
    studentNames[2] = "Vish";
    cout << "Student ID 1 : " << studentNames[1] << endl;
    cout << "Student ID 2 : " << studentNames[2] << endl;
  

    map<int, string> employees = { {101, "John"}, {103, "Emma"}, {102, "David"} };

    cout << "Employee List:\n";
    for (const auto& e : employees) {
        cout << "ID: " << e.first << ", Name: " << e.second << endl;
    }


    map<string, int> scores = { {"Alice", 90}, {"Bob", 85}, {"Charlie", 78} };

    string name;
    cout << "Enter student name: ";
    cin >> name;

    // Check if the key exists
    if (scores.find(name) != scores.end()) {
        cout << name << "'s score is: " << scores[name] << endl;
    }
    else {
        cout << name << " not found in the records.\n";
    }

    map<int, string> students = { {101, "Alice"}, {102, "Bob"}, {103, "Charlie"} };

    // Remove a student with ID 102
    students.erase(102);

    // Display the remaining students
    cout << "Students after deletion:\n";
    for (const auto& pair : students) {
       cout << "ID: " << pair.first << ", Name: " << pair.second << endl;
    }



    map<string, int> students = { {"Alice", 90}, {"Bob", 85}, {"Charlie", 78} };

    // Check if "Alice" exists
    if (students.count("Alice") > 0) {
       cout << "Alice exists in the map.\n";
    }
    else {
       cout << "Alice does not exist.\n";
    }



    return 0;
}