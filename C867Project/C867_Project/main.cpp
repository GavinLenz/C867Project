#include <iostream>
#include "degree.h"
#include "student.h"
#include "roster.h"


int main() {
    cout << "---------------------------------------------------------"<< '\n';
    cout << "| Class: C867 - Scripting and Programming: Applications |"<< '\n';
    cout << "| Language: C++                                         |"<< '\n';
    cout << "| Student ID: 011792260                                 |"<< '\n';
    cout << "| Name: Gavin Lenz                                      |"<< '\n';
    cout << "---------------------------------------------------------"<< '\n';
    
    const string studentData[] = {
        "A1,John,Smith,John1989@gm ail.com,20,30,35,40,SECURITY",
        "A2,Suzan,Erickson,Erickson_1990@gmailcom,19,50,30,40,NETWORK",
        "A3,Jack,Napoli,The_lawyer99yahoo.com,19,20,40,33,SOFTWARE",
        "A4,Erin,Black,Erin.black@comcast.net,22,50,58,40,SECURITY",
        "A5,Gavin,Lenz,glenz1@wgu.edu,20,10,60,90,SOFTWARE"
    };
    
    const static int NUMBER_OF_STUDENTS = 5;
    Roster roster;
    Student student;


    for (int i = 0; i < NUMBER_OF_STUDENTS; ++i) {
        roster.parse(studentData[i]);
    };
    
    cout << "Displaying all students: " << '\n';
    roster.printAll();
    cout << '\n';

    cout << "Displaying student's average days in courses: " << '\n';
    roster.printAverageDaysInCourse(student.getStudentId());
    cout << '\n';
    
    cout << "Displaying invalid emails: " << '\n';
    roster.printInvalidEmails();
    cout << '\n';
    
    cout << "Displaying students in the Software degree program: " << '\n';
    roster.printByDegreeProgram(SOFTWARE);
    cout << '\n';

    cout << "Removing student with the ID \"A3\" from the roster... " << '\n';
    roster.remove("A3");
    cout << '\n';

    cout << "Redisplaying all students: " << '\n';
    roster.printAll();
    cout << '\n';

    cout << "Searching for student with the ID \"A3\" from the roster... " << '\n';
    roster.remove("A3");
    cout << '\n';

    cout << "Deleting roster..." << '\n';
    roster.~Roster();
    
    
    return 0;
}
