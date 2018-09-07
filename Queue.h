#pragma once

const int DEFAULT_SIZE = 10;
//Queue is used in MatchGame as the deckpile as it utilizes a FIFO (first in, first out policy) which makes sense for the deck pile.
template <class T>
class Queue {
public:
	Queue(unsigned int capacity = DEFAULT_SIZE);
	// constructor for queue that can hold capacity elements
	~Queue(); // destructor
	bool isEmpty() const;
	// returns true if queue is empty, false otherwise
	bool isFull() const;
	// returns true if the queue is full, and false otherwise
	void enqueue(T k);
	// adds k to end of the queue;
	// precondition: queue must not be full
	T dequeue();
	// removes the front item from the queue, and returns it;
	// precondition: queue must not be empty already
	T peek() const;
	// retrieves front item from the queue, and returns it;
	// precondition: queue must not be empty already
private:
	int m_front; // index of front queue element
	int m_size; // number of items currently in queue
	int m_capacity; // upper capacity of queue
	T * m_container; // storage for queue items
};



template <class T>
Queue<T> ::Queue(unsigned int capacity) {
	m_size = 0; m_front = 0;
	m_capacity = capacity;
	m_container = new T[capacity];
}
template <class T>
Queue<T> :: ~Queue() {
	delete[] m_container;
}


template <class T>
bool Queue<T> ::isEmpty() const {
	if (m_size == 0)
		return true;
	else
		return false;
}
template <class T>
bool Queue<T> ::isFull() const {
	if (m_size == m_capacity)
		return true;

	else 
	return false ;
}

template <class T>
void Queue<T> ::enqueue(T k) {
	// precondition: queue must not be full
	if (isFull() == false) {
		m_container[(m_front + m_size) % m_capacity] = k;
		m_size++;
	}
}

template <class T>
T Queue<T> ::dequeue() {
	// precondition: queue must not be empty already
	if (!(m_size==0)) {
		T item = m_container[m_front];
		m_front = (m_front + 1) % m_capacity;
		m_size--;
		return item;
	}
	
}

template <class T>
T Queue<T> ::peek() const {
	// precondition: queue must not be empty already
	if (!(m_size==0)) {
		return m_container[m_front];
	}
}
