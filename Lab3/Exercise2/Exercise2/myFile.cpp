// Exercise2.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "myLinkedList.h"


Evaluation* add(Evaluation* e, int& i) {
	Evaluation *current = e;
	for (int j = 0; j < i; j++)
	{
		current = current->next;
	}
	//get and set new values
	char newStudent[20] = " ";
	int newGrade;
	cout << "enter the student value" << endl;
	cin >> newStudent;
	cout << "enter the grade value" << endl;
	cin >> newGrade;
	
	Evaluation* newLink = NULL;
	//newLink->student = *newStudent;
	newLink->grade = newGrade;

	current = current->next = newLink;

	return e;
}

Evaluation* remove(Evaluation* e, int& i) {
	//get the name of the student to remove
	char newStudent[20];
	cout << "enter the name of the student you wish to delete" << endl;
	cin >> newStudent;
	//check if it is the first value
	if (e->student == newStudent) {
		return e->next;
	}
	
	//check other values
	Evaluation* current = e;

	for (int j = 0; j < i; j++)
	{
		if (current->next->student == newStudent) {
			current->next = current->next->next;
			break;
		}
		current = current->next;
	}
	
	return e;
}

void display(Evaluation* e) {
	if (e == NULL) { return; }
	while (e->next != NULL)
	{
		cout << "student named " << e->student;
		cout << "has a grade of: " << e->grade << endl;
		e = e->next;
	}
}

int average(Evaluation* e, int const& i) {
	int sum = 0;
	Evaluation* current = e;
	for (int j = 0; j < i; j++)
	{
		sum += current->grade;
	}
	return sum/i;//returns sum of all grades devided by the number of grades (the average)
}



int main()
{
	Evaluation *first=NULL;		//Pointer on the firstelement of the list
								//the list is empty, so initialization to NULL
	int number=0;				//number o felements in the linked list
	int choice;					//choice for the menu
	do{
		cout << endl << endl <<"1) Display ofthe complete linked list.\n";
		cout << "2)Inserting anelement\n";
		cout << "3) Removinganelement.\n";
		cout << "4) Calculation of theclass average.\n";
		cout << "5) Exiting theprogram.\n" <<endl << endl;
		cout << "Your choice??:";
		cin >> choice;

		switch (choice)
		{
			case 1: display(first); 
			break;
			case 2: first=add(first,number); 
			break;
			case 3: first=remove(first,number);
			break;
			case 4: average(first,number); 
			break;
			case 5: exit(0);
			default:
				break;
		}
	}while (1);
	return 0;
}

