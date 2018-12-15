// Carter Mooring & Jerry Xue
// Date: December 3rd, 2018
// File: queue.cpp
// Gonzaga University, CPSC 122, Dr. Yerion

#include "queue.h"
#include <iostream>

using namespace std;

struct Node
{
	ItemType item;
	Node* next;
};

// outputs a queue to a file or the screen
// pre  : rhsq exists. output is open.
// post : contents of rhsq have been output
// usage: cout << rhsq << endl;
ostream& operator<< (ostream& output, const Queue& rhsq)
{
	Node* currentptr;

	if (not rhsq.isEmpty())
	{
		output << "front -> ";
		currentptr = rhsq.backptr -> next; // starts at front
		while (currentptr != rhsq.backptr)
		{
			output << currentptr -> item << ", ";
			currentptr = currentptr -> next;
		}
		output << currentptr -> item << " <- back" << endl;
	} else {
		output << "the queue is empty" << endl;
	}
	return output;
}

// creates an empty queue
// post : an empty queue
// usage: Queue q;
Queue::Queue()
{
	backptr = nullptr;
}

// copies an existing queue
// pre  : rhsq exists
// post : queue object is a copy of rhsq
// usage: Queue q(anotherq); or passing a Que object by value
Queue::Queue(const Queue& rhsq)
{
	Node* currentptr;
	bool isNotFull;

	currentptr = rhsq.backptr -> next; // starts at front
	while (currentptr != rhsq.backptr)
	{
		lineUp(currentptr -> item, isNotFull);
		currentptr = currentptr -> next;
	}
	lineUp(currentptr -> item, isNotFull);
}

// destroys a queue
// pre  : queue object exists
// post : queue object does not exist
// usage: automatically done at the end of scope
Queue::~Queue()
{
	bool isNotEmpty;
	while (not isEmpty())
	{
		getServed(isNotEmpty);
	}
}

// finds the size of a queue object
// pre  : queue object exists
// post : returns the size of the queue object
// usage: cout << q.getSize();
int Queue::getSize() const
{
	int size = 0;
	Node* currentptr;

	if(backptr == nullptr) {
		return size;
	}
	else {
		currentptr = backptr;
		size++;
		while(currentptr -> next != backptr) {
			currentptr = currentptr -> next;
			size++;
		}
	}
	return size;
}

// checks to see if a queue object is empty
// pre  : queue object exists
// post : if queue is empty returns true else returns false
// usage: if (q.isEmpty())
bool Queue::isEmpty() const
{
	return (backptr == nullptr);
}

// inserts a new item at the rear of the queue
// pre  : newItem has an assigned value; queue exists
// post : if queue object is not full, newItem is added
// at the rear of the queue and isNotFull is true else isNotFull is false
// usage: myq.lineUp(hunter, isNotFull);
void Queue::lineUp(ItemType newItem, bool& isNotFull)
{
	Node* newptr;

	if (isEmpty())
	{
		backptr = new Node;
		if (backptr != nullptr)
		{
			backptr -> item = newItem;
			backptr -> next = backptr;
			isNotFull = true;
		} else {
			isNotFull = false;
		}
	} else {
		newptr = new Node;
		if (newptr != nullptr)
		{
			newptr -> item = newItem;
			newptr -> next = backptr -> next;
			backptr -> next = newptr;
			backptr = newptr;
			isNotFull = true;
		} else {
			isNotFull = false;
		}
	}
}

// deletes item from the front of the queue after copying it
// pre  : queue exists
// post : if queue is nonempty, front of queue has been removed
// and isNotEmpty is true else isNotEmpty is false
// usage:
void Queue::getServed(bool& isNotEmpty)
{
	Node* currentptr;
	if(not isEmpty() and backptr == backptr -> next)
	{
		delete backptr -> next;
		backptr = nullptr;
		isNotEmpty = false;
	} else if (not isEmpty()) {
		currentptr = new Node;
		currentptr = backptr -> next -> next;
		delete backptr -> next;
		backptr -> next = currentptr;
		isNotEmpty = true;
	}
}

// copies the front item
// pre  : queue exists and is not empty
// post : returns the front item in the queue
ItemType Queue::getWhoIsServed() const
{
	return backptr -> next -> item;
}

// copies the queue
// pre  : rhsq exists. queue object exists but may be empty
// post : queue object is a copy of rhsq
// usage: copyq.operator=(rhsq);
// or        copyq = rhsq;
Queue& Queue::operator=(const Queue& rhsq)
{
	// copying rhsq into data object
	Node* currentptr;
	bool isNotFull;
	if (this != &rhsq)
	{
		while (not isEmpty())
		getServed(isNotFull);
		if (not rhsq.isEmpty())
		{
			currentptr = rhsq.backptr -> next; // starts at front
			while (currentptr != rhsq.backptr)
			{
				lineUp(currentptr -> item, isNotFull);
				currentptr = currentptr -> next;
			}
			lineUp(currentptr -> item, isNotFull);
		}
	}
	return *this; // to allow cascading ='s (perkins = spike = rui)'
}
