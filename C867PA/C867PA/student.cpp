#include "student.h"
Student::Student() /*Parameterless constructor sets to default values*/
{
	this->studentID = ""; /*Empty string is something, nullptr is nothing*/
	this->firstName = "";
	this->lastName = "";
	this->emailAddress = "";
	this->age = 0;
	for (int i = 0; i < courseCompletionDayAmount; i++) this->daysInCourse[i] = 0;
	this->degreeProgram = DegreeProgram::SECURITY;
}

Student::Student(string studentID, string firstName, string lastName, string emailAddress, int age, int daysInCourse[], DegreeProgram degreeProgram) {
	this->studentID = studentID;
	this->firstName = firstName;
	this->lastName = lastName;
	this->emailAddress = emailAddress;
	this->age = age;
	for (int i = 0; i < courseCompletionDayAmount; i++) this->daysInCourse[i] = daysInCourse[i];
	this->degreeProgram = degreeProgram;
}

Student::~Student() {} /*destructor does nothing - the Book class creates nothing dynamically*/

string Student::getStudentID() { return this->studentID; }
string Student::getFirstName() { return this->firstName; }
string Student::getLastName() { return this->lastName; }
string Student::getEmailAddress() { return this->emailAddress; }
int Student::getAge() { return this->age; }
int* Student::getDaysInCourse() { return this->daysInCourse; }
DegreeProgram Student::getDegreeProgram() { return this->degreeProgram; }

void Student::setStudentID(string studentID) { this->studentID; }
void Student::setFirstName(string firstName) { this->firstName; }
void Student::setLastName(string lastName) { this->lastName; }
void Student::setEmailAddress(string emailAddress) { this->emailAddress; }
void Student::setAge(int age) { this->age; }
void Student::setDaysInCourse(int daysInCourse[]) /*set each value individually*/ {
	for (int i = 0; i < courseCompletionDayAmount; i++) this->daysInCourse[i] = daysInCourse[i];
}
void Student::setDegreeProgram(DegreeProgram degreeProgram) { this->degreeProgram = degreeProgram; }

void Student::printHeader() /*Use to print the header*/ {
	cout << "Output format: StudentID|First Name|Last Name|Email Address|Age|Days to Complete Course| Program\n";
}

void Student::print() {
	cout << this->getStudentID() << '\t'; /*Using tab separated output and getters*/
	cout << this->getFirstName() << '\t';
	cout << this->getLastName() << '\t';
	cout << this->getEmailAddress() << '\t';
	cout << this->getAge() << '\t';
	cout << this->getDaysInCourse()[0] << '\t';
	cout << this->getDaysInCourse()[1] << '\t';
	cout << this->getDaysInCourse()[2] << '\t';
	cout << degreeProgramStrings[this->getDegreeProgram()] << '\n'; /*degreeprogram to string*/
}