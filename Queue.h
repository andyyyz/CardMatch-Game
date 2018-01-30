#pragma once
#include "LinkedList.h"
#include "MatchCard.h"
#include "MatchGame.h"
#include "MatchPlayer.h"

template<class Item> class Queue {
private:
	LinkedList<Item> m_container;

public:
	Queue();

	~Queue();

	bool isEmpty() const;

	bool isFull() const;

	void enQueue(Item card); //adds a card from the array of ordered Matchcards randomly to shuffle into the queue deck

	Item deQueue(); //retrieves the most front card

	Item peek() const;
};

template<class Item>
Queue<Item>::Queue() {}; //do i need to initialize the container here??

template <class Item>
Queue<Item>::~Queue() {};

template<class Item>
bool Queue<Item>::isEmpty() const {
	return m_container.isEmpty();
};

template<class Item>
bool Queue<Item>::isFull() const {
	return false;
};

template<class Item>
void Queue<Item>::enQueue(Item card) {
	return m_container.addTail(card);
};

template<class Item>
Item Queue<Item>::deQueue() {
	return m_container.removeHead(); //rememeber to check if the deck is empty or not in the main game!!
};

template<class Item>
Item Queue<Item>::peek() const {
	return m_container.retrieveHead();
};