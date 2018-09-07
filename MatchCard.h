#pragma once
#include <iostream>

// User defined Suit and Denomination types (user-defined integers) 
enum Suit { SPADES = 1, HEARTS = 2, CLUBS = 3, DIAMONDS = 4 };



class MatchCard
{
public:
	MatchCard(Suit suit = HEARTS, int rank = 1); // constructor with some default values
	~MatchCard(); // destructor
	inline Suit getSuit(void) const { return m_suit; }
	inline int getRank(void)const { return Rank; }
	char toCharSuit(void); // returns a char that "describes" card's suit
	

	
private:
	Suit m_suit; // private storage of suit

	int Rank; // private storage of Rank
	friend std::ostream& operator<<(std::ostream& os, const MatchCard &c);
};

// global operator functions comparing suits and the rank number of each card
// The cards a and b are passed by reference
inline bool operator<(const MatchCard& a, const MatchCard& b) {
	if (a.getSuit() == b.getSuit()) return (a.getRank()<b.getRank());
	else                            return (a.getSuit()<b.getSuit());
}
inline bool operator>(const MatchCard& a, const MatchCard& b) {
	if (a.getSuit() == b.getSuit()) return (a.getRank()>b.getRank());
	else                            return (a.getSuit()>b.getSuit());
}

// checks equality of suits and ranks for two cards
inline bool operator==(const MatchCard &a,const MatchCard  &b) { return (a.getRank() == b.getRank() && a.getSuit() == b.getSuit()); }

