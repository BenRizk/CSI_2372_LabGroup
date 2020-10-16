/***********File:"myFile1.cpp"**********/
#include <iostream> 
#include "myFile1a.h"
#include "myFile1b.h"
using namespace std; 

/*section a) the constructor function, getNum function, and gethours function*/
Course::Course(int number, int givenHours) {
	num = number;
	hours = givenHours;
}
int Course::getNum() {
	return num;
}
int Course::getHours() {//error here with returning address not value
	cout << "printing hours in getHours " << hours << endl;
	return hours;
}


/*section b) */
Student::Student(int a, int b) {
	numID = a;
	maxCoures = b;
	nbCourses = 0;
	List_grades = new int;
	List_courses = new Course*;
}
Student::~Student() {//this deletes all of the pointers
	delete List_grades;
	delete List_courses;
}
double Student::average() {
	int sum = 0;
	for (int i = 0; i < nbCourses; i++)
	{
		sum += List_grades[i];
	}
	return sum/ nbCourses;
}
int Student::totalHours() {
	int sum = 0;
	for (int i = 0; i < nbCourses; i++)
	{
		//cout << List_courses[0]->getHours()<< endl;
		sum += List_courses[i]->getHours();
	}
	return sum;
}
bool Student::addCourse(Course* newClass, int grade) {
	if (nbCourses == 0) {  
		cout << "in addCourse " << grade << "  " << &grade << endl;
		List_grades[0] = grade;
		List_courses[0] = newClass;
		cout << "in addCourse lists " << List_grades[0] << "  " << List_courses[0] << endl;
	}
	if (nbCourses >= maxCoures) { return false; }
	nbCourses++;
	List_grades[nbCourses] = grade;
	List_courses[nbCourses] = newClass;
	return true;
}


int main() { 
	Course*Math= new Course(100,60); 
	Course*ITI= new Course(200,120); 
	Student*Yan= new Student(1, 35); 
	Student*Jane=new Student(2, 35); 
	Yan->addCourse(Math,15); 
	Yan->addCourse(ITI,12); 
	Jane->addCourse(Math,8); 
	Jane->addCourse(ITI,5); 
	cout << "The total hours of Yan is "<< Yan->totalHours() << endl; 
	cout << "The average of Yan is "<< Yan->average() << endl; 
	cout << "The total hours of Jane is "<< Jane->totalHours() << endl;
	cout << "The average of Jane is "<< Jane->average() << endl; 
	delete Math; 
	delete ITI; 
	delete Yan; 
	delete Jane; 
	cout<< " Enter a number to exit..."<<endl; 
	return 0;
}