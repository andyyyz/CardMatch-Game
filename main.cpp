#include "MatchGame.h"
#include <iostream>

using namespace std;

int main() {
	//user input variables
	int userInputPlayers;
	int userInputMax;
	bool loop = true;
	//loops while true
	cout << "Welcome to MATCH" << endl;

	while (loop)
	{
		cout << "How many players would you like in the game? ";
		cin >> userInputPlayers; //user input
		cout << endl;
		cout << "What is the max rank you would like in the game?";
		cin >> userInputMax; //user input
		cout << endl;
		// -1 because you need a face up card to start too!
		if ((userInputMax * 4 - 1) < (userInputPlayers * 6)) {
			//message to tell how the user to fix the issue of too many players per deck and loops while still invalid
			cout << "INVALID INPUTS! HINT: Try a bigger difference between the number of players and max rank!" << endl;
		}
		else {
			loop = false; // if the values are fine, it doesn't loop anymore
		}
	}
	//creates a game with user inputs
	MatchGame game(userInputPlayers, userInputMax);
	//creates the starting deck with the methods below
	game.createCards();

	game.shuffleDeck();

	game.fillDeck();
	//initiates the play method
	game.play();

	return 0;
}