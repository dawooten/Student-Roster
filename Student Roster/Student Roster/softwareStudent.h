#pragma once
#include <iostream>
#include <string>
#include "degree.h"
#include "student.h"

//new class
class SoftwareStudent : public Student
{

public:

	//constructors empty and full
	SoftwareStudent();
	SoftwareStudent(string ID, string FirstName, string LastName, string Email, int Age, int days[], Degree dtype); //possible issue here - see BR example

	//overwritten getDegreeProgram() function
	Degree getDegreeProgram();
	void setDegreeProgram(Degree dtype);

	//print
	void print();

	//destructor
	~SoftwareStudent();

};

