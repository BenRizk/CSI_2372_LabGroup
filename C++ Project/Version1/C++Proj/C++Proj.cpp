// C++Proj.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
using namespace std;

//Cards section
class Card {
    string cardName;
    virtual int getCardsPerCoin(int coins);
    virtual string getName();
    virtual void print(ostream& out);
    /*
    TODO: a global stream insertion operator for printing any objects of such a class which implements the �Virtual Friend Function Idiom� with the class hierarch
    */
};

class Blue: Card {/*this eneds to be copied into the class of Chili, Stink, Green, soy, red and garden*/
    string cardName;
    int getCardsPerCoin(int coins) {
        switch (coins)
        {
        case 1:
            return 4;
        case 2:
            return 6;
        case 3:
            return 8;
        case 4:
            return 10;
        }
    }
    string getName() { return "Blue"; };
    void print(ostream& out) {
        cout << &out << " B" ;
    }
};


//Chain section
class Chain {

};

class Deck{

};

class DiscardPile {

};

class TradeArea {

};

class Hand {

};

class Player {

};


class Table {

};

class CardFactory {

};


int main()
{
    std::cout << "Hello World!\n";
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
