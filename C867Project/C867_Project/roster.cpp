#include <stdio.h>
#include "degree.h"
#include "student.h"
#include "roster.h"


void Roster::add(int students) {
    this->NUMBER_OF_STUDENTS = students;
    this->index = 0;
    for (int i = 0; i < NUMBER_OF_STUDENTS; ++i) {
        this->classRosterArray[i] = new Student();
    }
    return;
}

void Roster::parse(string studentData) {
    string studentId;
    string firstName;
    string lastName;
    string emailAddress;
    int age;
    int daysToComplete1;
    int daysToComplete2;
    int daysToComplete3;
    string type;
    if (index < 5) {
        classRosterArray[index] = new Student();
        
        int i = studentData.find(",");
        studentId = studentData.substr(0, i);
        classRosterArray[index]->setStudentId(studentId);
        
        int j = i + 1;
        i = studentData.find(",", j);
        firstName = studentData.substr(j, i - j);
        classRosterArray[index]->setFirstName(firstName);
        
        j = i + 1;
        i = studentData.find(",", j);
        lastName = studentData.substr(j, i - j);
        classRosterArray[index]->setLastName(lastName);
        
        j = i + 1;
        i = studentData.find(",", j);
        emailAddress = studentData.substr(j, i - j);
        classRosterArray[index]->setEmailAddress(emailAddress);
        
        j = i + 1;
        i = studentData.find(",", j);
        age = stoi(studentData.substr(j, i - j));
        classRosterArray[index]->setAge(age);
        
        j = i + 1;
        i = studentData.find(",", j);
        daysToComplete1 = stoi(studentData.substr(j, i - j));
        
        j = i + 1;
        i = studentData.find(",", j);
        daysToComplete2 = stoi(studentData.substr(j, i - j));
        
        j = i + 1;
        i = studentData.find(",", j);
        daysToComplete3 = stoi(studentData.substr(j, i - j));
        
        classRosterArray[index]->setDaysToComplete(daysToComplete1, daysToComplete2, daysToComplete3);
        
        j = i + 1;
        i = studentData.find(",", j);
        type = studentData.substr(j, i - j);
        if (type == "SECURITY") {
            classRosterArray[index]->setDegree(SECURITY);
        }
        else if (type == "NETWORK") {
            classRosterArray[index]->setDegree(NETWORK);
        }
        else if (type == "SOFTWARE") {
            classRosterArray[index]->setDegree(SOFTWARE);
        }
        else {
            cout << "Unknown Degree Program." << '\n';
        }
        ++index;
    }
    return;
}

void Roster::remove(string studentId) {
    for (int i = 0; i < NUMBER_OF_STUDENTS; ++i) {
        Student* student = classRosterArray[i];
        if (student != nullptr && student->getStudentId() == studentId) {
            classRosterArray[i] = nullptr;
            return;
        }
    }
    cout << "Student with id " << studentId << " not found!" << '\n';
}

void Roster::printAll() {
    for (int i = 0; i < NUMBER_OF_STUDENTS; ++i) {
        if (classRosterArray[i] != nullptr) {
            classRosterArray[i]->print();
        }
    }
    return;
}

void Roster::printInvalidEmails() {
    for (int i = 0; i < NUMBER_OF_STUDENTS; ++i) {
        string emailAddress = classRosterArray[i]->getEmailAddress();
        if ((emailAddress.find(' ') != string::npos) || (emailAddress.find('.') == string::npos) || (emailAddress.find('@') == string::npos)) {
            cout << classRosterArray[i]->getStudentId() << "'s email address " << emailAddress << " is invalid." << '\n';
        }
    }
    return;
}

void Roster::printAverageDaysInCourse(string studentId) {
    for (int i = 0; i < NUMBER_OF_STUDENTS; ++i) {
        int array[3] = {classRosterArray[i]->getDaysToComplete1(), classRosterArray[i]->getDaysToComplete2(), classRosterArray[i]->getDaysToComplete3()};
        double averageDaysToComplete = (static_cast<double>(array[0]) + static_cast<double>(array[1]) + static_cast<double>(array[2])) / 3.0;
        cout << classRosterArray[i]->getStudentId() << "'s Average Days In Their Courses: " << averageDaysToComplete << '\n';
    }
    return;
}

void Roster::printByDegreeProgram(DegreeProgram degree) {
    for (int i = 0; i < NUMBER_OF_STUDENTS; ++i) {
        if (classRosterArray[i] != nullptr && classRosterArray[i]->getDegree() == degree)
            classRosterArray[i]->print();
    }
    return;
}

Roster::~Roster() {
    return;
}
