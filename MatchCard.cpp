
#include "MatchCard.h"


MatchCard::MatchCard(Suit suit, int rank) {
	m_suit = suit;
	 Rank = rank;

}

// destructor
MatchCard::~MatchCard()
{
}

char MatchCard::toCharSuit()
{
	if (m_suit == HEARTS)   return 'H';
	else if (m_suit == CLUBS)    return 'C';
	else if (m_suit == SPADES)   return 'S';
	else                       return 'D';
}


std::ostream& operator<<(std::ostream& os, const MatchCard &c) {
	int suit = c.getSuit();
	int rank = c.getRank();// Insert Rank
	if (rank == 1)
		os << "Ace";
	else
	os << rank;// Prints number of rank of the card then the suit of the card 

	switch (suit) {
	case 1:
		os <<" of Spades";
		break;
	case 2:
		os << " of Hearts";
		break;
	case 3:
		os << " of Clubs";
		break;
	default:
		os << " of Diamonds";
	}
	return os;
}