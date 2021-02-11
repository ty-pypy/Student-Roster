#include <iostream>
#include <string>

#include "student.hpp"

using namespace std;

//Full constructor that will fill in all private information about the Student object
Student::Student(string studID, string studFirst, string studLast,
                 string studEmail, int studAge, int studClass1, int studClass2, int
                 studClass3, DegreeProgram studDegree) {
    studentID = studID;
    firstName = studFirst;
    lastName = studLast;
    email = studEmail;
    age = studAge;
    daysLeft[0] = studClass1;
    daysLeft[1] = studClass2;
    daysLeft[2] = studClass3;
    studentDegree = studDegree;
}

//Define the setters
void Student::setStudentID(string inputStudID) {
    studentID = inputStudID;
}

void Student::setFirstName(string inputFirst) {
    firstName = inputFirst;
}

void Student::setLastName(string inputLast) {
    lastName = inputLast;
}

void Student::setEmail(string inputEmail) {
    email = inputEmail;
}

void Student::setAge(int inputAge) {
    age = inputAge;
}

void Student::setDaysLeft(int inputClass1, int inputClass2, int inputClass3) {
    daysLeft[0] = inputClass1;
    daysLeft[1] = inputClass2;
    daysLeft[2] = inputClass3;
}

void Student::setDegree(DegreeProgram inputDegree) {
    studentDegree = inputDegree;
}


//Define the getters
string Student::getStudentID() {
    return studentID;
}

string Student::getFirstName() {
    return firstName;
}

string Student::getLastName() {
    return lastName;
}

string Student::getEmail() {
    return email;
}

int Student::getAge() {
    return age;
}

int* Student::getDaysLeft() {
    static int daysArrayPtr[numClasses];
    
    for (int i = 0; i < numClasses; ++i) {
        daysArrayPtr[i] = daysLeft[i];
    }
    return daysArrayPtr;
}

DegreeProgram Student::getDegree() {
    return studentDegree;
}


//Print funciton used to print out the information for a specific student object
void Student::print() {
    cout << getStudentID() << "   ";
    cout << "First Name: " << getFirstName() << "   ";
    cout << "Last Name: " << getLastName() << "    ";
    cout << "Student Email Address: " << getEmail() << "    ";
    cout << "Age: " << getAge() << "    ";
    cout << "daysInCourse: {";
    cout << daysLeft[0] << ", " << daysLeft[1] << ", " << daysLeft[2] << "}    ";
    cout << "Degree Program: " << degreeTypes[getDegree()] << endl;
}
