#include "MatchGame.h"	

using namespace std;

//constructor that takes the number of players and max rank
MatchGame::MatchGame(int num, int max) {
	numPlayers = num;
	maxRank = max;
	decksize = max * 4; //4 suits are multiplied by the maxrank
	startingArray = new MatchCard[decksize]; //new arrays
	shuffledArray = new MatchCard[decksize];
	players = new MatchPlayer[num]; //creates the players already here when the array is created

}

//destructor
MatchGame::~MatchGame() {

}

//creates a ordered deck of cards in startingArray
void MatchGame::createCards() {
	int x = 0;
	//generates a total of 4 * maxrank cards with the use of a nestled for loop
	for (int i = 0; i < 4; i++) {
		for (int j = 0; j < maxRank; j++) {
			startingArray[x] = MatchCard(static_cast<Suit>(i+1),static_cast<Rank>(j+1)); //casts int to enum types  
				x++;                                                                     //with + 1 since the enums start at 1 for ease of understanding
		}
	}
}

void MatchGame::shuffleDeck() {
	srand(time(NULL));  //  using the time seed from srand explanation 
	int i = 0;
	int nextplace = 0;
	int *checker = new int[decksize]; //checker array to hold all the already generated random values so they are not repeated
	
	while(i!=decksize) {
		int x = rand() % (decksize); // a random number is generated from zero to the decksize, which will represent the index in the startingArray that a card will be taken from 
		bool dblcheck = false; //double check function
		for (int j = 0; j < i; j++) { //checks to see if there are repeated random numbers
			if (x == checker[j]) {
				dblcheck = true;//doublecheck is changed to true as it found a match for the random number 
				break; //breaks once a match is found
			}
		}
		if (dblcheck) { // if true then will go back to the begining of the while loop to generate a new random number
			continue;
		}
			checker[nextplace] = x; //stores this random number in the checker array
			nextplace++; //increments to the next index
			shuffledArray[i] = startingArray[x]; //the shuffled array stores in order of increasing indexes of the chosen card at the staringArray index
			i++;
			}
		}

//fills the deck of the shuffledArray from i = 0, as the cards in it are already in random order
void MatchGame::fillDeck() {
	for (int i = 0; i < decksize; i++) {
		deck.enQueue(shuffledArray[i]); //use the enqueue method to keep adding to the "bottom" of the deck
	}
}

//method returns just draws cards by using the dequeue method to remove cards from the top of deck
MatchCard MatchGame::drawingCards() {
	return deck.deQueue();
}

//puts a card either from the deck at the start, or from a players hand, to the face up pile so that the last card added is the one most accessible
void MatchGame::drawFaceUpCard(MatchCard card) {
	faceup.push(card); //uses the push method to add a card
}

//just returns the values of the card without removing it
MatchCard MatchGame::seeFaceUp() {
	return faceup.peek();
}

//method used to reshuffle the cards in the face up pile (except the top card) back into the deck when the deck is empty
void MatchGame::reshuffle() {
	MatchCard tempcard = faceup.pop();//the top card of the faceup pile is saved to a temporary card

	//loops through the starting array overrwriting the cards in the starting array with that of the faceup pile, until the faceup pile is all reinserted
	for (int i = 0; i < faceup.size(); i++) {
		startingArray[i] = faceup.pop();
	}
	shuffleDeck(); //the shuffle method is ran again
	fillDeck(); //fills the deck again
	faceup.push(tempcard); //the temp card is placed back onto the top of the face up pile for players to continue to match to
}

//method that runs the players playing
void MatchGame::play() {
	//sets a variable to keep playing to true
	bool keepPlaying = true;
	//goes through each player and gives them the default 6 cards each
	for (int i = 0; i < numPlayers; i++) {
		for (int j = 0; j < 6; j++) {
			players[i].drawCard(drawingCards());
		}
	}

	drawFaceUpCard(drawingCards()); // draws the starting face up card
	cout << "START!" << endl;
	cout << "The Starting faceup card is the " << seeFaceUp() << endl; //shows which card is trying to be matched
	cout << endl;

	//loops while no one won yet
	while (keepPlaying) {

		//for loop here loops through each player
		for (int i = 0; i < numPlayers; i++)
		{
			//checks before each players turn if the deck is empty and runs the reshuffle method
			if (deck.isEmpty()) {
				cout << "RESHUFFLING!!!!!" << endl;
				cout << "RESHUFFLING!!!!!" << endl;
				cout << "RESHUFFLING!!!!!" << endl;
				cout << "RESHUFFLING!!!!!" << endl;
				reshuffle();
			}

			// updates the situation in the game
			cout << "The faceup card is the " << seeFaceUp() << endl;
			cout << endl;
			cout << "It's " << players[i].getPlayerName() << "'s Turn" << endl;

			//displays the player objects and their hand
			cout << players[i];

			//if the find a match they play the card from their hand to the faceup pile
			if (players[i].cardMatch(seeFaceUp())) {
				cout << players[i].getPlayerName() << " found a Match! They played a " << players[i].showplayCard(seeFaceUp()) << endl;
				cout << endl;
				drawFaceUpCard((players[i].playCard(seeFaceUp())));//faceup pile adds the card played from their hand
			}
			//if they don't find a match then they draw a card from the deck
			else {
				players[i].drawCard(drawingCards()); //draws the card that the deck dequeues
				cout << players[i].getPlayerName() << " did not find a Match. They drew a card" << endl;
				cout << endl;
			}
			
			//yells last card when they play their second last card
			if (players[i].gethandSize() == 1) {
				cout << players[i].getPlayerName() << " yells LAST CARD" << endl;
			}			
			
			//checks if a player's hand size is zero so that they win the game at the end of the turn so they win by the end of their turn
			if (players[i].gethandSize() == 0) {
				cout << players[i].getPlayerName() << " WINS and has crushed their enemies in MATCH (not even close)" << endl;
				keepPlaying = false;
				break;
			}
		}
	}
}