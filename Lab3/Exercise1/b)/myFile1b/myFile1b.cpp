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
	Card first;
	first.color = club;
	first.face = seven;
	Card second;
	second.color = spades;
	second.face = ten;
	Card third;
	third.color = heart;
	third.face = ace;
	Card fourth;
	fourth.color = club;
	fourth.face = queen;
	Hand myHand = {first, second, third, second, fourth};
	bool testPair(const Hand&);
	
	cout << "\nI have at least: " << testPair(myHand) << " pair" << endl;
	return 0;
}
