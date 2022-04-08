#pragma once
#include <iostream>
#include "securityStudent.h"

using namespace std;

//blank constuctor
SecurityStudent::SecurityStudent() 
{
	setDegreeProgram(SECURITY);
}

//full constructor
SecurityStudent::SecurityStudent(string ID, string FirstName, string LastName, string Email, int Age, int* days, Degree degree)
{
	setDegreeProgram(SECURITY);
}

//push SECURITY to SecurityStudent
Degree SecurityStudent::getDegreeProgram()
{
	return SECURITY;
}

void SecurityStudent::setDegreeProgram(Degree degree)
{
	this->degree = SECURITY;
}

//call print from Student then print SECURITY 
void SecurityStudent::print()
{
	this->Student::print();
	cout << "SECURITY" << endl;
}

//Destructor for Security and Student
SecurityStudent::~SecurityStudent()
{
	Student::~Student();
}