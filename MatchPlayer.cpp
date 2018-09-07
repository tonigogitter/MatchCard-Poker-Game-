#include "MatchPlayer.h"
#include "MatchCard.h"

MatchPlayer::MatchPlayer(unsigned int playernum)//Constructor

{
	playernumber=playernum;
}

// destructor
MatchPlayer::~MatchPlayer()
{
}

//Overloaded operator to printing player's name such as Player 1, Player 2 and so on. And Printing Player's hand is done directly in the play method in MatchGame.
std::ostream& operator<<(std::ostream& os, const MatchPlayer &z) {
	os << "Player "<< z.getplayerNUM();
	return os;

}

//To get a card to insert into the ordered list of a Player's hand
void MatchPlayer:: sethandCards(MatchCard card) {
	m_cardslist.insert(card);
}

//This returns the index of a MatchCard in a player's hand that matches the MatchCard passed into this function from suppose a faceup pile in match game (i.e).
int MatchPlayer::findingMatch(MatchCard samecard) {
	int index = 1;
	for (index; index<=m_cardslist.getLength();index++){
		if ((m_cardslist.retrieve(index).getRank()) == (samecard.getRank())){
			return index;
		}
		else if (m_cardslist.retrieve(index).getSuit() == samecard.getSuit()){
			return index;
		}
	}
	return -1;
}

//Get the MatchCard which is removed from the players hand, which is the card that was similar to the face up pile
MatchCard MatchPlayer::getSameCard(int index) {
	return m_cardslist.remove(index);
}

//Gets the size or number of cards in a players hand ordered list.
int MatchPlayer::getnumCards() {
	return m_cardslist.getLength();
}

//Just retrieves the matchcard with indexed passed in to see the MatchCard in nth place in a player's ordered list hand of MatchCards.
MatchCard MatchPlayer::getCardtosee(int index) {
	return m_cardslist.retrieve(index);
}

