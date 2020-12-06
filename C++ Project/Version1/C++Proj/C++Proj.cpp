// C++Proj.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <vector>
#include <algorithm>
#include <random>
#include <list>
#include <typeinfo>
using namespace std;

//Exception Section
class notEnoughCoins : public exception {
    char* ad_text;
public:
    notEnoughCoins(char* text) { ad_text = text; }
    notEnoughCoins() {}
    const char* what() const { return ad_text; }
};


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

//Chain section T
template <class T> class Chain_Base {
protected:
    std::vector<T*> chain;
    Chain_Base(T type) { std::vector<type*> chain; }
};

class Chain : public Chain_Base<Card>{
    
public:
    istream myIstream;
    int numberOfCards;
    CardFactory myCardFactory;
    vector<Card*> cardList;

    Chain() {
        numberOfCards = 0;
        return;
    }

    Chain(istream& is, const CardFactory* fact) {
        
        return;//TODO add this
    }
    
    Card* operator [] (int num){
        return cardList.at(num);
    }
    
    Chain& operator += (Card* newCard) {
        cardList.push_back(newCard);
        numberOfCards += 1;
        return *this;
    }

    int sell(){
        int sum = 0;
        int i = 0;
        Card temp;

        int blue = 0;
        int chilli = 0;
        int stink = 0;
        int green = 0;
        int soy = 0;
        int black = 0;
        int red = 0;
        int garden = 0;

        while (cardList.at(i) != NULL)
        {
            temp = *cardList.at(i);
            if (typeid(temp).name() == "Blue") {
                blue += 1;
            }
            else if (typeid(temp).name() == "Chilli") {
                chilli += 1;
            }
            else if (typeid(temp).name() == "Stink") {
                stink += 1;
            }
            else if (typeid(temp).name() == "Green") {
                green += 1;
            }
            else if (typeid(temp).name() == "Soy") {
                soy += 1;
            }
            else if (typeid(temp).name() == "Black") {
                black += 1;
            }
            else if (typeid(temp).name() == "Red") {
                red += 1;
            }
            else if (typeid(temp).name() == "Garden") {
                garden += 1;
            }
            i++;
        }
        i = 0;
        
         sum += temp.getCardsPerCoin(blue);
         sum += temp.getCardsPerCoin(blue);
         sum += temp.getCardsPerCoin(blue);
         sum += temp.getCardsPerCoin(blue);
         sum += temp.getCardsPerCoin(blue);
         sum += temp.getCardsPerCoin(blue);
         sum += temp.getCardsPerCoin(blue);
         sum += temp.getCardsPerCoin(blue);
        
    }

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

    Deck(istream& a, const CardFactory* c) {
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
        for (int i = 0; i < blue; i++) {
            Blue tempCard;
            myDeck.push_back(tempCard);
        }
        for (int i = 0; i < chilli; i++) {
            Chili tempCard;
            myDeck.push_back(tempCard);
        }
        for (int i = 0; i < stink; i++) {
            Stink tempCard;
            myDeck.push_back(tempCard);
        }
        for (int i = 0; i < green; i++) {
            Green tempCard;
            myDeck.push_back(tempCard);
        }
        for (int i = 0; i < soy; i++) {
            Soy tempCard;
            myDeck.push_back(tempCard);
        }
        for (int i = 0; i < red; i++) {
            Black tempCard;
            myDeck.push_back(tempCard);
        }
        for (int i = 0; i < red; i++) {
            Red tempCard;
            myDeck.push_back(tempCard);
        }
        for (int i = 0; i < garden; i++) {
            Garden tempCard;
            myDeck.push_back(tempCard);
        }

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

//Discard Pile Section T
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

    DiscardPile(istream& a, const CardFactory* b) {
        
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

//Trade Area Section T
class TradeArea {

public:
    list<Card> myList;


    TradeArea() {
        return;
    }

    TradeArea(istream& a, const CardFactory* c) {
        int blue = 0;
        int chilli = 0;
        int stink = 0;
        int green = 0;
        int soy = 0;
        int black = 0;
        int red = 0;
        int garden = 0;

        std::string word;
        while (a >> word){
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
            myList.push_back(tempCard);
        }
        for (int i = 0; i < chilli; i++) {
            Chili tempCard;
            myList.push_back(tempCard);
        }
        for (int i = 0; i < stink; i++) {
            Stink tempCard;
            myList.push_back(tempCard);
        }
        for (int i = 0; i < green; i++) {
            Green tempCard;
            myList.push_back(tempCard);
        }
        for (int i = 0; i < soy; i++) {
            Soy tempCard;
            myList.push_back(tempCard);
        }
        for (int i = 0; i < red; i++) {
            Black tempCard;
            myList.push_back(tempCard);
        }
        for (int i = 0; i < red; i++) {
            Red tempCard;
            myList.push_back(tempCard);
        }
        for (int i = 0; i < garden; i++) {
            Garden tempCard;
            myList.push_back(tempCard);
        }
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
                    Card* ret = &myList.front();
                    myList.remove(*myIter);
                return ret;
            }
        }
        return NULL;
    }

    int numCards() {
        return myList.size();
    }

};

//Hand section T
class Hand {
    std::list<Card*> heldCards;
    int numberOfCards;
public:
    Hand(istream& stream, const CardFactory* fact) {
        numberOfCards = 0;
        int blue = 0;
        int chilli = 0;
        int stink = 0;
        int green = 0;
        int soy = 0;
        int black = 0;
        int red = 0;
        int garden = 0;

        std::string word;
        while (stream >> word)
        {
            if (word.compare("B")) { blue += 1; }
            else if (word.compare("C")) { chilli += 1; numberOfCards += 1; }
            else if (word.compare("S")) { stink += 1; numberOfCards += 1;}
            else if (word.compare("G")) { green += 1; numberOfCards += 1;}
            else if (word.compare("S")) { soy += 1; numberOfCards += 1;}
            else if (word.compare("b")) { black += 1; numberOfCards += 1;}
            else if (word.compare("R")) { red += 1; numberOfCards += 1;}
            else if (word.compare("g")) { garden += 1; numberOfCards += 1;}
        }
        for (int i = 0; i < blue; i++) {
            Blue tempCard;
            heldCards.push_back(&tempCard);
        }
        for (int i = 0; i < chilli; i++) {
            Chili tempCard;
            heldCards.push_back(&tempCard);
        }
        for (int i = 0; i < stink; i++) {
            Stink tempCard;
            heldCards.push_back(&tempCard);
        }
        for (int i = 0; i < green; i++) {
            Green tempCard;
            heldCards.push_back(&tempCard);
        }
        for (int i = 0; i < soy; i++) {
            Soy tempCard;
            heldCards.push_back(&tempCard);
        }
        for (int i = 0; i < red; i++) {
            Black tempCard;
            heldCards.push_back(&tempCard);
        }
        for (int i = 0; i < red; i++) {
            Red tempCard;
            heldCards.push_back(&tempCard);
        }
        for (int i = 0; i < garden; i++) {
            Garden tempCard;
            heldCards.push_back(&tempCard);
        }
        return;
    }

    Hand() {
        numberOfCards = 0;
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

//Player Section T
class Player {
public:
    string name;
    std::vector<Card*> hand;
    int coins;
<<<<<<< HEAD
    int numberOfChains;
    std::vector<Chain> playerChains;

public:
=======


    Player() {
        name = "default";
        coins = 0;
    }
>>>>>>> 18961d8e09748b45f6acfff19b1611252c418c17

    Player(std::string& s) {
        name = s;
        coins = 0;
        playerChains.push_back(Chain());
        playerChains.push_back(Chain());
        numberOfChains = 2;
    };

    Player(std::istream& istream, const CardFactory* myCardFact) {
        std::string word, player1Name, player2Name;
        istream >> player1Name;
        istream >> coins;
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
        return playerChains.size();
    }

    int getNumChains() {
        return numberOfChains;
    }

    Chain& operator [] (int i) {
        return playerChains.at(i);
    }

    void buyThirdChain() {
         if (coins < 3) { throw notEnoughCoins("Not enough coins"); }//TODO
         coins -= 3;
    } 

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

//table Section T
class Table {
public:
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

//card factory
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

//Friend class section T
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
ostream& operator << (ostream& os, TradeArea trade) {
    std::list<Card>::iterator it = trade.myList.begin();
    for (int i = 0; i < trade.numCards(); i++) {
        os << &it;
        std::next(it, 1);
    }
    return os;
}
ostream& operator << (ostream& os, Table tab) {
    os << tab.p1 << tab.p2 << tab.tableDiscard << tab.tableTradeArea;
    
    return os;
}

<<<<<<< HEAD

=======
//Reconstruct function
>>>>>>> 18961d8e09748b45f6acfff19b1611252c418c17

int main()
{
    Deck gameDeck;
    Table gameTable;
    vector<Player> p1(2);
    string playerNames[2];
    TradeArea trader;
    string decision;
    int temp;
    Card *tempCard;
    cout << "Enter 1st player name: " << "\n";
    cin >> playerNames[0];
    cout << "Enter 2n player name: " << "\n";
    cin >> playerNames[1];

    //each player draw 5
    gameTable.p1.hand.push_back(gameTable.tableDeck.draw());
    gameTable.p1.hand.push_back(gameTable.tableDeck.draw());
    gameTable.p1.hand.push_back(gameTable.tableDeck.draw());
    gameTable.p1.hand.push_back(gameTable.tableDeck.draw());
    gameTable.p1.hand.push_back(gameTable.tableDeck.draw());
   
    gameTable.p2.hand.push_back(gameTable.tableDeck.draw());
    gameTable.p2.hand.push_back(gameTable.tableDeck.draw());
    gameTable.p2.hand.push_back(gameTable.tableDeck.draw());
    gameTable.p2.hand.push_back(gameTable.tableDeck.draw());
    gameTable.p2.hand.push_back(gameTable.tableDeck.draw());
    
    while (!gameTable.tableDeck.isEmpty()) {
        for (int i = 0; i < 2; i++) {           //for each player
             //display table
            if (i == 0) {
                //player 1 draws
                gameTable.p1.hand.push_back(gameTable.tableDeck.draw());
            }
            else {
                //player 2 draws
                gameTable.p2.hand.push_back(gameTable.tableDeck.draw());
            }
           
            if (gameTable.tableTradeArea.numCards() == 0) {
                //trade area places card into Dpile or chain

            }
           
            if (i == 0) {
                //player 1 plays card
               // gameTable.p1.hand.at(gameTable.p1.hand.size())
            }
            else {
                //player 2 plays card
                // gameTable.p2.hand.at(gameTable.p1.hand.size())
            }
            
            // if played card ends chain player gets points

            if (i == 0) {
                //player 1 decides to play topmost card
                cout << "Would you like to play another card?(y/n)";
                cin >> decision;
                if (decision._Equal("y")) {
                    // gameTable.p1.hand.at(gameTable.p1.hand.size())
                }
            }
            else {
                //player 2 decides to play topmost card
                cout << "Would you like to play another card?(y/n)";
                cin >> decision;
                if (decision._Equal("y")) {
                    // gameTable.p2.hand.at(gameTable.p1.hand.size())
                }
            }
            // if played card ends chain player gets points
            if (i == 0) {
                //player 1 decides to show hand
                cout << "do you want to show your hand to discard a card?(y/n)";
                cin >> decision;
                if (decision._Equal("y")) {
                    //choose card to discard
                     //choose card to discard
                    cout << "Choose a card in your hand to discard. (1,2,3,4,etc.)";
                    cin >> temp;
                    tempCard = gameTable.p1.hand.at(temp);            //take card from player hand and place into discard pile
                    gameTable.tableDiscard += tempCard;
                }
            }
            else {
                //player 2 decides to show hand
                cout << "Do you want to show your hand to discard a card?(y/n)";
                cin >> decision;
                if (decision._Equal("y")) {
                    //choose card to discard
                    cout << "Choose a card in your hand to discard. (1,2,3,4,etc.)";
                    cin >> temp;
                    tempCard = gameTable.p2.hand.at(temp);            //take card from player hand and place into discard pile
                    gameTable.tableDiscard += tempCard;
                }
            }

            //place three card into trade area from deck
                
            while ((gameTable.tableDiscard.top())._Equal(gameTable.tableTradeArea.myList.begin())) {         //while top card of discard pile matches top card of trade area
                //take top cord of Dpile and place in trade area
                gameTable.tableTradeArea.myList.emplace_back(gameTable.tableDiscard.top());
            }
            std::list<Card>::iterator myIter;
            for (myIter = gameTable.tableTradeArea.myList.begin(); myIter != gameTable.tableTradeArea.myList.end(); ++myIter) { //iterate throught all cards in trade area
                if (i == 0) {

                    //player 1 decides to chain the card
                    cout << "Would you like to chain the card?(y/n)";
                    cin >> decision;
                    if (decision._Equal("y")) {
                        //place player 1 card into chain
                    }

                }
                else {
                    //player 2 decides to to chain the card
                    cout << "Would you like to chain the card?(y/n)";
                    cin >> decision;
                    if (decision._Equal("y")) {
                        //place player 2 card into chain
                    }
                }
            }
            
            if (i == 0) {
                //player 1 draws
                gameTable.p1.hand.push_back(gameTable.tableDeck.draw());
                gameTable.p1.hand.push_back(gameTable.tableDeck.draw());
            }
            else {
                //player 2 draws
                gameTable.p2.hand.push_back(gameTable.tableDeck.draw());
                gameTable.p2.hand.push_back(gameTable.tableDeck.draw());
            }


        }

    }
}

