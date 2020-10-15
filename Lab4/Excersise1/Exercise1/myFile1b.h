/* **********File:"myFile1b.h" * *********/ 
#include <iostream>
#include "myFile1a.h"
using namespace std; 
class Student{ 
	int numID; 
	int nbCourses; 
	int maxCoures; 
	int* List_grades; 
	Course * *List_courses; 
public: 
	Student(int, int); //constructor
	~Student(); //destructor
	double average(); 
	int totalHours(); 
	bool addCourse(Course*, int ); 
};