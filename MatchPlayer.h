#pragma once
#include <iostream>
#include <String>
#include "OrderedList.h"
#include "MatchGame.h"
#include "MatchCard.h"
#include "StandardFunctors.h"

using namespace std;

class MatchPlayer {
private:
	static int playerNum; //the number of players is shared throughout all player objects
	string thisplayername;//the player name 
	OrderedList<MatchCard,IsLess> hand; //their hand has default order from greatest to least of cards
	
public:
	
	MatchPlayer(); //default constructor

	~MatchPlayer(); //destructor

	string getPlayerName() const; //gets the player name

	bool cardMatch(MatchCard card); //checks if two cards match

	void drawCard(MatchCard card); //draw card into hand

	MatchCard playCard(MatchCard card); //plays card from hand

	MatchCard showplayCard(MatchCard card); //shows which card is played

	int gethandSize(); //gets the size of the hand

	friend ostream& operator<<(ostream& os, const MatchPlayer& p); //overloads the cout << operator with players

};
