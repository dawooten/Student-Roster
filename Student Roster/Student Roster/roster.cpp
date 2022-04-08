#pragma once
#include <iostream>
#include <string>
#include "roster.h"

using namespace std;

//empty constructor for new Roster
Roster::Roster()
{
	this->capacity = 0;
	this->lastIndex = -1;
	this->classRosterArray = nullptr;
}

//max capacity for contructor Roster
Roster::Roster(int capacity)
{
	this->capacity = capacity;
	this->lastIndex = -1;
	this->classRosterArray = new Student * [capacity];
}

//Set instance variables - E.3.a.
void Roster::add(string row)
{
	if (lastIndex < capacity) 
	{
		++lastIndex;
		int daysInCourseArray[Student::daysInCourseSize];
			   
		if (row.substr(row.length() - 8, 8) == "SOFTWARE") 
		{
			this->classRosterArray[lastIndex] = new SoftwareStudent();
			classRosterArray[lastIndex]->setDegreeProgram(SOFTWARE);
		}

		else if (row.substr(row.length() - 7, 7) == "NETWORK") 
		{
			this->classRosterArray[lastIndex] = new NetworkStudent();
			classRosterArray[lastIndex]->setDegreeProgram(NETWORK);
		}

		else if (row.substr(row.length() - 8, 8) == "SECURITY") 
		{
			this->classRosterArray[lastIndex] = new SecurityStudent();
			classRosterArray[lastIndex]->setDegreeProgram(SECURITY);
		}

		//setstudentID
		int rhs = studentData[lastIndex].find(",");
		classRosterArray[lastIndex]->setstudentID(studentData[lastIndex].substr(0, rhs));

		//setfirstName
		int lhs = rhs + 1;
		rhs = studentData[lastIndex].find(",", lhs);
		classRosterArray[lastIndex]->setfirstName(studentData[lastIndex].substr(lhs, rhs - lhs));

		//setlastName
		lhs = rhs + 1;
		rhs = studentData[lastIndex].find(",", lhs);
		classRosterArray[lastIndex]->setlastName(studentData[lastIndex].substr(lhs, rhs - lhs));

		//setemailAddress
		lhs = rhs + 1;
		rhs = studentData[lastIndex].find(",", lhs);
		classRosterArray[lastIndex]->setemail(studentData[lastIndex].substr(lhs, rhs - lhs));

		//setage
		lhs = rhs + 1;
		rhs = studentData[lastIndex].find(",", lhs);
		classRosterArray[lastIndex]->setage(stoi(studentData[lastIndex].substr(lhs, rhs - lhs)));

		//setdaysInCourse1
		//daysInCourse[0]
		lhs = rhs + 1;
		rhs = studentData[lastIndex].find(",", lhs);
		daysInCourseArray[0] = stoi(studentData[lastIndex].substr(lhs, rhs - lhs));

		//setdaysInCourse2
		//daysInCourse[1]
		lhs = rhs + 1;
		rhs = studentData[lastIndex].find(",", lhs);
		daysInCourseArray[1] = stoi(studentData[lastIndex].substr(lhs, rhs - lhs));

		//setdaysInCourse3
		//daysInCourse[2]
		lhs = rhs + 1;
		rhs = studentData[lastIndex].find(",", lhs);
		daysInCourseArray[2] = stoi(studentData[lastIndex].substr(lhs, rhs - lhs));

		classRosterArray[lastIndex]->setdaysInCourse(daysInCourseArray);
	}
}

//Removes students by studentID - E.3.b.
void Roster::remove(string studentID)
{
	for (int i = 0; i <= lastIndex; ++i) 
	{
		if (classRosterArray[i] == nullptr) 
		{
			cout << "ERROR: Student ID Not Found" << endl;
			break;
		}
		else if (studentID == classRosterArray[i]->getstudentID()) 
		{
			classRosterArray[i] = nullptr;
			cout << "Removed Student: " << studentID << endl;
		}
	}
}

// Print tab-separated list - E.3.c.
void Roster::printAll()
{
	for (int i = 0; i <= this->lastIndex; i++) 
	{
		(this->classRosterArray)[i]->print();
	}
}

//Print average of days in 3 courses - E.3.d.
void Roster::printDaysInCourse(string studentID)
{
	bool found = false;
	for (int i = 0; i <= lastIndex; ++i) 
	{
		if (this->classRosterArray[i]->getstudentID() == studentID) 
		{
			found = true;
			int* days = classRosterArray[i]->getdaysInCourse();
			cout << "Average number of days for " << studentID << " in their three courses: " << (days[0] + days[1] + days[2]) / 3 << endl;
		}
	}
}

//Checks and Prints invalid Student emails
void Roster::printInvalidEmails()
{
	for (int i = 0; i <= lastIndex; ++i) 
	{
		string email = classRosterArray[i]->getemail();
		if ((email.find("@") == string::npos) || (email.find(" ") != string::npos) || (email.find(".") == string::npos)) 
		{
			cout << email << endl;
		}
	}
}

//Prints Student Information organized by degree
void Roster::printByDegreeProgram(int degreeProgram)
{
	cout << "Student Roster by Degree: " << degreeTypeString[degreeProgram] << endl;
	for (int i = 0; i <= lastIndex; ++i) 
	{
		if (this->classRosterArray[i]->getDegreeProgram() == degreeProgram) 
		{
			this->classRosterArray[i]->print();
		}
			
	}
}

//Destructor for Roster and its new array 
Roster::~Roster()
{
	for (int i = 0; i < numStudents; ++i)
	{
		delete this->classRosterArray[i];
	}
	delete classRosterArray;
}


int main()
{
	//F.1. Print course, language, student ID, and name
	cout << "Scripting and Programming - Applications - C867" << endl;
	cout << "C++" << endl;
	cout << "000897998" << endl;
	cout << "Derek Wooten" << endl << endl;
	
	//F.2. Create Roster class called classRoster
	Roster* classRosterArray = new Roster(numStudents);

	//F.3. Add numStudents to classRoster
	for (int i = 0; i < numStudents; ++i)
	{
		classRosterArray->add(studentData[i]);
	}
	
	//F.4. Print all
	cout << "Roster" << endl;
	classRosterArray->printAll();
	cout << endl;

	//F.4. Print invalid emails 
	cout << "Invalid Emails: " << endl;
	classRosterArray->printInvalidEmails();
	cout << endl;

	//F.4. Print average days in courses
	cout << "Average days in courses for each student: " << endl;
	for (int i = 0; i < numStudents; ++i) {
		classRosterArray->printDaysInCourse(classRosterArray->classRosterArray[i]->getstudentID());
	}
	cout << endl;

	//F.4. Print SOFTWARE degree program
	classRosterArray->printByDegreeProgram(SOFTWARE);
	cout << endl;

	//F.4. Remove A3
	classRosterArray->remove("A3");
	cout << endl;

	//F.4. Remove A3 and print message
	classRosterArray->remove("A3");
	cout << endl;
	   	 
	system("pause");
	return 0;
}


