#include "roster.h"

int main() {
	/*STRINGS TO BE PARSED*/
	const string studentData[] =
	{
		"A1,John,Smith,John1989@gm ail.com,20,30,35,40,SECURITY",
		"A2,Suzan,Erickson,Erickson_1990@gmailcom,19,50,30,40,NETWORK",
		"A3,Jack,Napoli,The_lawyer99yahoo.com,19,20,40,33,SOFTWARE",
		"A4,Erin,Black,Erin.black@comcast.net,22,50,58,40,SECURITY",
		"A5,Solomon,Blount,sblou44@wgu.edu,23,14,40,33,SOFTWARE"
	};

	const int numStudents = 5;
	Roster classRoster;

	for (int i = 0; i < numStudents; i++) classRoster.parse(studentData[i]);
	cout << "Displaying all students: " << std::endl;
	classRoster.printAll();
	cout << std::endl;

	cout << "Displaying all students with invalid email addresses: " << std::endl;
	classRoster.printInvalidEmails();
	cout << std::endl;

	cout << "Displaying average days to complete a course: " << std::endl;
	classRoster.printAverageDaysInCourse();

	for (int i = 0; i < 3; i++) {
		cout << "Displaying by degree program: " << degreeProgramStrings[i] << std::endl;
		classRoster.printByDegreeProgram((DegreeProgram)i); /*cast the integer to a degree program*/
	}

	cout << "Removing student by ID A3: " << std::endl;
	classRoster.remove("A3");
	cout << std::endl;

	/*printAll() is inside the remove() function*/

	/*attempting to remove the same student twice to prove success for the first function call*/

	cout << "Removing student by ID A1: " << std::endl;
	classRoster.remove("A3");
	cout << std::endl;

	system("pause");
	return 0;
}



