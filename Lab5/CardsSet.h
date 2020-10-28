/*CardsSet.h*/
#include <stdio.h>      
#include <stdlib.h>
class CardsSet { 
	public:
		CardsSet() : number(0) {}
		void novSet(); 
		void shuffle(); 
		int numCards() { return number; }
		Card take(); 
		void put(Card k); 
		Card lookIn(int no); 
		void empty() { number = 0; }
	private: 
		Card set[52]; 
		int number; 

void novSet() {
	Card *pointer = set;
	for (int i = 0; i < 52; i++) {
		int value = ((rand() % 13) + 1);
		int decide = rand() % 4;
		color temp = club;
		if (decide = 0) {
			temp = club;
		}
		if (decide = 1) {
			temp = diamond;
		}
		if (decide = 2) {
			temp = heart;
		}
		if (decide = 3) {
			temp = spade;
		}
		Card myCard = Card(temp, value);
		set[i] = myCard;
		number++;
	}
	return;
}
void shuffle() {
	for (int i = 0; i < number; i++) {
		Card holdMe = set[i];
		int someNumber = rand() % number;
		set[i] = set[someNumber];
		set[someNumber] = holdMe;
	}
	return;
}

Card take() {
	Card returnMe = set[number];
	Card replace = Card(club, 1);
	set[number] = replace;
	number--;
	return returnMe;
}

void put(Card me) {
	set[number] = me;
	number--;
	return;
}

Card lookIn(int num = 1) {
	return set[num];
}

};

