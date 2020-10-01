#include " myFile2.h"
/********************************************************************************/
/* Function menu which returns a character corresponding to the user's choice */
/********************************************************************************/
char menu(void)
{
	char choice;
	cout << endl << endl << "\t\tMenu" << endl << endl;
	cout << "1) Strings display." << endl;
	cout << "2) Replacement of a string by an other one" << endl;
	cout << "3) Sorting strings" << endl;
	cout << "4) Exit of the program" << endl << endl;
	cout << "Your choice :";
	cin >> choice;
	return(choice);
}
/********************************************************************************/
/*The replace function that replaces one string by another. It takes as arguments an array of pointers
on the strings "tab", the number of elements of this array of pointers "nbre" and the maximum size of
the strings "size" */
/********************************************************************************/
void replace(char* tab[], int const& nbre, int const& size)
{
	int numero; //the string to modify
	cout << endl << "Enter the string number to modify: ";
	cin.ignore(INT_MAX, '\n');
	cin >> numero;
	if (numero >= 0 && numero <= nbre) //check if the number is valid
	{
		cout << "Enter the new string: ";
		cin.ignore(INT_MAX, '\n');
		cin.getline(tab[numero], size, ' ');
	}
	else
	{
		cout << "There is no string with this number" << endl;
	}
}