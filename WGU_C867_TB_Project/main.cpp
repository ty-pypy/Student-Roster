#include <iostream>
#include <string>

#include "degree.hpp"
#include "student.hpp"
#include "roster.hpp"

using namespace std;


int main() {
    cout << "C867 - Scripting and Programming Applications, ";
    cout << "C++, 001326587, Tyler Brown\n\n";
    
    //Comma delimited inforamation to be used to create a roster of students
    const string studentData[] = {
        "A1,John,Smith,John1989@gm ail.com,20,30,35,40,SECURITY",
        "A2,Suzan,Erickson,Erickson_1990@gmailcom,19,50,30,40,NETWORK",
        "A3,Jack,Napoli,The_lawyer99yahoo.com,19,20,40,33,SOFTWARE",
        "A4,Erin,Black,Erin.black@comcast.net,22,50,58,40,SECURITY",
        "A5,Tyler,Brown,tbro909@students.wgu.edu,25,7,27,42,SOFTWARE"
        };
    
    //Declare the roster
    Roster classRoster;
    
    //Parse the information from the above array into Student objects that fill the Roster
    for (int i = 0; i < Roster::arraySize; ++i) {
        classRoster.parseStud(studentData[i]);
    }
    
    //Printing all Students in the Roster
    classRoster.printAll();
    
    //Printing any invalid emails, if there are any
    classRoster.printInvalidEmails();
    
    //Prints the average amount of days remaining for the three classes for a Student
    for (int i = 0; i < Roster::arraySize; i++) {
        classRoster.printAverageDaysInCourse(classRoster.classRosterArray[i]->getStudentID());
    }
    
    //Printing Student information for students with specified degree type
    classRoster.printByDegreeProgram(SOFTWARE);
    
    //Removing specific Student from the Roster based on their ID
    classRoster.remove("A3");
    
    //Printing all Students in the Roster again
    classRoster.printAll();
    
    //Removing specific Student from the Roster based on their ID
    classRoster.remove("A3");
    
    return 0;
    
}
