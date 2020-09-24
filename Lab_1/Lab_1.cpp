// Lab_1.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>

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

int main()
{
    std::cout << "Hello World!\n";
    const double Pi = 3.14159;
    int sur = surface(2);
    int vol = volume(4, 3);
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


