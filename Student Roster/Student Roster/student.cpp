#pragma once
#include <iostream>
#include <string>
#include <iomanip>
#include "student.h"
#include "degree.h"

using namespace std;
using std::cout;
using std::left;
using std::setw;

//blank constructor
Student::Student()
{
	this->studentID = ""; //all below are protected in student.h
	this->firstName = "";
	this->lastName = "";
	this->email = "";
	this->age = 0;
	this->daysInCourse = new int[daysInCourseSize];
	
	for (int i = 0; i < daysInCourseSize; ++i) //array of number of days to complete each course
	{
		this->daysInCourse[i] = 0;
	}
}

//full constructor
Student::Student(string ID, string FirstName, string LastName, string Email, int Age, int days[], Degree degree)
{
	this->studentID = ID;
	this->firstName = FirstName;
	this->lastName = LastName;
	this->email = Email;
	this->age = Age;
	this->daysInCourse = new int[daysInCourseSize];
	
	for (int i = 0; i < 3; ++i) 
	{
		this->daysInCourse[i] = days[i];
	}
}

//accessors/getters
string Student::getstudentID()
{
	return studentID;
}

string Student::getfirstName()
{
	return firstName;
}

string Student::getlastName()
{
	return lastName;
}

string Student::getemail()
{
	return email;
}

int Student::getage()
{
	return age;
}

int* Student::getdaysInCourse()
{
	return daysInCourse;
}

//mutators/setters
void Student::setstudentID(string ID)
{
	this->studentID = ID;
}

void Student::setfirstName(string FirstName)
{
	this->firstName = FirstName;
}

void Student::setlastName(string LastName)
{
	this->lastName = LastName;
}

void Student::setemail(string Email)
{
	this->email = Email;
}

void Student::setage(int Age)
{
	this->age = Age;
}

void Student::setdaysInCourse(int daysInCourse[])
{
	for (int i = 0; i < daysInCourseSize; ++i)
	{
		this->daysInCourse[i] = daysInCourse[i];
	}
}

//print students except degree
void Student::print()
{
	int* days = getdaysInCourse();

	cout << getstudentID() << "\t";
	cout << "First name: " << getfirstName() << "\t";
	cout << "Last name: " << getlastName() << "\t";
	cout << "Age: " << getage() << "\t";
	cout << "daysInCourse: {" << *days << " " << *(days + 1) << " " << *(days + 2) << "}" << "\t";

	/*void Student::print()
{
	cout << left << setw(5) << studentID;
	cout << left << setw(10) << firstName;
	cout << left << setw(10) << lastName;
	cout << left << setw(40) << email;
	cout << left << setw(10) << age;
	cout << left << setw(10) << daysInCourse[0];
	cout << left << setw(10) << daysInCourse[1];
	cout << left << setw(10) << daysInCourse[2];
	
}*/
}

//destructor
Student::~Student()
{
	if (daysInCourse != nullptr) 
	{
		delete [] daysInCourse;
		daysInCourse = nullptr;
	}
}	