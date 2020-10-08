// myFile1a.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
using namespace std;
enum Color { club, diamond, spades, heart };
enum Face { seven, eight, nine, ten, jack, queen, king, ace };
struct Card
{
	Color color;
	Face face;
};

int main()
{
	Card temp;
	
	int hold= 0;
	int hold2 = 0;

	Card game[32];
	for (int i = 0; i < 32; i++) {
		hold = rand() % 4;		//choose random number from 0-3
		hold2 = rand() % 7;		//choose random number from 0-7
		//decide suit
		if (hold == 0) {
			game[i].color = club;
		}
		if (hold == 1) {
			game[i].color = diamond;
		}
		if (hold == 2) {
			game[i].color = spades;
		}
		if (hold == 3) {
			game[i].color = heart;
		}
		//decide face
		if (hold2 == 0) {
			game[i].face = seven;
		}
		if (hold2 == 1) {
			game[i].face = eight;
		}
		if (hold2 == 2) {
			game[i].face = nine;
		}
		if (hold2 == 3) {
			game[i].face = ten;
		}
		if (hold2 == 4) {
			game[i].face = jack;
		}
		if (hold2 == 5) {
			game[i].face = queen;
		}
		if (hold2 == 6) {
			game[i].face = king;
		}
		if (hold2 == 7) {
			game[i].face = ace;
		}
		
	}
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
