#include <iostream>
#include "MatchPlayer.h"
#include "MatchCard.h"
#include "MatchGame.h"
#include <string>

using namespace std;

int MatchPlayer::playerNum = 1; //player's name number starts at 1

MatchPlayer::MatchPlayer() {
	thisplayername = "Player " + to_string(playerNum); //this is what playername form is
	playerNum++; //once a player is created the shared variable increased by one
}

MatchPlayer::~MatchPlayer() {
}

string MatchPlayer::getPlayerName() const{
	return thisplayername; //getter for player name
}

bool MatchPlayer::cardMatch(MatchCard card) {
	return (hand.find(card) != -1); //return a boolean if it has found a matching card
}

void MatchPlayer::drawCard(MatchCard card) {
	hand.insert(card); //inserts a card object into the hand
}

//returns the card that the player plays from their hand
//the parameter it takes is the card the player is trying to find a "match" of in their hand
MatchCard MatchPlayer::playCard(MatchCard card) {
	if (cardMatch(card)) {
		return hand.remove(hand.find(card));
	}
}

//this returns the played card but does not remove it from the hand for reference only
MatchCard MatchPlayer::showplayCard(MatchCard card) {
	if (cardMatch(card)) {
		return hand.retrieve(hand.find(card));
	}
}

//gives all classes the access to the hand size
int MatchPlayer::gethandSize() {
	return hand.getLength();
}

//overrides the << operator to output players 
ostream& operator<<(ostream& os, const MatchPlayer& p) {
	os << p.getPlayerName() << " has a hand of " << endl;
	for (int i = 1; i <= p.hand.getLength(); i++) { //ORDEREDLIST STARTS AT 1
		os << p.hand.retrieve(i) << endl; //retrieves the cards so nothing is changed in the actual hand
	}
	os << endl;
	return os;

}

