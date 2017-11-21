#include "stdafx.h"


#include <iostream>


using namespace std;

enum our_list{
	name, ///< name of student
	mark, ///< his/her mark
	status, ///< status of the student (passed or not passed exams) 
};
struct MyStruct {
	char name[255];
	int mark;
	int status;
};

/*!
\brief Output results
\param [in] n
\param [in] obj[] list of objects

Outputting our result into the command line (using "cout")

*/
void print(const MyStruct obj[], int n)
{

	fot(int j = 0; j<n; j++)
		cout << "Name:\t" << obj[j].name << "\t Mark: \t" << obj[j].mark << "\t Status \t" << obj[j].status << endl;
} 

/*!
\brief Result of the session
\param [in] n number of students
\param [in] n number of students
\warning number of students must be less than the maximum integer value (equal 2,147483647*10^9). It also must be non-negative value.

The result of the 2nd year undergraduate student's posting from the subject "Modern computer technologies in nuclear physics"

*/

int main()
{

	const int n = 3;

	MyStruct student[n] = {};

	for (int i = 0; i < n; i++)
	{
		cout << "\n Name:\t";
		cin >> student[i].name;


		cout << "\n Mark:\t";
		cin >> student[i].mark;


		cout << "\n Status:\t";
		cin >> student[i].status;
	}

	return 0;
}
