#include "roster.h"

void Roster::parse(string studentData) {
	int rhs = studentData.find(","); // Find the first comma
	string studentID = studentData.substr(0, rhs); // Extract student ID

	int lhs = rhs + 1; // Move past the previous comma
	rhs = studentData.find(",", lhs);
	string firstName = studentData.substr(lhs, rhs - lhs); // Extract first name

	lhs = rhs + 1; // Move past the previous comma
	rhs = studentData.find(",", lhs);
	string lastName = studentData.substr(lhs, rhs - lhs); // Extract last name

	lhs = rhs + 1; // Move past the previous comma
	rhs = studentData.find(",", lhs);
	string emailAddress = studentData.substr(lhs, rhs - lhs); // Extract email

	lhs = rhs + 1; // Move past the previous comma
	rhs = studentData.find(",", lhs);
	int age = stod(studentData.substr(lhs, rhs - lhs)); // Extract age

	lhs = rhs + 1; // Move past the previous comma
	rhs = studentData.find(",", lhs);
	int daysInCourse1 = stod(studentData.substr(lhs, rhs - lhs)); // Extract days in course 1

	lhs = rhs + 1; // Move past the previous comma
	rhs = studentData.find(",", lhs);
	int daysInCourse2 = stod(studentData.substr(lhs, rhs - lhs)); // Extract days in course 2

	lhs = rhs + 1; // Move past the previous comma
	rhs = studentData.find(",", lhs);
	int daysInCourse3 = stod(studentData.substr(lhs, rhs - lhs)); // Extract days in course 3

	lhs = rhs + 1; // Move past the previous comma
	rhs = studentData.find(",", lhs);
	string degreeProgramStr = studentData.substr(lhs, rhs - lhs); // Extract degree program as a string

	// Determine the DegreeProgram based on the extracted string
	DegreeProgram degreeProgram = SECURITY; // Default value
	if (degreeProgramStr == "NETWORK") {
		degreeProgram = NETWORK;
	}
	else if (degreeProgramStr == "SOFTWARE") {
		degreeProgram = SOFTWARE;
	}

	// Add the student to the roster
	add(studentID, firstName, lastName, emailAddress, age, daysInCourse1, daysInCourse2, daysInCourse3, degreeProgram);
}

void Roster::add(string studentID, string firstName, string lastName, string emailAddress, int age, int daysInCourse1, int daysInCourse2, int daysInCourse3, DegreeProgram degreeProgram) /*Put days in course back into array for constructor */ {
	int darr[3] = { daysInCourse1, daysInCourse2, daysInCourse3 };
	/*Make a new Student object (lastIndex starts at -1, NOT 0!*/
	/*Use the prefix form of ++, NOT postfix*/
	classRosterArray[++lastIndex] = new Student(studentID, firstName, lastName, emailAddress, age, darr, degreeProgram); /*Call full student constructor*/
}

/*display all students using tab-separated output*/
void Roster::printAll() {
	Student::printHeader();
	for (int i = 0; i <= Roster::lastIndex; i++) {
		classRosterArray[i]->print(); // Call the print() method for each student
	}
	cout << std::endl;
}

/*display only students who match the given degree program*/
void Roster::printByDegreeProgram(DegreeProgram degreeProgram) {
	Student::printHeader();
	for (int i = 0; i <= Roster::lastIndex; i++) {
		if (Roster::classRosterArray[i]->getDegreeProgram() == degreeProgram) classRosterArray[i]->print();
	}
	cout << std::endl;
}

/*Each student's email must contain a '@', '.' and no spaces*/
void Roster::printInvalidEmails() {
	bool any = false;
	for (int i = 0; i <= Roster::lastIndex; i++) {
		string emailAddress = (classRosterArray[i]->getEmailAddress());
		if (emailAddress.find('@') == string::npos || emailAddress.find('.') == string::npos || emailAddress.find(' ') != string::npos) {
			any = true;
			cout << emailAddress << ": " << classRosterArray[i]->getStudentID() << std::endl;
		}
	}
	if (!any) cout << "NONE" << std::endl;
}

void Roster::printAverageDaysInCourse(string studentID) {
	bool success = false; /*assuming it isn't here*/
	for (int i = 0; i <= Roster::lastIndex; i++) {
		if (classRosterArray[i]->getStudentID() == studentID) {
			success = true; /*found*/
			cout << classRosterArray[i]->getStudentID() << ": ";
			cout << (classRosterArray[i]->getDaysInCourse()[0]
				+ classRosterArray[i]->getDaysInCourse()[1]
				+ classRosterArray[i]->getDaysInCourse()[2]) / 3.0 << std::endl;
		}
	}
	cout << std::endl;
}

void Roster::remove(string studentID) /*studentID is a parameter*/ {
	bool success = false; /*assuming it isn't here*/
	for (int i = 0; i <= Roster::lastIndex; i++) {
		if (classRosterArray[i]->getStudentID() == studentID) {
			success = true; /*found*/
			if (i < numStudents - 1) {
				Student* temp = classRosterArray[i]; /*swap it with last student*/
				classRosterArray[i] = classRosterArray[numStudents - 1];
				classRosterArray[numStudents - 1] = temp;
			}
			Roster::lastIndex--; /*the last book isn't deleted, but cannot be accessed because the previous index is decremented*/
		}
	}
	if (success) {
		cout << studentID << " removed from the roster." << std::endl << std::endl;
	}
	else cout << studentID << " not found." << std::endl << std::endl;
}

Roster::~Roster() {
	cout << "DESTRUCTOR CALLED!" << std::endl << std::endl;
	for (int i = 0; i < numStudents; i++) {
		cout << "Destroying student #" << i + 1 << std::endl;
		delete classRosterArray[i];
		classRosterArray[i] = nullptr;
	}
}


