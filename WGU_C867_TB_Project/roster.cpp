#include <iostream>
#include <string>

#include "student.hpp"
#include "roster.hpp"

using namespace std;

//Parses the information in the argument and creates a new Student object with parsed
//information that is added to the class roster
void Roster::parseStud(string studRow) {
    size_t beforeC;
    size_t afterC;

    string inID ="";
    string inFirst = "";
    string inLast = "";
    string inEmail = "";
    int inAge = 0;
    int inClass1 = 0;
    int inClass2 = 0;
    int inClass3 = 0;
    int inClasses[3];
    string inDegree = "";
    DegreeProgram inEnumDegree = SECURITY;
    
    if (lastIndex < arraySize) {
          lastIndex++;
        
        //Create a new Student at index = lastIndex
        classRosterArray[lastIndex] = new Student (inID, inFirst, inLast, inEmail, inAge, inClass1, inClass2, inClass3, inEnumDegree);
    
        //Get Student ID
        beforeC = studRow.find(",");
        inID = studRow.substr(0, beforeC);
        
        //Get Student First Name
        afterC = beforeC + 1;
        beforeC = studRow.find(",", afterC);
        inFirst = studRow.substr(afterC, beforeC - afterC);
        
        //Get Student Last Name
        afterC = beforeC + 1;
        beforeC = studRow.find(",", afterC);
        inLast = studRow.substr(afterC, beforeC - afterC);
        
        //Get Student Email Address
        afterC = beforeC + 1;
        beforeC = studRow.find(",", afterC);
        inEmail = studRow.substr(afterC, beforeC - afterC);
        
        //Get Student Age
        afterC = beforeC + 1;
        beforeC = studRow.find(",", afterC);
        inAge = stoi(studRow.substr(afterC, beforeC - afterC));
        
        //Get Class 1 and add it to array of class end dates
        afterC = beforeC + 1;
        beforeC = studRow.find(",", afterC);
        inClass1 = stoi(studRow.substr(afterC, beforeC - afterC));
        inClasses[0] = inClass1;
        
        //Get Class 2 and add it to array of class end dates
        afterC = beforeC + 1;
        beforeC = studRow.find(",", afterC);
        inClass2 = stoi(studRow.substr(afterC, beforeC - afterC));
        inClasses[1] = inClass2;
        
        //Get Class 3 and add it to array of class end dates
        afterC = beforeC + 1;
        beforeC = studRow.find(",", afterC);
        inClass3 = stoi(studRow.substr(afterC, beforeC - afterC));
        inClasses[2] = inClass3;
        
        //Get Degree Type
        afterC = beforeC + 1;
        beforeC = studRow.find(",", afterC);
        inDegree = studRow.substr(afterC, beforeC - afterC);
        if (inDegree == "SECURITY") {
            inEnumDegree = SECURITY;
        }
        else if (inDegree == "NETWORK") {
            inEnumDegree = NETWORK;
        }
        else {
            inEnumDegree = SOFTWARE;
        }
    
        //Call the add function to set each private variable for the new Student
        add(inID, inFirst, inLast, inEmail, inAge, inClass1, inClass2, inClass3, inEnumDegree);
    }
}

//Adds the parsed data to the private variables of the Student object via the setters/mutators
void Roster::add(string studentID, string firstName, string lastName, string emailAddress, int age, int daysInCourse1, int daysInCourse2, int daysInCourse3, DegreeProgram degreeProgram) {
    
    if (classRosterArray[lastIndex]->getStudentID() == "") {
        classRosterArray[lastIndex]->setStudentID(studentID);
    }
    if (classRosterArray[lastIndex]->getFirstName() == "") {
        classRosterArray[lastIndex]->setFirstName(firstName);
    }
    if (classRosterArray[lastIndex]->getLastName() == "") {
        classRosterArray[lastIndex]->setLastName(lastName);
    }
    if (classRosterArray[lastIndex]->getEmail() == "") {
        classRosterArray[lastIndex]->setEmail(emailAddress);
    }
    if (classRosterArray[lastIndex]->getAge() == 0) {
        classRosterArray[lastIndex]->setAge(age);
    }
    if (classRosterArray[lastIndex]->getDaysLeft()) {
        classRosterArray[lastIndex]->setDaysLeft(daysInCourse1, daysInCourse2, daysInCourse3);
    }
    if (classRosterArray[lastIndex]->getDegree() == SECURITY) {
        classRosterArray[lastIndex]->setDegree(degreeProgram);
    }
}

//Removes a specific Student object based on the student ID
void Roster::remove (string studentID) {
    bool found = false;
    
    for (int i = 0; i < lastIndex; i++) {
        if (classRosterArray[i]->getStudentID() == studentID) {;
            found = true;
            
            delete classRosterArray[i];
            classRosterArray[i] = classRosterArray[lastIndex];
            lastIndex--;
            cout << "Student with ID: " << studentID << ", removed from roster\n\n\n";
            break;
        }
        else {
            continue;
        }
    }
    if (found == false) {
        cout << "Student with ID: " << studentID << ", not currently in roster\n\n\n";
    }
    
}


//Will loop through the class roster and print out every Student object's information based
//on the Student print() function
void Roster::printAll() {
    cout << "Printing all Students in the Roster:" << endl << endl;
    for (int i = 0; i <= lastIndex; ++i) {
        classRosterArray[i]->print();
        cout << endl;
    }
    cout << endl;
}

//Will take the days remaining in the three courses of a Student object and determine the
//average number of days
void Roster::printAverageDaysInCourse(string studentID) {
    int average = 0;
    int sum = 0;
    
    for (int i = 0; i <= lastIndex; ++i) {
        if (classRosterArray[i]->getStudentID() == studentID) {
            cout << "Calculating the average number of days for Student: ";
            cout << classRosterArray[i]->getStudentID() << endl;
            
            int* arrayForAverage = classRosterArray[i]->getDaysLeft();
            sum = arrayForAverage[0] + arrayForAverage[1] + arrayForAverage[2];
            average = sum / Student::numClasses;
            
            cout << "The average number of days for this student is ";
            cout << average << ".\n";
            break;
            }
        else {
            continue;
        }
    }
    cout << endl;
}


//Will check the email addresses of all Student objects and print any invalid ones
void Roster::printInvalidEmails() {
    cout << "Checking all emails for errors:\n\n";
    for (int i = 0; i <= lastIndex; ++i) {
        if (classRosterArray[i]->getEmail().find("@") != string::npos) {
            if (classRosterArray[i]->getEmail().find(".") != string::npos) {
                if (classRosterArray[i]->getEmail().find(" ") == string::npos) {
                    continue;
                }
                else {
                    cout << "Student: " << classRosterArray[i]->getStudentID();
                    cout << " has an invalid email. ";
                    cout << "Email contains a space (' '): ";
                    cout << classRosterArray[i]->getEmail()<< endl << endl;
                    continue;
                }
            }
            else {
                cout << "Student: " << classRosterArray[i]->getStudentID();
                cout << " has an invalid email. ";
                cout << "Email missing a period ('.'): ";
                cout << classRosterArray[i]->getEmail()<< endl << endl;;
                continue;
            }
        }
        else {
            cout << "Student: " << classRosterArray[i]->getStudentID();
            cout << " has an invalid email. " ;
            cout << "Email missing at sign ('@'): ";
            cout << classRosterArray[i]->getEmail()<< endl << endl;
            continue;
        }
    }
    cout << endl;
}

//Will call the Student objects print() function for each student whose degree type matches
//the degree parameter
void Roster::printByDegreeProgram(DegreeProgram degree) {
    cout << "Printing information for Students with Degree Type: ";
    cout << degreeTypes[degree] << endl << endl;;
    //cout << degreeTypes[degree] << end;
    for (int i = 0; i <= lastIndex; ++i) {
        if (classRosterArray[i]->getDegree() == degree) {
            classRosterArray[i]->print();
            cout << endl;
        }
        else if(classRosterArray[i]->getDegree() == degree) {
            classRosterArray[i]->print();
            cout << endl;
        }
        else if(classRosterArray[i]->getDegree() == degree) {
            classRosterArray[i]->print();
            cout << endl;
        }
        else {
            continue;
        }
        
    }
    cout << endl;
}

//Deconstruction deletes the dynamically allocated memory for the Student pointers in the
//Roster array
Roster::~Roster() {
    for (int i = 0; i <= lastIndex; ++i) {
        delete classRosterArray[i];
    }
    cout << "Destructor called\n\n";
}
