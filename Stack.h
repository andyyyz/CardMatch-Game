#pragma once
#include "List.h"
template<class Item> class Stack {
private:
	List<Item>m_container;

public:
	Stack(unsigned int capacity = DEFAULT_LIST);

	~Stack();

	bool isEmpty() const;

	bool isFull() const;

	unsigned size() const;

	void push(Item card);

	Item pop();

	Item peek()const;	
	
};

template<class Item>
Stack<Item>::Stack(unsigned int capacity = DEFAULT_LIST) : m_container(capacity) {};

template <class Item>
Stack<Item>::~Stack() {};

template<class Item>
unsigned Stack<Item>::size() const {
	return m_container.getLength();
};

template<class Item>
bool Stack<Item>::isEmpty() const {
	return m_container.isEmpty();
};

template<class Item>
bool Stack<Item>::isFull() const {
	return m_container.isFull();
};

template<class Item>
void Stack<Item>::push(Item card) {
	return m_container.insert(size() + 1, card); //the initial size is 0 so we gotta plus one it
};

template<class Item>
Item Stack<Item>::pop() {
	return m_container.remove(size());
};

template<class Item>
Item Stack<Item>::peek() const {
	return m_container.retrieve(size());		
};


