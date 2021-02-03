#include "roster.h"

void Roster::parse(string row) {
    int rhs = row.find(",");
    string studentID = row.substr(0, rhs);
    
    int lhs = rhs + 1;
    rhs = row.find(",", lhs);
    string firstName = row.substr(lhs, rhs - lhs);
    
    lhs = rhs + 1;
    rhs = row.find(",", lhs);
    string lastName = row.substr(lhs, rhs - lhs);
    
    lhs = rhs + 1;
    rhs = row.find(",", lhs);
    string emailAddress = row.substr(lhs, rhs - lhs);
    
    lhs = rhs + 1;
    rhs = row.find(",", lhs);
    int age = stoi(row.substr(lhs, rhs - lhs));
    
    lhs = rhs + 1;
    rhs = row.find(",", lhs);
    int daysInCourse1 = stoi(row.substr(lhs, rhs - lhs));
    
    lhs = rhs + 1;
    rhs = row.find(",", lhs);
    int daysInCourse2 = stoi(row.substr(lhs, rhs - lhs));
    
    lhs = rhs + 1;
    rhs = row.find(",", lhs);
    int daysInCourse3 = stoi(row.substr(lhs, rhs - lhs));
    
    lhs = rhs + 1;
    rhs = row.find(",", lhs);
    string program = row.substr(lhs, rhs - lhs);
    
    DegreeProgram degreeProgram;
    
    if (program == "SECURITY") degreeProgram = SECURITY;
    else if (program == "NETWORK") degreeProgram = NETWORK;
    else degreeProgram = SOFTWARE;
    
    add(studentID, firstName, lastName, emailAddress, age, daysInCourse1, daysInCourse2, daysInCourse3, degreeProgram);
}

void Roster::add(string studentID, string firstName, string lastName, string emailAddress, int age, int daysInCourse1, int daysInCourse2, int daysInCourse3, DegreeProgram degreeProgram) {
    int daysArr[3] = {daysInCourse1, daysInCourse2, daysInCourse3};
    
    classRosterArray[++lastIndex] = new Student(studentID, firstName, lastName, emailAddress, age, daysArr, degreeProgram);
}

void Roster::remove(string studentID) {
    bool removed = false;
    for (int i = 0; i <= Roster::lastIndex; i++) {
        if (classRosterArray[i]->getStudentID() == studentID) {
            if (i < numStudents - 1) {
                Student* temp = classRosterArray[i];
                classRosterArray[i] = classRosterArray[numStudents - 1];
                classRosterArray[numStudents - 1] = temp;
            }
            Roster::lastIndex--;
            removed = true;
        }
    }
    if (removed) {
        cout << studentID << " has been successfully removed from the roster. \n\n";
    } else {
        cout << "No student found with ID " << studentID << ".\n\n";
    }
}

void Roster::printAll() {
    for (int i = 0; i <= lastIndex; i++) classRosterArray[i]->print();
}

void Roster::printAverageDaysInCourse(string studentID) {
    for (int i = 0; i < 5; i++) {
        if (Roster::classRosterArray[i]->getStudentID() == studentID) {
            cout << studentID << ": ";
            cout << (classRosterArray[i]->getDays()[0] + classRosterArray[i]->getDays()[1] + classRosterArray[i]->getDays()[2]) / 3.0;
            cout << "\n";
        }
    }
}

void Roster::printInvalidEmails() {
    bool any = false;
    
    for (int i = 0; i <= Roster::lastIndex; i++) {
        string email = Roster::classRosterArray[i]->getEmailAddress();
        if (email.find("@") == string::npos || email.find(".") == string::npos || email.find(" ") != string::npos) {
            any = true;
            cout << email << "\n";
        }
    }
    
    if (!any) cout << "None";
}

void Roster::printByDegreeProgram(DegreeProgram degreeProgram) {
    for (int i = 0; i <= Roster::lastIndex; i++) {
        if (Roster::classRosterArray[i]->getDegreeProgram() == degreeProgram) classRosterArray[i]->print();
    }
    cout << '\n';
}

Roster::~Roster() {
    for (int i = 0; i < numStudents; i++) {
        delete classRosterArray[i];
        classRosterArray[i] = nullptr;
    }
    cout << "Class Roster has been destroyed.\n";
}
