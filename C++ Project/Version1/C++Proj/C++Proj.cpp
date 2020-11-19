// C++Proj.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <vector>
using namespace std;

//Cards section
class Card {                                            //Card acts as a base class for its children to take from
    virtual int getCardsPerCoin(int coins) {
    }
    virtual string getName() {
    }
    virtual void print(ostream& out) {

    }
};


class Blue : public Card {                               //From Blue to Garden are the different cards that exist in the game and are children of Card  
    string getName() {
        return "Blue";
    }                          // They have a name, points, and print function
    int getCardsPerCoin(int coins) {
        if (coins == 1) {
            return 4;
        }
        else if (coins == 2) {
            return 6;
        }
        else if (coins == 3) {
            return 8;
        }
        else if (coins == 4) {
            return 10;
        }
        else {
            return 100;
        }
    }
    void print(ostream& out) {
        out.put('B');
    }
};

class Chili : public Card {
    string getName() {
        return "Chili";
    }
    int getCardsPerCoin(int coins) {
        if (coins == 1) {
            return 3;
        }
        else if (coins == 2) {
            return 6;
        }
        else if (coins == 3) {
            return 8;
        }
        else if (coins == 4) {
            return 9;
        }
        else {
            return 100;
        }
    }
    void print(ostream& out) {
        out.put('C');;
    }
};

class Stink : public Card {
    string getName() {
        return "Stink";
    }
    int getCardsPerCoin(int coins) {
        if (coins == 1) {
            return 3;
        }
        else if (coins == 2) {
            return 5;
        }
        else if (coins == 3) {
            return 7;
        }
        else if (coins == 4) {
            return 8;
        }
        else {
            return 100;
        }
    }
    void print(ostream& out) {
        out.put('S');;
    }
};

class Green : public Card {
    string getName() {
        return "Green";
    }
    int getCardsPerCoin(int coins) {
        if (coins == 1) {
            return 3;
        }
        else if (coins == 2) {
            return 5;
        }
        else if (coins == 3) {
            return 6;
        }
        else if (coins == 4) {
            return 7;
        }
        else {
            return 100;
        }
    }
    void print(ostream& out) {
        out.put('G');;
    }
};

class Soy : public Card {
    string getName() {
        return "Soy";
    }
    int getCardsPerCoin(int coins) {
        if (coins == 1) {
            return 2;
        }
        else if (coins == 2) {
            return 4;
        }
        else if (coins == 3) {
            return 5;
        }
        else if (coins == 4) {
            return 7;
        }
        else {
            return 100;
        }
    }
    void print(ostream& out) {
        out.put('S');;
    }
};

class Black : public Card {
    string getName() {
        return "Black";
    }
    int getCardsPerCoin(int coins) {
        if (coins == 1) {
            return 2;
        }
        else if (coins == 2) {
            return 4;
        }
        else if (coins == 3) {
            return 5;
        }
        else if (coins == 4) {
            return 6;
        }
        else {
            return 100;
        }
    }
    void print(ostream& out) {
        out.put('b');;
    }
};

class Red : public Card {
    string getName() {
        return "Red";
    }
    int getCardsPerCoin(int coins) {
        if (coins == 1) {
            return 2;
        }
        else if (coins == 2) {
            return 3;
        }
        else if (coins == 3) {
            return 4;
        }
        else if (coins == 4) {
            return 5;
        }
        else {
            return 100;
        }
    }
    void print(ostream& out) {
        out.put('R');;
    }
};

class Garden : public Card {
    string getName() {
        return "Garden";
    }
    int getCardsPerCoin(int coins) {
        if (coins == 1) {
            return NULL;
        }
        else if (coins == 2) {
            return 2;
        }
        else if (coins == 3) {
            return 3;
        }
        else if (coins == 4) {
            return NULL;
        }
        else {
            return 100;
        }
    }
    void print(ostream& out) {
        out.put('g');;
    }
};

//Chain section
template <class T> class Chain_Base {
protected:
    std::vector<T*> chain;
    Chain_Base(T type) { std::vector<type*> chain; }
};

class Chain {
    istream myIstream;
    CardFactory myCardFactory;
    /*Chain(istream& a, const CardFactory* b) {
        myCardFactory = *b;
    }
    Chain<T>& operator += (Card*) {
        return this;
    }
    int sell(){
        int sum = 0;
        for each (object card in myCardFactory)
        {
            sum += card::getCardsPerCoin();
        }
    }*/
};



class Deck : public std::vector<Card>{

    Deck(istream& i, const CardFactory* c) {
        
    }
    Card* draw() {

    }
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
