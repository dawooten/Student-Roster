#pragma once
#include <iostream>
#include <string>
#include "student.h"
#include "securityStudent.h"
#include "networkStudent.h"
#include "softwareStudent.h"


using namespace std;

//Number of Students in classRosterArray
const int numStudents = 5;

//Data provided with myself as A5
string studentData[numStudents] = {
	"A1,John,Smith,John1989@gm ail.com,20,30,35,40,SECURITY",
	"A2,Suzan,Erickson,Erickson_1990@gmailcom,19,50,30,40,NETWORK",
	"A3,Jack,Napoli,The_lawyer99yahoo.com,19,20,40,33,SOFTWARE",
	"A4,Erin,Black,Erin.black@comcast.net,22,50,58,40,SECURITY",
	"A5,Derek,Wooten,dwoote3@wgu.edu,31,20,20,20,SOFTWARE"
};

//Set up for Roster in roster.cpp
class Roster {
public:
	int lastIndex;
	int capacity;
	Student** classRosterArray; //E.1.
	Roster(); 
	Roster(int capacity);
	void add(string datarow); //E.3.a.
	void remove(string studentID); //E.3.b.
	void printAll(); //E.3.c.
	void printDaysInCourse(string studentID); //E.3.d. asking for average tricky
	void printInvalidEmails(); //E.3.e.
	void printByDegreeProgram(int ); //E.3.f.
	~Roster(); //destrtuctor to end
};