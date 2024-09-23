#pragma once
#include <iostream>
#include <string>
#include "degree.h"
using std::string;
using std::cout;


class Student {
public:
    const static int DAYS_ARRAY_SIZE = 3;
    Student();
    Student(string studentId, string firstName, string lastName, string emailAddress, int age, int daysToComplete1, int daysToComplete2, int daysToComplete3, DegreeProgram degree);
    ~Student();
    void setStudentId(string studentId);
    void setFirstName(string firstName);
    void setLastName(string lastName);
    void setEmailAddress(string emailAddress);
    void setAge(int age);
    void setDaysToComplete(int daysToComplete1, int daysToComplete2, int daysToComplete3);
    void setDegree(DegreeProgram degree);
    string getStudentId();
    string getFirstName();
    string getLastName();
    string getEmailAddress();
    int getAge();
    int getDaysToComplete1();
    int getDaysToComplete2();
    int getDaysToComplete3();
    DegreeProgram getDegree();
    void print();
    void printHeader();
    
private:
    string studentId;
    string firstName;
    string lastName;
    string emailAddress;
    int age;
    int daysToComplete[DAYS_ARRAY_SIZE];
    DegreeProgram degree;
};

