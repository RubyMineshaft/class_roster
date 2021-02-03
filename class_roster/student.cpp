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

Student::Student(string studentID, string firstName, string lastName, string emailAddress, int age, int daysInCourse1, int daysInCourse2, int daysInCourse3, DegreeProgram degreeProgram) {
    this->studentID = studentID;
    this->firstName = firstName;
    this->lastName = lastName;
    this->emailAddress = emailAddress;
    this->age = age;
    this->days[0] = daysInCourse1;
    this->days[1] = daysInCourse2;
    this->days[2] = daysInCourse3;
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
    cout << this->getFirstName() << '\t';
    cout << this->getLastName() << '\t';
    cout << this->getEmailAddress() << '\t';
    cout << this->getAge() << '\t';
    cout << this->getDays()[0] << ", ";
    cout << this->getDays()[1] << ", ";
    cout << this->getDays()[2] << '\t';
    cout << degreeProgramStrings[this->getDegreeProgram()] << '\n';
}
