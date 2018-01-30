#pragma once
#include <iostream>

using namespace std;

enum Rank { Ace = 1, Two = 2, Three = 3, Four = 4, Five = 5, Six = 6, Seven = 7, Eight = 8, Nine = 9, Ten = 10};
	enum Suit { Spades = 1, Hearts = 2, Clubs = 3, Diamonds = 4 };

class MatchCard {
private:
	Rank rank; //the private variables and methods
	Suit suit;
	friend ostream& operator<<(ostream& os, const MatchCard& c);

public:
	MatchCard(); //default constructor
	MatchCard(Suit suit, Rank rank); //constructor to take suit and rank
	Rank getRank() const; //getter and setters
	Suit getSuit() const;
	~MatchCard(); //destructor
};

//overrides the normal < , > and == operators to work when comparing card objects
inline bool operator<(const MatchCard& a, const MatchCard& b) { 
	if (a.getSuit() == b.getSuit()) {
		return (a.getRank() < b.getRank()); //if the suits are the same the ranks are then compared
	}
	else {
		return (a.getSuit() < b.getSuit()); 
	}
};

inline bool operator>(const MatchCard& a, const MatchCard& b) {
	if (a.getSuit() == b.getSuit()) {
		return (a.getRank() > b.getRank());
	}
	else {
		return (a.getSuit() > b.getSuit());
	}
};

//checks if the two cards are equal!
//if they have the same suit OR same rank, its a match
inline bool operator==(MatchCard& a, MatchCard& b) {
	return (a.getRank() == b.getRank() || a.getSuit() == b.getSuit()); //in our case of the game of MATCH, a match is defined when EITHER 
};                                                                     //the SUIT or RANK is the same

