#ifndef student_h
#define student_h

#include <iostream>
#include <iomanip>
#include "degree.h"

using std::string;
using std::cout;

class Student {
private:
    string studentID;
    string firstName;
    string lastName;
    string emailAddress;
    int age;
    int days[3];
    DegreeProgram degreeProgram;
public:
    Student();
    Student(string studentID, string firstName, string lastName, string emailAddress, int age, int days[], DegreeProgram degreeProgram);
    ~Student();
    
    string getStudentID();
    string getFirstName();
    string getLastName();
    string getEmailAddress();
    int getAge();
    int getDays();
    DegreeProgram getDegreeProgram();
    
    void setStudentID(string studentID);
    void setFirstName(string firstName);
    void setLastName(string lastName);
    void setEmailAddress(string emailAddress);
    void setAge(int age);
    void setDays(int days[]);
    void setDegreeProgram(DegreeProgram degreeProgram);
    
    void print();
};


#endif /* student_h */
