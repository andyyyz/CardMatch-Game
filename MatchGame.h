#pragma once
#include "MatchPlayer.h"
#include "Stack.h"
#include "Queue.h"
#include <ctime>

using namespace std;

class MatchPlayer; //forward declaration so that the array can use player objects to fill it

class MatchGame {
private:
	int numPlayers;
	int maxRank;
	int decksize;
	Stack<MatchCard> faceup; //faceup is a stack so that the card that is added last is the one that is the most easilt accessed
	Queue<MatchCard> deck; //deck is drawn in order so the queue is a good choice for type
	MatchCard* startingArray;//the dynamic array for all the existing cards in order
	MatchCard* shuffledArray; //the dynamic array that holds the same cards as startingArray, but randomly shuffled
	MatchPlayer* players; //a dynamic array that holds a user determined number of players

public:
	MatchGame(int numPlayer, int maxRank); //constructor takes user inputs number of players and maxrank

	~MatchGame(); // destructor

	void play(); // the play method that will contain the majority of the simulation

	void createCards(); //creates the cards based on max rank

	void shuffleDeck(); //shuffles the ordered cards randomly 

	void fillDeck(); //fills the actual deck of type queue with the shuffledcards

	void reshuffle();//the reshuffle method shuffles the faceup pile of cards (except the current faceup card) back into the deck

	MatchCard drawingCards(); //initial draw method for all the players at the beginning of the game

	void drawFaceUpCard(MatchCard card); //initial starting card in the stack (faceup pile) is drawn

	MatchCard seeFaceUp(); //sees which card is on the top of the faceup pile
};