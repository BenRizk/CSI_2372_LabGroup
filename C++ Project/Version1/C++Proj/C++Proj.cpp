// C++Proj.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <vector>
#include <algorithm>
#include <random>
#include <list>
using namespace std;

//Cards section
class Card {                                            //Card acts as a base class for its children to take from
public:
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
    Chain(istream& is, const CardFactory* fact) {
        return;//TODO add this
    }
    
    /*
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
public:
    vector<Card> getCardList() {
        return cardList;
    }
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
        Deck tempDeck;
        //tempDeck = (*c).getDeck();                 TODO: try to get deck from card factory
        myDeck.emplace_back(NULL);
    }
    Card* draw() {
        Card temp;
        temp = myDeck.back();
        myDeck.pop_back();
        Card* pointTemp = &temp;
        return pointTemp;
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
    void shuffleDeck() {
        auto rng = default_random_engine{};
        shuffle(begin(myDeck), end(myDeck), rng);
    }
};

//Discard Pile Section
class DiscardPile {
    std::vector<Card*> pile;
    int numberOfCards = 0;
public:
    DiscardPile() {
        return;
    }
    DiscardPile(int blue = 0, int chilli = 0, int stink = 0, int green = 0, int soy = 0, int black = 0, int red = 0, int garden = 0) {
        std::vector<Card*> newPile;
        for (int i = 0; i < blue; i++) {
            Blue tempCard;
            newPile.push_back(&tempCard);
        }
        for (int i = 0; i < chilli; i++) {
            Chili tempCard;
            newPile.push_back(&tempCard);
        }
        for (int i = 0; i < stink; i++) {
            Stink tempCard;
            newPile.push_back(&tempCard);
        }
        for (int i = 0; i < green; i++) {
            Green tempCard;
            newPile.push_back(&tempCard);
        }
        for (int i = 0; i < soy; i++) {
            Soy tempCard;
            newPile.push_back(&tempCard);
        }
        for (int i = 0; i < red; i++) {
            Black tempCard;
            newPile.push_back(&tempCard);
        }
        for (int i = 0; i < red; i++) {
            Red tempCard;
            newPile.push_back(&tempCard);
        }
        for (int i = 0; i < garden; i++) {
            Garden tempCard;
            newPile.push_back(&tempCard);
        }
        pile = newPile;
    }
    DiscardPile(istream& a, const CardFactory* b) {//This
        
        int blue = 0;
        int chilli = 0;
        int stink = 0;
        int green = 0;
        int soy = 0;
        int black = 0;
        int red = 0;
        int garden = 0;

        std::string word;
        while (a >> word)
        {
            if (word.compare("B")) { blue += 1; }
            else if (word.compare("C")) { chilli += 1; }
            else if (word.compare("S")) { stink += 1; }
            else if (word.compare("G")) { green += 1; }
            else if (word.compare("S")) { soy += 1; }
            else if (word.compare("b")) { black += 1; }
            else if (word.compare("R")) { red += 1; }
            else if (word.compare("g")) { garden += 1; }
        }
        std::vector<Card*> newPile;
        for (int i = 0; i < blue; i++) {
            Blue tempCard;
            newPile.push_back(&tempCard);
        }
        for (int i = 0; i < chilli; i++) {
            Chili tempCard;
            newPile.push_back(&tempCard);
        }
        for (int i = 0; i < stink; i++) {
            Stink tempCard;
            newPile.push_back(&tempCard);
        }
        for (int i = 0; i < green; i++) {
            Green tempCard;
            newPile.push_back(&tempCard);
        }
        for (int i = 0; i < soy; i++) {
            Soy tempCard;
            newPile.push_back(&tempCard);
        }
        for (int i = 0; i < red; i++) {
            Black tempCard;
            newPile.push_back(&tempCard);
        }
        for (int i = 0; i < red; i++) {
            Red tempCard;
            newPile.push_back(&tempCard);
        }
        for (int i = 0; i < garden; i++) {
            Garden tempCard;
            newPile.push_back(&tempCard);
        }
        pile = newPile;
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
    friend ostream& operator << (ostream&, DiscardPile);

};

class TradeArea {

    list<Card> myList;

public:
    TradeArea() {
        return;
    }
    TradeArea(istream& i, const CardFactory* c) {

    }
    TradeArea& operator+=(Card* c) {
        myList.insert(myList.begin(),*c);
        return;
    }
    bool legal(Card* c) {
        std::list<Card>::iterator myIter;
        for (myIter = myList.begin(); myIter != myList.end(); ++myIter) {
            string comp1 = (*myIter).getName();
            string comp2 = (*c).getName();
            if (comp1._Equal(comp2)) {
                return true;
            }
        }
        return false;
    }
    Card* trade(string temp) {
        std::list<Card>::iterator myIter;
        for (myIter = myList.begin(); myIter != myList.end(); ++myIter) {
            string comp1 = (*myIter).getName();
            if (comp1._Equal(temp)) {
                //return myList.remove((*myIter));                         TODO: find way to turn list element into card pointer
            }
        }
        return NULL;
    }
    int numCards() {
        return myList.size();
    }

};

//Hand section
class Hand {
    std::list<Card*> heldCards;
    int numberOfCards;
public:
    Hand(istream& stream, const CardFactory* fact) {
        numberOfCards = 0;
        return;//TODO: add this section
    }
    Hand& operator += (Card* car) {
        heldCards.push_back(car);
        numberOfCards++;
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
    int getNumberOfCards() {
        return numberOfCards;
    }
    /*  and the interstion operator (friend) to print Hnad on an std::ostream. the hand should print all the cards in order*/
    friend ostream& operator << (ostream&, Hand);
};

//Player Section
class Player {
    string name;
    std::vector<Card*> hand;
    int coins;
public:
    Player(std::string& s) {
        name = s;
        coins = 0;
    };
    Player(std::istream& istream, const CardFactory* myCardFact) {
        //TODO add this
        std::string word, player1Name, player2Name;
        istream >> player1Name;
        istream >> coins;
        /*while (istream >> word)
        {
            if (word.compare("B")) {//TODO:   hand += Blue()        repeat this for all possible cards
            }
            
        }*/
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
    Chain& operator [] (int i);//TODO add this        //return the chain at posistion i
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
    friend ostream& operator << (ostream&, Player);
};

//table Section
class Table {
    Player p1;
    Player p2;
    Deck tableDeck;
    DiscardPile tableDiscard;
    TradeArea tableTradeArea;
    int p1Op2Turn = 1;
    Table() {
        std::string a = "player 1";
        p1 = Player(a);
        std::string b = "player 2";
        p2 = Player(b);
        tableDeck = Deck();
        tableDiscard = DiscardPile(0,0,0,0,0,0,0,0);
        tableTradeArea = TradeArea();
        return;
    }
    Table(istream& is, const CardFactory* cardFact) {
        

        std::string word,player1Name,player2Name;
        is >> player1Name;
        is >> player2Name;
        int blue = 0;
        int chilli = 0;
        int stink = 0;
        int green = 0;
        int soy = 0;
        int black = 0;
        int red = 0;
        int garden = 0;

        while (is >> word)
        {
            if (word.compare("B")) { blue += 1; }
            else if (word.compare("C")) { chilli += 1; }
            else if (word.compare("S")) { stink += 1; }
            else if (word.compare("G")) { green += 1; }
            else if (word.compare("S")) { soy += 1; }
            else if (word.compare("b")) { black += 1; }
            else if (word.compare("R")) { red += 1; }
            else if (word.compare("g")) { garden += 1; }
        }
        DiscardPile(blue, chilli, stink, green, soy, black, red, garden);
        return;
    }
    
    bool win(std::string& playerName) {
        std::string name1 = p1.getName();
        std::string name2 = p2.getName();
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
    }
    /*insertion operator (friend) to print Table to in std::ostream  the 2 players, discard pile, and trading area*/
    friend ostream& operator << (ostream&, Table);
};

class CardFactory {

    Deck tempDeck;
public:

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

    void replaceDeck(Deck newDeck) {
        tempDeck = newDeck;
    }

    Deck getDeck() {
        tempDeck.shuffleDeck();
        return tempDeck;
    }
};

//Friend class section
ostream& operator << (ostream& os, DiscardPile pile){
    os << pile.top();
    return os;
}
ostream& operator << (ostream& os, Hand han) {
    for (int i = 0; i < han.getNumberOfCards(); i++){
        os << han[i];
    }
    return os;
}
ostream& operator << (ostream& os, Chain ch) {
    vector<Card> a = ch.getCardList();
    for (int i = 0; i < a.size(); i++){
        a.at(i).print(os);
    }
    return os;
}
ostream& operator << (ostream& os, Player play) {//prints the player's name, number of coins and each of the chains
    os << play.getName() << "  " << play.getNumCoins()<<" coins/n";
    for (int i = 0; i < play.getNumChains(); i++) {
        os << &play[i]; 
    }
    return os;
}
ostream& operator << (ostream& os, Table tab) {
    os << tab.p1 << tab.p2 << tab.tableDiscard /*<< tab.tableTradeArea                  TODO: THis needs to be uncommented when trade area has an ostream*/;
    /*for (int i = 0; i < tab.size(); i++) {
        a.at(i).print(os);
    }*/
    return os;
}

//Reconstruct function



int main()
{
    Deck gameDeck;
    //Table gameTable;
    string playerNames[2];
    cout << "Enter 1st player name: " << "\n";
    cin >> playerNames[0];
    cout << "Enter 2n player name: " << "\n";
    cin >> playerNames[1];

    //each player draw 5

    while (!gameDeck.isEmpty()) {
        
    }
}

