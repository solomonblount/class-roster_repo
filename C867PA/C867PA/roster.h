#pragma once
#include "student.h"
class Roster {
private:
	int lastIndex = -1;
	const static int numStudents = 5;
	Student* classRosterArray[numStudents]; /*Not declared dynamically*/

public:
	/*The parse method goes through a set of comma-delimited strings and extracts the data of a student*/
	void parse(string row);
	/*All student data is then passed into the add method, which creates the Student object and places it in the roster*/
	void add(string studentID,
		string firstName,
		string lastName,
		string emailAddress,
		int age,
		int daysInCourse1,
		int daysInCourse2,
		int daysInCourse3,
		DegreeProgram degreeProgram);
	void remove(string studentID); /*Find the student with supplied ID and remove*/
	void printAll(); /*Loops through all the students in classRosterArray and call the print() function for each student*/
	void printAverageDaysInCourse(); /*Prints a student's average number of days in the three courses (the student ID parameter identifies the student)*/
	void printByDegreeProgram(DegreeProgram degreeProgram); /*Prints out student information for a degree program specified by an enumerated type*/
	void printInvalidEmails(); /*Each student's email must contain a '@', '.' and no spaces*/
	~Roster();
};

