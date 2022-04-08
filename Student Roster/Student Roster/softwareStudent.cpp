#pragma once
#include <iostream>
#include "softwareStudent.h"

using namespace std;

//blank constuctor
SoftwareStudent::SoftwareStudent()
{
	setDegreeProgram(SOFTWARE);
}

//full constructor
SoftwareStudent::SoftwareStudent(string ID, string FirstName, string LastName, string Email, int Age, int* days, Degree degree)
{
	setDegreeProgram(SOFTWARE);
}

//push SOFTWARE to NetworkStudent
Degree SoftwareStudent::getDegreeProgram()
{
	return SOFTWARE;
}

void SoftwareStudent::setDegreeProgram(Degree degree)
{
	this->degree = SOFTWARE;
}


//call print from Student then print SOFTWARE
void SoftwareStudent::print()
{
	this->Student::print();
	cout << "SOFTWARE" << endl;
}

//Destructor for Software and Student
SoftwareStudent::~SoftwareStudent()
{
	Student::~Student();
}