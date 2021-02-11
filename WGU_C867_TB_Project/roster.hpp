#ifndef roster_hpp
#define roster_hpp

#include <stdio.h>
#include "student.hpp"

using namespace std;

class Roster {
    public:
        const static int arraySize = 5;
        int lastIndex = -1;
        
        //Array of Student pointer objects used for the class roster
        Student* classRosterArray[arraySize];

        //Parses the information in the studRow parameter and creates a new Student object that is added to the class roster
        void parseStud(string studRow);
    
        void add(string studentID, string firstName, string lastName, string emailAddress, int age, int daysInCourse1, int daysInCourse2, int daysInCourse3, DegreeProgram degreeProgram);
        
        //Removes a specific Student object based on the student ID
        void remove (string studentID);
        
        //Will loop through the class roster and print out every Student object's information based on the Student print() function
        void printAll();
    
        //Will take the days remaining in the three courses of a Student object and determine the average number of days
        void printAverageDaysInCourse(string studentID);
    
        //Will check the email addresses of all Student objects and print any invalid ones
        void printInvalidEmails();
    
        //Will call the Student objects print() function for each student whose degree type matches the degree parameter
        void printByDegreeProgram(DegreeProgram degree);
    
        //Deconstruction deletes the dynamically allocated memory for the Student pointers in the Roster array
        ~Roster();

};


#endif /* roster_hpp */
