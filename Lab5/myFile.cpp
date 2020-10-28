/*FilemyFile.cpp*/
#include "myFile.h"
#include "Player.h"
#include "CardsSet.h"
#include "Card.h"

#include <iostream>
using namespace std; 
#include <cstdlib>
#include <ctime>
#include <cassert>

int main(){
	CardsSet packet;
	Player you(packet, false);
	Player me(packet, true);
	char answer[3];
	bool cont = true;
	cout << "Hello!"<< endl;
	while (cont)
	{
		cout << "A new game?"<< endl;
		cin >> answer;
		cont = answer[0]=='y';
		if (cont)
			{
			packet.novSet();
			packet.shuffle();
			int p1 = you.play();
			if (p1> 21)
				cout << "You lost!"<< endl;
			else if (p1 == 21)
				cout << "You won!"<< endl;
			else // the computer must play
				{
				int p2 = me.play();
				if (p2 <= 21 && p2 >= p1)
					cout << "You lost!"<< endl;
				else
					cout << "You won!"<< endl;
			}
		}
	}
	return 0;
}