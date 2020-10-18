// Exercise2.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <string>
using namespace std;
#include "SetInt.h"

class SetInt {
	int size;
	int* set;
	
public:
	SetInt() {
		size = 0;
		set = NULL;

	}

	SetInt(int arr[], int length) {
		size = length;
		set = arr;
	}

	~SetInt() {
		size = 0;
		delete set;
	}

	void add(int input) {
		*(set + size + 1) = input;
		size++;
	}

	void remove(int input) {
		for(int i = 0;i < size; i++){
			if (*(set + i) == input) {
				*(set + i) = 0;
				size--;
			}
		}
		
	}
	bool contains(int input) {
		for (int i = 0;i < size; i++) {
			if (*(set + i) == input) {
				return true;
			}
		}
		return false;
	}
	int nbElem() {
		return size;
	}
	int* tabElem() {
		if (set != NULL) {
			return set;
		}
		return NULL;
	}
private:
	bool containsAux(int num, int& pos) {
		for (int i = 0;i < size; i++) {
			if (*(set + i) == num && i == pos) {
				return true;
			}
		}
		return false;
	}
};



int main() {

	SetInt a; // object creation
	int hold;
	while (true)
	{
		cout << "add an element" << "\n";
		cin >> hold;
		a.add(hold);
		cout << "add an other element" << "\n";
		cout << "(Y)es/(N)o :" << "\n";
		string chain;
		getline(cin, chain);// reads a sequence of characters ending with an end of line and store it in the chain
		 //object (end of line not included)
		if (chain[0] == 'n' || 'N')break;
	}
	return 0;
}

