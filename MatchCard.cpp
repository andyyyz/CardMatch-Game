#include "MatchCard.h"
#include <iostream>

using namespace std;

//default constructor
MatchCard::MatchCard() {
	
}

//constructor sets the suit and rank variables
MatchCard::MatchCard(Suit s, Rank r){
	suit = s;
	rank = r;
}

//destructor
MatchCard::~MatchCard() {

}

//getter
Rank MatchCard::getRank() const {
	return rank;
}
//setter
Suit MatchCard::getSuit() const {
	return suit;
}

//friend function that overrides the output << operator for cards
ostream& operator<<(ostream& os, const MatchCard &c) {
	int ranks = c.getRank();
	int suits = c.getSuit();

	if (ranks == 1) {
		os << "Ace"; //ace is called for 1 because of convention
	}
	else {
		os << ranks;
	}

	os << " of "; //convention

	//switch statement for the suits 
	switch (suits) {
	case 1:
		os << "Spades";
		break;
	case 2:
		os << "Hearts";
		break;
	case 3:
		os << "Clubs";
		break;
	default:
		os << "Diamonds";
		break;
}

	return os;
}

