#include"MatchGame.h"
#include"MatchCard.h"
#include"Queue.h"

MatchGame::MatchGame(int userRank, int numplayers) {
	//A Done----Create all the cards place them in an array- WORKS
	maxRank1 = userRank;
	numPlayers1 = numplayers;

	BigCardPile = new MatchCard[(maxRank1 * 4) + 1];
	int w = 1;
	for (int i = 0; i < (maxRank1); i++) {
		BigCardPile[i] = MatchCard(HEARTS, w);
		w++;
	}

	int v = 1;
	for (int i = (maxRank1); i < (maxRank1 * 2); i++) {
		BigCardPile[i] = MatchCard(CLUBS, v);
		v++;
	}

	int s = 1;
	for (int i = (maxRank1 * 2); i < (maxRank1 * 3); i++) {
		BigCardPile[i] = MatchCard(SPADES, s);
		s++;
	}

	int u = 1;
	for (int i = (maxRank1 * 3); i < (maxRank1 * 4); i++) {
		BigCardPile[i] = MatchCard(DIAMONDS, u);
		u++;
	}

	//B Done----Cards Being Taken from the array (created above) randomly (until empty) and placed into a queue that represents the deck pile-WORKS

	deck1 = maxRank1 * 4;
	//Queue now works, enque, deque, peek
	//Stack Works perfectly with peek,push and pop.
	const int  m_size = maxRank1 * 4;
	srand(time(NULL));
	m_array = new MatchCard[m_size];


	for (int i = 0; i < m_size; i++) {
		//chose a random index from our tmp array of VALID data
		int ix = rand() % (m_size - i);
		m_array[i] = BigCardPile[ix];
		//move the last element in our tmp array to the remove element position
		BigCardPile[ix] = BigCardPile[m_size - i - 1];


	}
	//Just for Printing the Deck before being enqueued or dequeued or else would have been hard to access.
	cout << "This is the starting full Deck of Cards" << endl;
	for (int i = 0; i < m_size; i++) {
		cout << m_array[i] << endl;


	}

	//WORKS WORKS WORKS, QUEUE Officialy Works, all is being added in. Check
	for (int i = 0; i < m_size; i++) {

		deck1.enqueue(m_array[i]);

	}


	//C Done----Creates an array of players (Playersheet is the container) with the size of numplayers. In this the match player is only intiated with their number. 
	cout << endl;
	cout << "*****************************************************************************" << endl;
	cout << "Here are the players HANDS, check it out to keep track." << endl;
	cout << "Have fun and let the games begin" << endl;
	cout << "*****************************************************************************" << endl;
	cout << endl;
	playersheet = new MatchPlayer[numPlayers1];
	for (int i = 0; i < numPlayers1; i++) {
		cout << endl;
		playersheet[i] = (i + 1);
		cout << playersheet[i] << endl;
		unsigned int a = 6;
		for (unsigned int y = 1; y <= a; y++) {
			playersheet[i].sethandCards(deck1.dequeue());
		}
		
		for (int x = 1; x <= 6; x++) {
			cout << playersheet[i].getCardtosee(x) << endl;
		}

		//D Done----To put cards in their hand, calling gethand function which calls the setter function for the orderlist of hand in matchplayer, and passes in a match card from deckpile queue looping n (6 number of times-cards number).
	}

	faceup1 = userRank * 4;
	
	faceup1.push(deck1.dequeue());
		//E Done----Draw a starting card for the faceup pile.
}

// destructor
MatchGame::~MatchGame()
{
}

void MatchGame::play(void)
{
	
		cout << "Start" << endl;
		cout << "Face up Card to start is " << faceup1.peek() << endl;
		
		int out = 1;
		//Looping turns until 
			while (true) {
				//Creating a turn
				for (int i = 0; i < numPlayers1; i++) {
					cout << endl;
					cout << "It is " << playersheet[i] << "'s turn" << endl;
					cout<<"This is currently "<< playersheet[i] << "'s hand" << endl;//Prints Players Hand each time.
					cout << "///////////////////////////////" << endl;
						for (int x = 1; x <= playersheet[i].getnumCards(); x++) {
							cout << playersheet[i].getCardtosee(x) << endl;
						}
				

					cout << "///////////////////////////////" << endl;
					cout << endl;

					int matchcardindex = playersheet[i].findingMatch(faceup1.peek());// Finds which card in a player's hand matches the card facing up in the face up pile
					//If a match is not found then an arbitrary index of -1 is found and that player draws a card from deck into their hand.
					if (matchcardindex == -1) {
						cout << playersheet[i] << " did not find a match. They drew a card" << endl;
						playersheet[i].sethandCards(deck1.dequeue());
					}
					//If not then player will remove their card that was similar and pass that directly to be pushed out 
					else {
						faceup1.push(playersheet[i].getSameCard(matchcardindex));
						cout << playersheet[i] << " found a match! They played " << faceup1.peek() << endl;
					}




					//Next independent condition, if deck is empty then save the top card on the faceup pile then move all the face up piles to deck to repopulate.
					//Then add the top card back.
					if ((deck1.isEmpty()) == true) {
						MatchCard tempCard = faceup1.pop();
						for (int i=0;i<faceup1.size();i++)
						{
							deck1.enqueue(faceup1.pop());
						}
						faceup1.push(tempCard);

						cout << "The deck has been repopulated" << endl;

					}



					//If player has one card left, yell one card left
					if (playersheet[i].getnumCards() == 1) {
						cout << playersheet[i] << "  yells Last-Card!" << endl;
					}
					//Or if the player has no cards in their hand then they have won and break out of this for loop and the while loop using an if statement to exit this play method. 
					else if (playersheet[i].getnumCards() == 0) {
						cout << playersheet[i] << " has crushed their enemies in MATCH (not even close)" << endl;
						out = 10;
						break;
					}
					cout << endl;
					cout << "*******************************" << endl;
					cout << "Face up Card now is " << faceup1.peek() << endl;// Updating FaceupPile's first top card each turn to let user's know for their convience to see if it matches players's  input card from hand.
					cout << "*******************************" << endl;

				}
				if (out == 10)
					break;
				

			}
		}
	


// Making sure it's utility doesn't cause functionality failure.
class MyFunctor {
public:
	template<class T>
	static bool compare(const T& a, const T& b) {
		if (a == NULL) return false; // CONVENTION: NULL pointer is "greater" than other pointers 
		else if (b == NULL) return true; // NOTE: returns false is both pointers are NULL
		else return a->getRank() < b->getRank(); // for non NULL pointers we compare objects they point at
	}

};
