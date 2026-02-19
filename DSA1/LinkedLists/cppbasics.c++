//A constructor is a special function that:
//Has the same name as the class
//Has no return type
//Runs automatically when object is created



#include <iostream>
using namespace std;

class Student {
public:
    int id;

    Student() {      // Constructor
        id = 0;
        cout << "Constructor called\n";
    }
};
int main() {
    Student s;   // Constructor runs automatically
}

