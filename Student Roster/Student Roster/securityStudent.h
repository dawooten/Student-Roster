#pragma once
#include <iostream>
#include <string>
#include "degree.h"
#include "student.h"

//new class
class SecurityStudent : public Student 
{

public:

	//constructor blank and full
	SecurityStudent();
	SecurityStudent(string ID, string FirstName, string LastName, string Email, int Age, int* days, Degree degree);

	//overriding the getDegreeProgram() function in Student
	Degree getDegreeProgram();
	void setDegreeProgram(Degree degree);

	//print
	void print();

	//destructor
	~SecurityStudent();

};

	
	
	
	
