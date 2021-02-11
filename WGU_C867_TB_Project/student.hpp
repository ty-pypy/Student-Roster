#ifndef student_hpp
#define student_hpp

#include <stdio.h>
#include "degree.hpp"

using namespace std;

class Student {

    public:
        const static int numClasses = 3;
    
        //Student Constructors
        Student(string studID, string studFirst, string studLast,
                string studEmail, int studAge, int studClass1, int studClass2, int
                studClass3, DegreeProgram studDegree);
            
        //Setters for the Student object
        void setStudentID(string inputStudID);
        void setFirstName(string inputFirst);
        void setLastName(string inputLast);
        void setEmail(string inputEmai);
        void setAge(int inputAge);
        void setDaysLeft(int inputClass1, int inputClass2, int inputClass3);
        void setDegree(DegreeProgram inputDegree);
        
        //Getters for the Student object
        string getStudentID();
        string getFirstName();
        string getLastName();
        string getEmail();
        int getAge();
        int* getDaysLeft();
        DegreeProgram getDegree();
    
        //Print out individual student's inforamtion
        void print();
        
        
    private:
        string studentID;
        string firstName;
        string lastName;
        string email;
        int age;
        int daysLeft[numClasses];
        DegreeProgram studentDegree = SECURITY;
};

#endif /* student_hpp */
