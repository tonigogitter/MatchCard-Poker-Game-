#pragma once
#define DEFAULT_STACK 20
#include "List.h"
//Stack is used for the face up pile, as it keeps adding items to the top. Last in First out (LIFO) works for the face up pile.
template <class Item>
class Stack {
public:
	Stack(unsigned capacity = DEFAULT_STACK);
	// construct a stack with initial capacity of capacity; if the user does not provide a value, the default size is used
	~Stack(); // destructor
	bool isEmpty() const; // returns true if stack is empty, and false otherwise
	bool isFull() const;
	// returns true if stack is full, and false otherwise
	unsigned size() const;
	// returns number of elements currently in the stack
	void push(Item k);
	// put k on top of the stack
	Item pop();
	// Remove and return the top element from the stack;
	// PRECONDITION: the stack must not be empty


	Item peek() const;
	// return the top element without modifying the stack;
	// PRECONDITION: the stack must not be empty
private:
	// only differences between this file and Stack.h from first one
	// are in this part: m_container is now a list;
	// m_top and m_max_capacity are no longer needed
	List<Item> m_container;
};

template <class Item>
Stack<Item> ::Stack(unsigned capacity)
	: m_container(capacity) { }

template <class Item>
Stack<Item> :: ~Stack() { } // nothing to do here

template <class Item>
bool Stack<Item> ::isEmpty() const {
	return m_container.isEmpty();
}

template <class Item>
bool Stack<Item> ::isFull() const {
	return m_container.isFull();
}

template <class Item>
unsigned Stack<Item> ::size() const {
	return m_container.getLength();
}

template <class Item>
void Stack<Item> ::push(Item k) {
	m_container.insert(size() + 1, k);
}
template <class Item>
Item Stack<Item> ::pop() {
	if (m_container.isEmpty() == 0)
		return m_container.remove(size());
}
template <class Item>
Item Stack<Item> ::peek() const {
	if (m_container.isEmpty() == 0)
		return m_container.retrieve(size());
}