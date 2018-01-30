#pragma once
#include "List.h"
#include "StandardFunctors.h"
#include "MatchCard.h"

template<class Item, class Order = IsLess> 
class OrderedList {
private:
	List<Item> m_container;

public:

	OrderedList(unsigned int capacity = DEFAULT_LIST);

	~OrderedList();

	bool isEmpty() const;

	unsigned int getLength() const;

	Item retrieve(unsigned int position) const;

	Item remove(unsigned int position);

	int insert(Item card);

	int find(Item card) const;

	int binarySearch(Item card) const;
};

template <class Item, class Order>
OrderedList<Item, Order>::OrderedList(unsigned int capacity) : m_container(capacity) {} //a const has to be initialized before the constructor

template <class Item, class Order>
OrderedList<Item, Order>::~OrderedList() {}

template <class Item, class Order>
bool OrderedList<Item, Order>::isEmpty() const {
	return m_container.isEmpty();
}

template <class Item, class Order>
unsigned int OrderedList<Item, Order>::getLength() const {
	return m_container.getLength();
}

template <class Item, class Order>
Item OrderedList<Item, Order>::remove(unsigned int pos) {
	return m_container.remove(pos);
}

template <class Item, class Order>
Item OrderedList<Item, Order>::retrieve(unsigned int pos) const {
	return m_container.retrieve(pos);
}

template <class Item, class Order>
int OrderedList<Item, Order> ::insert(Item card) {
	unsigned int k;
	for (k = 1; k <= getLength(); k++)
		if (Order::compare(card, retrieve(k))) break;
	m_container.insert(k, card);
	return k;
}

template < class Item, class Order>
int OrderedList<Item, Order> ::binarySearch(Item card) const {
	int first = 1, last = m_container.getLength();
	while (first <= last) {
		int mid = first + (last - first) / 2;
		Item val = retrieve(mid);
		if (Order::compare(card, val)) {
			last = mid - 1;
		}
		else if (Order::compare(card, val)) {
			first = mid + 1;
		}
		else {
			return mid;
		}
	}
	return -1;
}

template <class Item, class Order>
int OrderedList<Item,Order>::find(Item card) const {
	int k;
	for (k = 1; k <= getLength(); k++)
	{
		if (card == retrieve(k)) {
			return k;
		}
	}
	return -1;
}