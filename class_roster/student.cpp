#include "student.h"

Student::Student() {
    this->studentID = "";
    this->firstName = "";
    this->lastName = "";
    this->emailAddress = "";
    this->age = 0;
    for (int i = 0; i < 3; i++) this->days[i] = 0;
    this->degreeProgram = DegreeProgram::SOFTWARE;
}

Student::Student(string studentID, string firstName, string lastName, string emailAddress, int age, int days[], DegreeProgram degreeProgram) {
    this->studentID = studentID;
    this->firstName = firstName;
    this->lastName = lastName;
    this->emailAddress = emailAddress;
    this->age = age;
    for (int i = 0; i < 3; i++) {
        this->days[i] = days[i];
    }
    this->degreeProgram = degreeProgram;
}

Student::~Student() {};

string Student::getStudentID() { return this->studentID; }
string Student::getFirstName() { return this->firstName; }
string Student::getLastName() { return this->lastName; }
string Student::getEmailAddress() { return this->emailAddress; }
int Student::getAge() { return this->age; }
int* Student::getDays() { return this->days; }
DegreeProgram Student::getDegreeProgram() { return this->degreeProgram; }

void Student::setStudentID(string studentID) { this->studentID = studentID; }
void Student::setFirstName(string firstName) { this->firstName = firstName; }
void Student::setLastName(string lastName) { this->lastName = lastName; }
void Student::setEmailAddress(string emailAddress) { this->emailAddress = emailAddress; }
void Student::setAge(int age) { this->age = age; }
void Student::setDays(int days[]) {
    for (int i = 0; i < 3; i++) { this->days[i] = days[i]; }
}
void Student::setDegreeProgram(DegreeProgram degreeProgram) { this->degreeProgram = degreeProgram; }

void Student::print() {
    cout << this->getStudentID() << '\t';
    cout << "First Name: " << this->getFirstName() << '\t';
    cout << "Last Name: " << this->getLastName() << '\t';
    cout << "Email: " << this->getEmailAddress() << '\t';
    cout << "Age: " << this->getAge() << '\t';
    cout << "daysInCourse: {" << this->getDays()[0] << ", ";
    cout << this->getDays()[1] << ", ";
    cout << this->getDays()[2] << "} \t";
    cout << "Degree Program: " << degreeProgramStrings[this->getDegreeProgram()] << '\n';
}
