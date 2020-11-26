// C++Proj.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <vector>
#include <random>
#include <list>
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


class Blue : public Card {  
                             //From Blue to Garden are the different cards that exist in the game and are children of Card  
public :
    Blue() {
        return;
   }
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
public:
    Chili() {
        return;
    }
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
public:
    Stink() {
        return;
    }
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
public:
    Green() {
        return;
    }
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
public:
    Soy() {
        return;
    }
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
public:
    Black() {
        return;
    }
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
public:
    Red() {
        return;
    }
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
public:
    Garden() {
        return;
    }
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
    int numberOfCards;
    CardFactory myCardFactory;
    vector<Card> cardList;
    /*Chain(istream& a, const CardFactory* b) {
        myCardFactory = *b;
    }
    Chain<T>& operator += (Card* newCard) {
        cardList.push_back(newCard);
        numberOfCards += 1;
        return *this
    }
    int sell(){
        int sum = 0;
        int i = 0;
        while (cardList[i] != NULL)
        {
            sum += cardList[i]::getCardsPerCoin();
        }
    }*/
};

//Deck section
class Deck{
public:
    vector<Card> myDeck;

public : 
    
    Deck() {
        return;
    }

    Deck(istream& i, const CardFactory* c) {

    }
    Card* draw() {
        Card* temp;
    }

    void addCard(Card addMe) {
        myDeck.emplace_back(addMe);
    }
    bool isEmpty() {
        if (myDeck.empty()) {
            return true;
        }
        return false;
    }
};

//Discard Pile Section
class DiscardPile {
    std::vector<Card*> pile;
    int numberOfCards = 0;
    DiscardPile(istream& a, const CardFactory* b) {
        //TODO add this, I dont know what should go here
    }
    DiscardPile& operator+=(Card* newCard) {
        pile.push_back(newCard);
        numberOfCards += 1;
    }
    Card* pickup() {
        if (numberOfCards >= 0) {
            Card* temp = pile[numberOfCards];
            pile.erase(pile.begin() + numberOfCards - 1);
            return temp;
        }
        return NULL;
    }
    Card* top() {
        return pile[numberOfCards];
    }
    void print(std::ostream& a) {
        int i;
        for (i = 0; i < numberOfCards; i++) {
            a << pile[i] << endl;
        }
    }
    /*TODO:         insert operator friend to insert only the top caed of the discard to an std::ostream*/
};

class TradeArea {

};

//Hand section
class Hand {
    std::list<Card*> heldCards;
    Hand(istream& stream, const CardFactory* fact) {
        return;//TODO: add this section
    }
    Hand& operator += (Card* car) {
        heldCards.push_back(car);
        return *this;
    }
    Card* play() {
        Card* returnThis = heldCards.front();
        heldCards.pop_front();
        return returnThis;
    }
    Card* top() {
        Card* returnThis = heldCards.front();
        return returnThis;
    }
    Card* operator[] (int num) {
        std::list<Card*>::iterator iter;
        int i;
        if (num < 0) {
            return NULL;
        }
        while (i < num)
        {
            iter++;
            i++;
        }
        Card* returnThis = *iter;
        heldCards.erase(iter);
        return returnThis;
    }
    /*  and the interstion operator (friend) to print Hnad on an std::ostream. the hand should print all the cards in order*/
};

//Player Section
class Player {
    string name;
    std::vector<Card*> hand;
    int coins;
    Player(std::string& s) {
        name = s;
        coins = 0;
    };
    Player(std::istream& istream, const CardFactory* myCardFact) {
        //TODO add this
    }
    std::string getName() {
        return name;
    }
    int getNumCoins() {
        return coins;
    }
    Player& operator += (int newCoins) {
        coins += newCoins;
        return *this;
    }
    int getMaxNumChains() {
        //TODO this is not done at all
        return 2;//this is not final and is a place holder //should return 2 or 3
    }
    int getNumChains() {
        //TODO add this later
        return 1;//this is not final and is a placholder //should return a non-zero number of chains
    }
    Chain& operator [] (int i);//TODO add this        //return the chainat posistion i
    void buyThirdChain(); //TODO add this   //adds a empty 3rd chain to the player for 3 coins. if they do not have enough coins throw NotEnoughCoins Excepetion
    void printHand(std::ostream& stream, bool topOrAll) {
        if (topOrAll) {
            for (Card* n : hand) {
                std::cout << &n << '\n';
            }
        }
        else {
            std::cout << hand.front() << "'\n";
        }
    }
    /*add the insertion operator (friend) to print Player to an std::ostream. prints the player's name, number of coins and each of the chains*/
};

//table Section
class Table {
    Player p1;
    Player p2;
    Deck tableDeck;
    DiscardPile tableDiscard;
    TradeArea tableTradeArea;
    int p1Op2Turn = 1;
    Table(istream& is, const CardFactory* cardFact) {
        //TODO: NOT DONE!!!!!!!!!!!!!
        //p1 = new Player();
        //p2 = new Player();
        return;
    }
    /* TODO: this will not work untill the initalization function is made
    bool win(std::string& playerName) {
        std::string& name1 = p1.getName();
        std::string& name2 = p2.getName();
        if (!playerName.compare(name1) && tableDeck.isEmpty()) {
            return true;
        }else if (!playerName.compare(name2) && tableDeck.isEmpty()) {
            return true;
        }
    }
    void printHand(bool topOrAll) {
        if (p1Op2Turn == 1) {
            p1.printHand(cout, topOrAll);
        }
        else {
            p2.printHand(cout, topOrAll);
        }
    }*/
    /*insertion operator (friend) to print Table to in std::ostream  the 2 players, discard pile, and trading area*/
};

class CardFactory {

    Deck tempDeck;

    CardFactory() {
        for (int i = 0; i < 20; i++) {
            Blue tempCard;
            tempDeck.addCard(tempCard);
        }
        for (int i = 0; i < 18; i++) {
            Chili tempCard;
            tempDeck.addCard(tempCard);
        }
        for (int i = 0; i < 16; i++) {
            Stink tempCard;
            tempDeck.addCard(tempCard);
        }
        for (int i = 0; i < 14; i++) {
            Green tempCard;
            tempDeck.addCard(tempCard);
        }
        for (int i = 0; i < 12; i++) {
            Soy tempCard;
            tempDeck.addCard(tempCard);
        }
        for (int i = 0; i < 10; i++) {
            Black tempCard;
            tempDeck.addCard(tempCard);
        }
        for (int i = 0; i < 8; i++) {
            Red tempCard;
            tempDeck.addCard(tempCard);
        }
        for (int i = 0; i < 6; i++) {
            Garden tempCard;
            tempDeck.addCard(tempCard);
        }
    }

    static CardFactory* getFactory() {
        CardFactory temp;
        CardFactory* tempPoint;
        tempPoint = &temp;

        return tempPoint;
    }

    Deck getDeck() {
        return tempDeck;
    }

};


int main()
{
    std::cout << "Hello World!\n";
}

