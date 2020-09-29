// Lab_1.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include "myfile2.h"
using namespace std;

/*IV.5 Excersise 2:
    1) the main function calculates the surface area of a disck if given the coice option 1, calculates the volume of a cylinder if given choice option 2 and if given choice option 3 then it prints the calues for the surface and the volume.

    */
    //Excersise 2: 2i)
int surface(int rad) {
    const double Pi = 3.14159;
    return 2 * Pi * rad;
}

//Excersise 2: 2ii)
int volume(int rad, int hei) {
    return surface(rad) * hei;
}

double findHex(double val) {
    double temp;
    int counter = 0;
    temp = val;
    do {
        temp = temp / 16;
        counter++;
    } while (temp > 1);     // repeat while temp is not a fraction
    return (counter + temp);
}

double findOct(double val) {
    double temp;
    int counter = 0;
    temp = val;
    do {
        temp = temp / 8;
        counter++;
    } while (temp > 1); // repeat while temp is not a fraction
    return (counter + temp);
}

double* getSci(double val) {
    double hold[2];
    hold[0] = val;
    hold[1] = 0;
    while (hold[0] > 10) {
        hold[0] = hold[0] / 10;
        hold[1]++;
    }; // repeat while temp is not a fraction
    return hold;
}

int main()
{
    int a;
    char b;
    float c;
    double d;
    unsigned int f;
    short int g;

    cout << sizeof(a) << "\n";
    cout << sizeof(b) << "\n";
    cout << sizeof(c) << "\n";
    cout << sizeof(d) << "\n";
    cout << sizeof(f) << "\n";
    cout << sizeof(g) << "\n";

    

    const double Pi = 3.14159;
    int sur = surface(2);
    int vol = volume(4, 3);

    cout << "my surface: " << "\n" << sur;
    cout << "my volume: " << "\n" << vol << "\n";
    

    double fillMe;
    double myInt;
    double* mySci;
    char myChar;

    cout << "Enter number: ";
    cin >> fillMe;
    cout << "\n" << "Enter another number: ";
    cin >> myInt;
    cout << "\n" << "Enter letter: " ;
    cin >> myChar;

    cout << "The values(dec,oct,hex): " << fillMe << ", " << findOct(fillMe) << ", " << findHex(fillMe);
    mySci = getSci(myInt);
    cout << "\n" << "With and without notational value: " << myInt << ", " << mySci[0] << " e+" << mySci[1];
    cout << "\n" <<"Your character: " << myChar;
    
    return 0;
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
