#pragma once
#include <iostream>
#include"OrderedList.h"
#include"MatchCard.h"
const int DEFAULT_LIST1 = 1;

class MatchPlayer
{
public:
	MatchPlayer(unsigned int playernum = DEFAULT_LIST1);// OrderedList<MatchCard>cardslt);//Constructor
	~MatchPlayer();
	inline int getplayerNUM(void) const { return playernumber; }//
	void sethandCards(MatchCard card);
	int findingMatch(MatchCard samecard);
	MatchCard getSameCard(int index);
	int getnumCards();
	MatchCard getCardtosee(int index);
	//Purpose of each function is defined in the corresponding MatchPlayer cpp file.

private:
	OrderedList<MatchCard>m_cardslist;
	unsigned int playernumber;
	friend std::ostream& operator<<(std::ostream& os, const MatchPlayer &z);//Overloading << operator to print, defined further in cpp file.

};