#pragma once
#include <iostream>
#include "networkStudent.h"

using namespace std;

//blank constuctor
NetworkStudent::NetworkStudent()
{
	setDegreeProgram(NETWORK);
}

//full constructor
NetworkStudent::NetworkStudent(string ID, string FirstName, string LastName, string Email, int Age, int* days, Degree degree)
{
	setDegreeProgram(NETWORK);
}

//push NETWORK to NetworkStudent
Degree NetworkStudent::getDegreeProgram()
{
	return NETWORK;
}

void NetworkStudent::setDegreeProgram(Degree degree)
{
	this->degree = NETWORK;
}

//call print from Student then print NETWORK
void NetworkStudent::print()
{
	this->Student::print();
	cout << "NETWORK" << endl;
}

//Destructor for Network and Student
NetworkStudent::~NetworkStudent()
{
	Student::~Student();
}