// Lab_2.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
using namespace std;
void main(void)
{
	int tab[80];
	int* p;
	int i;
	for (i = 0; i < 80; i++) tab[i] = i * i;
	cout << tab[2] << endl;
	tab[2] = tab[1];
	cout << tab[1] << endl;
	cout << tab[2] << endl;
	tab[2] = *(tab + 1);
	cout << tab[1] << endl;
	cout << tab[2] << endl;
	*(tab + 2) = tab[1];
	cout << tab[1] << endl;
	*(tab + 2) = *(tab + 1);
	p = &tab[0];
	p = tab + 1;
	tab[4] = *p;
	
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
