/*CardsSet.h*/
class CardsSet { 
	public:
		CardsSet() : number(0) {}
		void novSet(); 
		void shuffle(); 
		int numCards() { return number; }
		card take(); 
		void put(Card k); 
		Card lookIn(int no); 
		void empty() { number = 0; }
	private: 
		Cardset[52]; 
		int number; 
};