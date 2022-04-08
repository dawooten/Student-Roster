#pragma once
#include <iostream>
#include <string>
#include "degree.h"

using namespace std;

class Student
{

public:

    //number of courses from degree.h
    const static int daysInCourseSize = 3;

protected:

    //base class variables
    string studentID;
    string firstName;
    string lastName;
    string email;
    int age;
    int* daysInCourse;
    Degree degree;

public:

    //constructors
    Student();
    Student(string ID, string FirstName, string LastName, string Email, int Age, int days[], Degree degree);

    //accessors/getters
    string getstudentID();
    string getfirstName();
    string getlastName();
    string getemail();
    int getage();
    int* getdaysInCourse();
    virtual Degree getDegreeProgram() = 0; //leave implementation of getDegreeProgram() empty

    //mutators/setters
    void setstudentID(string ID);
    void setfirstName(string FirstName);
    void setlastName(string LastName);
    void setemail(string Email);
    void setage(int Age);
    void setdaysInCourse(int days[]);
    virtual void setDegreeProgram(Degree degree) = 0;

    //virtual print specific student data
    virtual void print() = 0;

    //destructor
    ~Student();

};