//A constructor is a special function that:
//Has the same name as the class
//Has no return type
//Runs automatically when object is created



#include <iostream>
using namespace std;


//Example of a constructor
class Student {
public:
    int id;

    Student() {      // Constructor
        id = 0;
        cout << "Constructor called\n";
    }
};
//Example of a Defalt constructor:
class Teacher{
    public:
    string name;
    int id;
    Teacher(){
        name="Part-Time";
        id=0;
        cout << "Default Constructor Called\n";
        cout<<"Name: "<<name<<endl;
        cout<<"ID: "<<id<<endl;
    }
    Teacher(string name,int id){
        this->name=name;
        this->id=id;
        cout << "Parameterized Constructor Called\n";
        cout<<"Name: "<<name<<endl;
        cout<<"ID: "<<id<<endl;
    }
};


class Parents {
public:
    Parents() {
        cout << "Parent Constructor\n";
    }

    ~Parents(){
        cout<<"Parent Destructor\n";
    }
};


int main() {
    Student s; // Constructor runs automatically
    Teacher t; // Constructor runs automatically
    Teacher T1("Salman",508);
}



