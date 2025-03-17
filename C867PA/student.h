#pragma once
#include <iostream>
#include <iomanip>
#include "degree.h"
using std::string;
using std::cout;
//using std::endl;

class Student {
public:
	const static int courseCompletionDayAmount = 3;
private:
	string studentID;
	string firstName;
	string lastName;
	string emailAddress;
	int age;
	int daysInCourse[courseCompletionDayAmount];
	DegreeProgram degreeProgram;
public:
	Student(); /*parameterless constructor - sets to default values - you always write this!*/
	Student(string studentID, string firstName, string lastName, string emailAddress, int age, int daysInCourse[], DegreeProgram degreeProgram);/*Full constructor*/
	~Student(); /*destructor*/

	/*getters aka accessors*/
	string getStudentID();
	string getFirstName();
	string getLastName();
	string getEmailAddress();
	int getAge();
	int* getDaysInCourse();
	DegreeProgram getDegreeProgram();

	/*setters aka mutators*/
	void setStudentID(string studentID);
	void setFirstName(string firstName);
	void setLastName(string lastName);
	void setEmailAddress(string emailAddress);
	void setAge(int age);
	void setDaysInCourse(int daysInCourse[]);
	void setDegreeProgram(DegreeProgram dp);

	static void printHeader(); /*displays a header for the data to follow*/

	void print(); /*displays 'this' student's data*/
};

