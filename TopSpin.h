#pragma once
#include "CircularDoublyLinkedList.h"
#include <iostream>
using namespace std;

//Abstract Class
class TopSpinADT {
public:
	virtual void shiftLeft() = 0;
	virtual void shiftRight() = 0;
	virtual void spin() = 0;
	virtual bool isSolved() = 0;
};

class TopSpin:public TopSpinADT
{
private:
	//Node Class
	class Node {
	public:
		//Node Constructor 
		Node(int val, Node* nx = NULL, Node* prv = NULL) :Value(val), next(nx), previous(prv)
		{
			if (previous)
			{
				previous->next = this;
			}
			if (next)
			{
				next->previous = this;
			}
		}
		int Value;
		Node*next;
		Node*previous;
	};
public:
	//Top spin member variables
	int gameSize = 0;
	int mechanismSpinSize = 0;
	Node  *mechanismStart = 0;
	CircularDoublyLinkedList<int>board; 
	//Top Spin Functions
	TopSpin(int size, int spinSize);
	int getSize();


//Iterator Class
public:
	class Iterator {// iterators are used for efficient traversal of linked lists
	private:
		Node* m_ptr;    // an iterator hides a pointer to node
	public:
		Iterator(Node* ptr) { m_ptr = ptr; }
		void operator++ () { m_ptr = m_ptr->next; } // for forward traversing, e,g, Iterator i=begin(); ... ++i;
		bool operator != (const Iterator& b) { return m_ptr != b.m_ptr; }
		int operator *() { return m_ptr->Value; }
		int getValue() { return m_ptr->Value; }
		void setValue(int val) { m_ptr->Value = val; }
	};

	// linked list objects create forward-traversal iterators using the two functions below
	Iterator begin() { return Iterator(mechanismStart); }
	Iterator end() { return Iterator(nullptr); }
};


