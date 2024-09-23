#pragma once
#include <stdio.h>
#include "student.h"


class Roster {
public:
    int index = 0;
    int NUMBER_OF_STUDENTS = 5;
    void parse(string row);
    void add(int students);
    void remove(string studentId);
    void printAll();
    void printInvalidEmails();
    void printAverageDaysInCourse(string studentId);
    void printByDegreeProgram(DegreeProgram degree);
    ~Roster();
    
private:
    Student* classRosterArray[5];
};
