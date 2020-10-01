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