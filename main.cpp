#include"MatchCard.h"
#include"MatchGame.h"
#include"MatchPlayer.h"
#include"OrderedList.h"
#include"List.h"
#include<iostream>
#include"Queue.h"
#include"Stack.h"
#include"StandardFunctors.h"
#include<ctime>
using namespace std;


int main()
{


	cout << "Welcome to the MATCH" << endl;
	unsigned int userRank2 = 40;//
	cout << "This a card game, please specify your maximum card size: ";
	cin >> userRank2;

	int numplayers2 = 2;//
	cout << "How many players are playing" << endl;
	cin >> numplayers2;

	//These two statements above ask user for their inputs on maximum rank and number of players.
	//And checks them with the while loop condition below and if userRank x 4 (suits) is less than or equal to numplayer x 6 [basically if not enough cards to distribute into each player's hand 6 times with at least one left over for the face up pile)
	//If doesn't meet that condition keep asking for the two inputs until it meets the condition.

	while ((userRank2 * 4) <= (numplayers2 * 6)) {
		cout << "Please re enter: " << endl;

		cout << "This a card game, please specify your maximum card size: ";
		cin >> userRank2;

			cout << "How many players are playing" << endl;
		cin >> numplayers2;

	}

	//creates a MatchGame object called game1 with parameters of user inputs of max Rank- the userRank1 and number of players- numplayers2.
	MatchGame game1(userRank2, numplayers2);
	game1.play();//calls the play method of object game1.

}
	
	
	