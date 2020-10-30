/* Player.h*/  
class Player {
	public:
		Player(CardsSet& cardPacket, bool isComputer) : packet(cardPacket), computer(isComputer) {}
		int play() {
			cout << "here is your first card";
			Card temp = packet.take();
			temp.write();
			inHand.put(temp);
			bool keepGoing = true;
			string answer;
			while (keepGoing)
			{
				cout << "would you like to draw another card? (Y/N)" << endl;
				cin >> answer;
				if (answer.compare("N") == 1) {
					keepGoing = false;
					break;
				}
				temp = packet.take();
				temp.write();
				inHand.put(temp);
			}
			return countPoints()
		}
	private:
		CardsSet inHand; 
		CardsSet& packet; 
		const bool computer; 
		int countPoints() {
			CardsSet handCopy = inHand;
			Card temp;
			int sum = 0;
			while (handCopy.number > 0)
			{
				temp = handCopy.take();
				sum += temp.val;
			}
			return sum;
		}
};