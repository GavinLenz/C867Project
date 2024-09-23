#include <stdio.h>
#include <string>
#include "student.h"


Student::Student() {}

Student::Student(string studentId, string firstName, string lastName, string emailAddress, int age, int daysToComplete1, int daysToComplete2, int daysToComplete3, DegreeProgram degree) {
    this->studentId = studentId;
    this->firstName = firstName;
    this->lastName = lastName;
    this->emailAddress = emailAddress;
    this->daysToComplete[0] = 0;
    this->daysToComplete[1] = 0;
    this->daysToComplete[2] = 0;
    for (int i = 0; i < DAYS_ARRAY_SIZE; i++) {
        this->daysToComplete[i] = 0;
    }
    this->degree = degree;
}

string Student::getStudentId() {
    return studentId;
}

string Student::getFirstName() {
    return firstName;
}

string Student::getLastName() {
    return lastName;
}

string Student::getEmailAddress() {
    return emailAddress;
}

int Student::getAge() {
    return age;
}

int Student::getDaysToComplete1() {
    return daysToComplete[0];
}

int Student::getDaysToComplete2() {
    return daysToComplete[1];
}

int Student::getDaysToComplete3() {
    return daysToComplete[2];
}

DegreeProgram Student::getDegree() {
    return degree;
}

void Student::setStudentId(string studentId) {
    this->studentId = studentId;
}

void Student::setFirstName(string firstName) {
    this->firstName = firstName;
}

void Student::setLastName(string lastName) {
    this->lastName = lastName;
}

void Student::setEmailAddress(string emailAddress) {
    this->emailAddress = emailAddress;
}

void Student::setAge(int age) {
    this->age = age;
}

void Student::setDaysToComplete(int daysToComplete1, int daysToComplete2, int daysToComplete3) {
    this->daysToComplete[0] = daysToComplete1;
    this->daysToComplete[1] = daysToComplete2;
    this->daysToComplete[2] = daysToComplete3;
}

void Student::setDegree(DegreeProgram degree) {
    this->degree = degree;
}

void Student::print() {
    cout << getStudentId() << "   First Name: " << getFirstName() << "   Last Name: " << getLastName() << "   Age: " << getAge() << "   daysInCourse: {" << getDaysToComplete1() << ", " << getDaysToComplete2()
    << ", " << getDaysToComplete3() << "}   Degree Program: " << degreeStrings[getDegree()] << "." << '\n';
}

Student::~Student() {}
