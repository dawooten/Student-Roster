#pragma once
#include <iostream>
#include <string>
#include "degree.h"
#include "student.h"

//new class
class NetworkStudent : public Student
{

public:

	//constructors empty and full
	NetworkStudent();
	NetworkStudent(string ID, string FirstName, string LastName, string Email, int Age, int days[], Degree dtype); //possible issue here - see BR example

	//overwritten getDegreeProgram() function
	Degree getDegreeProgram();
	void setDegreeProgram(Degree dtype);

	//print
	void print();

	//destructor
	~NetworkStudent();

};

