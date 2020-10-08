// myFile1b.cpp : This file contains the 'main' function. Program execution begins and ends there.
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
typedef Card Hand[5];
bool testPair(const Hand& h)
{
	int card1;
	int card2;
	for (int i = 0; i < 5; i++) {					//compare each card in hand by iteration
		for (int j = 0; j < 5; j++) {
			if (h[i].color == h[j].color && h[i].face == h[j].face) { // if two cards match return true
				return true;
			}
		}
	}
	return false;// if no matches return false
}

/*Example of main()*/
int main()
{
	bool testPair(const Hand&);
	Hand myHand = {};
	cout << "\nI have at least:" << testPair(myHand) << "pair" << endl;
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
