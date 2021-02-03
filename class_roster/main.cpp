#include "roster.h"

int main() {
    const string studentData[] = {
        "A1,John,Smith,John1989@gm ail.com,20,30,35,40,SECURITY",
        "A2,Suzan,Erickson,Erickson_1990@gmailcom,19,50,30,40,NETWORK",
        "A3,Jack,Napoli,The_lawyer99yahoo.com,19,20,40,33,SOFTWARE",
        "A4,Erin,Black,Erin.black@comcast.net,22,50,58,40,SECURITY",
        "A5,Matthew,Etress,metress1@wgu.edu,32,14,23,37,SOFTWARE"
    };
    
    cout << "Course: C867 - Scripting and Programming Applications \n";
    cout << "Language: C++ \n";
    cout << "Student ID: 001037958 \n";
    cout << "Name: Matthew Etress \n\n\n";
    
    Roster classRoster;
    const int numStudents = 5;
    
    for (int i = 0; i < numStudents; i++) {
        classRoster.parse(studentData[i]);
    }
    
    cout << "Displaying all students: \n";
    classRoster.printAll();
    cout << '\n';
    
    cout << "Displaying invalid email addresses: \n";
    classRoster.printInvalidEmails();
    cout << '\n';
    
    cout << "Displaying average days in course: \n";
    for (int i = 0; i < numStudents; i++) {
        classRoster.printAverageDaysInCourse(classRoster.classRosterArray[i]->getStudentID());
    }
    cout << "\n";
    
    cout << "Displaying Software Degree Program Students: \n";
    classRoster.printByDegreeProgram(SOFTWARE);
    cout << "\n";
    
    classRoster.remove("A3");
    
    cout << "Displaying updated student roster: \n";
    classRoster.printAll();
    cout << "\n";
    
    classRoster.remove("A3");
    
    return 0;
}
