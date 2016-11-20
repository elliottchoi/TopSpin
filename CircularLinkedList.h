#include <iostream>
#pragma once
template <class T>

class CircularDoublyLinkedList
{
	private: 
	//Node Class with Next and Previous Pointer
	class Node{
	public:
		//Node Constructor 
		Node(T val, Node* nx = NULL, Node* prv = NULL) :Value(val), next(nx), previous(prv)
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
		T Value;
		Node*next;
		Node*previous;
	};

	//private member variables
	private:
		Node* m_head;
		Node* m_tail;
		int m_size; 

	public:
		//Construct empty Circular Doubly Linked List
		CircularDoublyLinkedList();
		//Destroy a Circular Doubly Linked List 
		~CircularDoublyLinkedList();
		//Add Item to Front of List
		void addItem(T val);
		//get the head of the linkedList
		Node*getHead()const { return m_head; }
		void move_head(bool directionShift);

		//Iterator Class
public:
	class Iterator {// iterators are used for efficient traversal of linked lists
	private:
		Node* m_ptr;    // an iterator hides a pointer to node
	public:
		Iterator(Node* ptr) { m_ptr = ptr; }
		void operator++ () { m_ptr = m_ptr->next; } // for forward traversing, e,g, Iterator i=begin(); ... ++i;
		void operator--() { m_ptr = m_ptr->previous; }
		bool operator != (const Iterator& b) { return m_ptr != b.m_ptr; }
		int operator *() { return m_ptr->Value; }
		T getValue() { return m_ptr->Value; }
		void setValue(int val) { m_ptr->Value = val; }
	};
	// linked list objects create forward-traversal iterators using the two functions below
	Iterator begin() const { return Iterator(m_head); }
	Iterator end() const { return Iterator(m_tail); }
};

//Construct Circular Doubly Linked List
template <class T>
CircularDoublyLinkedList<T>::CircularDoublyLinkedList():
	m_head(NULL),
	m_tail(NULL),
	m_size(0)
	{}

//Destructor
template <class T>
CircularDoublyLinkedList<T>::~CircularDoublyLinkedList()
{
	Node *temp = m_head;
	Node **nextNode;
	//Iterates while there are still nodes left
	for (int x = 0; x > this->m_size; x++)
	{
		nextNode = temp->next;
		delete temp;
		temp = nextNode;
	}
}

//Adding item to tail
template <class T>
void CircularDoublyLinkedList<T>::addItem(T val)
{
	//Empty List, adding first node
	if (m_size == 0)
	{
		m_head = m_tail = new Node(val, NULL, NULL);
	}
	else
	{
		m_tail = new Node(val, m_tail, m_head);
	}
	m_size++;
}

//Allowing the shift of list
template <class T>
void CircularDoublyLinkedList<T>::move_head(bool shiftDirection)
{
	//Shifting Right
	if (shiftDirection)
	{
		m_head = m_head->next;
		m_tail = m_tail->next;
	}
	//Shifting Left
	else
	{
		m_head = m_head->previous;
		m_tail = m_tail->previous; 
	}
}

