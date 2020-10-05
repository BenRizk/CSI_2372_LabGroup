// myFile1pricipal.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
using namespace std;
#include "myFile1.h";

void main(void)
{
	int i;
	int myTab[size_tab] = { 2,4,88,2,3,55,87,134,2,5 };
	cout << "Display of unsorted array " << endl;
	for (i = 0;i < size_tab;i++) cout << myTab[i] << endl;
	sort(myTab, size_tab);
	cout << " Display of sorted array " << endl;
	for (i = 0;i < size_tab;i++) cout << myTab[i] << endl;
}

void sort(int numbers[], int size) {

}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
