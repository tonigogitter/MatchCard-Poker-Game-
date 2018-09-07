#pragma once
#include"MatchCard.h"
#include"MatchPlayer.h"
#include"OrderedList.h"
#include"List.h"
#include<iostream>
#include"Queue.h"
#include"Stack.h"
#include"StandardFunctors.h"
#include<ctime>
using namespace std;


class MatchGame
{
public: 
	MatchGame(int userRank, int numplayers);
	~MatchGame();
	void play(void);
	


private:
	int maxRank1;
	int numPlayers1;
	Stack<MatchCard>faceup1;// Face up Pile
	Queue<MatchCard>deck1;// Deck
	MatchCard *m_array;// Temporary array1
	MatchCard*BigCardPile;// Temporary array2
	MatchPlayer*playersheet;//Container of MatchPlayers involved in this Match Card Game.





};